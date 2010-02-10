#include <QtGui>
#include <QtOpenGL>

#include <math.h>

#include "simpoi_widget.h"
#include "poi.h"

SimpoiWidget::SimpoiWidget(QWidget *parent)
    : QGLWidget(parent)
{
    curr_pos.x = 300; curr_pos.y = 200;

    poi[0].size = 12;
    poi[0].radius = 100;
    poi[0].angle = PI;
    poi[0].speed = 4;
    poi[0].direction = -1;
    poi[0].path.height = 50;
    poi[0].path.width = 50;
    poi[0].path.angle = 0;
    poi[0].path.direction = -1;
    poi[0].path.speed = 4;
    poi[0].path.center.x = 400;
    poi[0].path.center.y = 300;
    poi[0].center.x = 400;
    poi[0].center.y = 300;
    poi[0].color[0] = 0.1;
    poi[0].color[1] = 1.0;
    poi[0].color[2] = 1.0;

    poi[1].size = 12;
    poi[1].radius = 100;
    poi[1].angle = PI;
    poi[1].speed = 4;
    poi[1].direction = 1;
    poi[1].path.height = 175;
    poi[1].path.width = 0;
    poi[1].path.angle = PI;
    poi[1].path.direction = -1;
    poi[1].path.speed = 4;
    poi[1].path.center.x = 400;
    poi[1].path.center.y = 300;
    poi[1].center.x = 400;
    poi[1].center.y = 300;
    poi[1].color[0] = 1.0;
    poi[1].color[1] = 0.1;
    poi[1].color[2] = 1.0;
  }


QSize SimpoiWidget::minimumSizeHint() const
{
    return QSize(800, 600);
}


QSize SimpoiWidget::sizeHint() const
{
    return QSize(800, 600);
}

/* here we go - each button that sends a signal needs its own slot, so
 * there are going to be A LOT of function here.  In fact, each one will
 * be doubled.  This could be solved by subclassing QSlider and creating
 * a unique signal that also sends the poi id, but I'll look into that
 * later */
void SimpoiWidget::poi1_speed_change(int value) { poi[0].speed = value; }
void SimpoiWidget::poi1_angle_change(int value) { poi[0].angle = value*PI/180; }
void SimpoiWidget::path1_speed_change(int value) { poi[0].path.speed = value; }
void SimpoiWidget::path1_angle_change(int value) { poi[0].path.angle = value*PI/180; }
void SimpoiWidget::poi1_clockwise() { poi[0].direction = 1; }
void SimpoiWidget::poi1_cc() { poi[0].direction = -1; }
void SimpoiWidget::path1_clockwise() { poi[0].path.direction = 1; }
void SimpoiWidget::path1_cc() { poi[0].path.direction = -1; }
void SimpoiWidget::path1_height_changed(const QString &str) { poi[0].path.height = str.toDouble(); }
void SimpoiWidget::path1_width_changed(const QString &str) { poi[0].path.width = str.toDouble(); }
void SimpoiWidget::path1_centerx_changed(const QString &str) { poi[0].path.center.x = str.toDouble(); }
void SimpoiWidget::path1_centery_changed(const QString &str) { poi[0].path.center.y = str.toDouble(); }


void SimpoiWidget::initializeGL() {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    glLineWidth (1.5);

    // specifies a background color: black in this case
    glClearColor(0,0,0,0) ;

    // setup for simple 2d projection
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();


    // map unit square to viewport window
    gluOrtho2D(0.0, 800, 0.0, 600);
}


void SimpoiWidget::paintGL() {
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT) ;

    glColor3f(1,0,0) ; // RGB

    int i;
    for(i=0; i<2; i++) {
        draw_path(poi[i]);  // draw paths first
    }
    for(i=0; i<2; i++) {
        draw_poi(poi[i]);
    }
}


void SimpoiWidget::resizeGL(int width, int height) {

}


void SimpoiWidget::mousePressEvent(QMouseEvent *event) {

}


void SimpoiWidget::mouseMoveEvent(QMouseEvent *event) {

}


void SimpoiWidget::keyPressEvent(QKeyEvent *e) {

}


 void SimpoiWidget::update() {
     for(int id=0; id<2; id++) {
        poi[id].angle += poi[id].speed*poi[id].direction*PI/180;
        if(poi[id].angle > 2*PI) poi[id].angle -= 2*PI;

        /*  path.speed is relative to rotation
         *  poi.speed/poi.path.speed = number of petals per rotation
         */
        poi[id].path.angle += poi[id].path.speed*poi[id].path.direction*PI/180;
        if(poi[id].path.angle > 2*PI) poi[id].path.angle -= 2*PI;

        /* change the center if poi is on a path */
        poi[id].center.x = poi[id].path.center.x +
                         poi[id].path.width*cos(poi[id].path.angle);
        poi[id].center.y = poi[id].path.center.y -
                         poi[id].path.height*sin(poi[id].path.angle);
    }

    updateGL();
 }

void SimpoiWidget::draw_poi(poi_t poi) {
  glBegin(GL_TRIANGLE_FAN);
  {
    position_t offset;
    offset.x = poi.radius*cos(poi.angle);
    offset.y = poi.radius*sin(poi.angle);

    glColor3f(poi.color[0],poi.color[1],poi.color[2]);

    /* first point is at the center to give the poi its 'tail' */
    glVertex2f(poi.center.x, poi.center.y );
    for(int angle=0; angle < 365; angle += 5) {
      glVertex2f(poi.center.x + cos(angle*PI/180)*poi.size + offset.x,
                 poi.center.y + sin(angle*PI/180)*poi.size - offset.y);
    }
  }
  glEnd();

  return;
}

void SimpoiWidget::draw_path(poi_t poi) {
  glBegin(GL_LINES);
  {
    /* make the paths a little darker */
    glColor3f(poi.color[0]-0.3,poi.color[1]-0.3,poi.color[2]-0.3);
    int angle;
    for(angle=0; angle < 360; angle++) {
      /* gradient from white to poi color for the path */
      /* maybe I'll try this again later
      glColor3f(1.0 - (1.0 - poi.color[0])*angle/360.0,
                1.0 - (1.0 - poi.color[1])*angle/360.0,
                1.0 - (1.0 - poi.color[2])*angle/360.0);
      */
      glVertex2f(poi.path.center.x + cos(angle*PI/180)*poi.path.width,
                 poi.path.center.y + sin(angle*PI/180)*poi.path.height);
      glVertex2f(poi.path.center.x + cos(angle*PI/180 + 0.1)*poi.path.width,
                 poi.path.center.y + sin(angle*PI/180 + 0.1)*poi.path.height);
    }
  }
  glEnd();

  return;
}

