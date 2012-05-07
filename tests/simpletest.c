#include <stdlib.h>
#include <stdio.h>
#include "laser.h"

int main(int argc, char **argv) {

  char **authors = (char**)malloc(sizeof(char*)*3);
  authors[0] = "Lucas A. Wilson"; 
  authors[1] = "John Q. Public"; 
  authors[2] = "James T. Kirk";

  laser_report *rpt = createReport("foo.tex", LASER_OUTPUT_TEX, NULL, "LASER: Library for Automated Simulation Event Reporting", 
                                  "I am testing LASER, written by Luke Wilson(lwilson@tacc.utexas.edu) and Carlos Rosales(carlos@tacc.utexas.edu).", authors, 3);

  laser_event *evt = createEvent("Basic Event", "This is a basic event", LASER_EVENT_BASIC, "This is an example basic event. Basic events are simply text blobs describing something of note.");

  laser_event *evt2 = createEvent("Image Event", "This is an image event. Filename stored in data field.", LASER_EVENT_IMAGE, "repeats-surface.png");

  laser_event *evt3 = createEvent("Table Event", "This is a table event. You can separate fields with a comma, rows with a semicolon, and bold elements with a leading asterisk.", LASER_EVENT_TABLE, "*Val1, Val2, Val3, Val4; Val5, *Val6, Val7, Val8; Val9, Val10, Val11 multi word, *Val12 multi word;");
 
  addEvent(rpt, evt);
  addEvent(rpt, evt2);
  addEvent(rpt, evt3);

  generateReport(rpt);
  return 0;
}
