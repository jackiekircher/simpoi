#ifndef _POI_H
#define _POI_H

#define PI 3.14159265


typedef struct window {
  int width;
  int height;
  char title[32];
}window_t;

typedef struct position {
  double x;
  double y;
} position_t;

typedef struct poi {
  double color[3];      /* color of poi */
  double size;          /* radius of poi head */
  double radius;        /* length of poi from head to tail */
  double angle;         /* position in the circle around the hand */
  double speed;         /* speed of poi */
  int direction;        /* 1: clockwise, -1: counter-clockwise */
  position_t center;    /* location of 'hand' */

  struct {
    double height;      /* height of path */
    double width;       /* width of path */
    double angle;       /* position within the path ('circles' only) */
    double direction;   /* 1: clockwise, -1: counter-clockwise */
    double speed;       /* speed of path */
    position_t center;  /* center of path */
  }path;
}poi_t;


void draw_poi(poi_t poi);
void draw_path(poi_t poi);

#endif
