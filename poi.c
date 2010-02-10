#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include "poi.h"

void draw_poi(poi_t poi) {
  glBegin(GL_TRIANGLE_FAN);
  {
    position_t offset;
    offset.x = poi.radius*cos(poi.angle);
    offset.y = poi.radius*sin(poi.angle);

    glColor3f(poi.color[0],poi.color[1],poi.color[2]);

    /* first point is at the center to give the poi its 'tail' */
    glVertex2f(poi.center.x ,
               poi.center.y );
    int angle;
    for(angle=0; angle < 365; angle += 5) {
      glVertex2f(poi.center.x + cos(angle*PI/180)*poi.size + offset.x,
                 poi.center.y + sin(angle*PI/180)*poi.size - offset.y);
    }
  }
  glEnd();

  return;
}

void draw_path(poi_t poi) {
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

