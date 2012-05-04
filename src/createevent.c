#include "taccreport.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

event_type *createEvent(char *title, char *desc, short etype, char *data) {
  event_type *evt = (event_type*)malloc(sizeof(event_type));

  evt->title = (char*)malloc(strlen(title)+1);
  strcpy(evt->title, title);

  evt->desc = (char*)malloc(strlen(desc)+1);
  strcpy(evt->desc, desc);

  evt->generated = time(0);

  evt->eventtype = etype;

  evt->data = (char*)malloc(strlen(data)+1);
  strcpy(evt->data, data);

  return evt;
}
