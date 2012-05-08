#include "laser.h"
#include <stdio.h>

laser_event *createReductionEvent(laser_reduction *reducer, short options, char *title, char *desc) {
  char datastr[1024] = "";

  if(options & LASER_AGG_COUNT) sprintf(datastr, "*Count, %ld;", reducer->count);
  if(options & LASER_AGG_SUM) sprintf(datastr, "%s *Sum, %lf;", datastr, reducer->values[0]);
  if(options & LASER_AGG_MEAN) sprintf(datastr, "%s *Mean, %lf;", datastr, reducer->values[1]);
  if(options & LASER_AGG_MIN) sprintf(datastr, "%s *Min, %lf;", datastr, reducer->values[2]);
  if(options & LASER_AGG_MAX) sprintf(datastr, "%s *Max, %lf;", datastr, reducer->values[3]);
  if(options & LASER_AGG_VAR) sprintf(datastr, "%s *Variance, %lf;", datastr, reducer->values[4]);
  if(options & LASER_AGG_CUSTOM) sprintf(datastr, "%s *Custom, %lf;", datastr, reducer->values[5]);

  return createEvent(title, desc, LASER_EVENT_TABLE, datastr);
}
