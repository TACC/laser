#include "laser.h"

laser_event *createReductionEvent(laser_reduction *reducer, char *title, char *desc) {
  char datastr[1024];

  

  return createEvent(title, desc, LASER_EVENT_TABLE, datastr);
}
