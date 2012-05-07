#include "laser.h"

laser_event *createAggregateEvent(laser_aggregate *aggregator, char *title, char *desc) {
  char datastr[1024];

  

  return createEvent(title, desc, LASER_EVENT_TABLE, datastr);
}
