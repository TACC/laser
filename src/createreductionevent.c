#include "laser.h"
#include <stdio.h>

laser_event *createReductionEvent(laser_reduction *reducer, char *title, char *desc) {
  char datastr[1024];

  sprintf(datastr, "*Count, %ld; *Sum, %lf; *Mean, %lf; *Min, %lf; *Max, %lf; *Variance, %lf; *Custom, %lf;", reducer->count,
          reducer->values[0], reducer->values[1], reducer->values[2], reducer->values[3], reducer->values[4], reducer->values[5]);  

  return createEvent(title, desc, LASER_EVENT_TABLE, datastr);
}
