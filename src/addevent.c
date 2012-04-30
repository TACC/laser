#include "taccreport.h"
#include <stdlib.h>

void addevent(report_type *report, event_type *event) {
  report->events = realloc(report->events, sizeof(event_type*)*(report->numevents+1));
  report->events[report->numevents++] = event;
}
