#include "laser.h"
#include <stdlib.h>
#include <string.h>

void addEvent(laser_report *report, laser_event *event) {
  laser_event **tmp = malloc(sizeof(laser_event*)*(report->numevents+1));
  if(report->events != NULL) {
    memcpy(tmp, report->events, sizeof(laser_event*)*report->numevents);
    free(report->events);
  }
  report->events = tmp;
    
  report->events[report->numevents++] = event;
}
