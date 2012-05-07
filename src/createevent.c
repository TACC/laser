#include "laser.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

laser_event *createEvent(char *title, char *desc, short etype, char *data) {
  laser_event *evt = (laser_event*)malloc(sizeof(laser_event));

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
