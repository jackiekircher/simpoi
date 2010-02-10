#ifndef SIMPOI_WIDGET_H
#define SIMPOI_WIDGET_H

#include <QGLWidget>
#include "poi.h"

class SimpoiWidget : public QGLWidget
{
    Q_OBJECT

public:
    SimpoiWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void update();
    void poi1_speed_change(int value);
    void poi1_angle_change(int value);
    void path1_speed_change(int value);
    void path1_angle_change(int value);
    void poi1_clockwise();
    void poi1_cc();
    void path1_clockwise();
    void path1_cc();
    void path1_height_changed(const QString &str);
    void path1_width_changed(const QString &str);
    void path1_centerx_changed(const QString &str);
    void path1_centery_changed(const QString &str);

signals:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *e);

private:
    void draw_poi(poi_t poi);
    void draw_path(poi_t poi);

    position_t curr_pos;    // current position
    window_t window;        // the display window

    poi_t poi[2];           // the poi! see poi.c
};

#endif // SIMPOI_WIDGET_H
