#include "laser.h"
#include <stdlib.h>
#include <string.h>

void addEvent(report_type *report, event_type *event) {
  event_type **tmp = malloc(sizeof(event_type*)*(report->numevents+1));
  if(report->events != NULL) {
    memcpy(tmp, report->events, sizeof(event_type*)*report->numevents);
    free(report->events);
  }
  report->events = tmp;
    
  report->events[report->numevents++] = event;
}
