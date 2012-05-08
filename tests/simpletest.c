#include <stdlib.h>
#include <stdio.h>
#include "laser.h"

double customreducer(double oldreduction, double newval, unsigned long count) {
  //Let's make an inverse sum
  if(newval==0.0) return oldreduction;

  return oldreduction + 1.0/newval;
}

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

  laser_reduction *rdc = createReduction(&customreducer);

  addEvent(rpt, evt);
  addEvent(rpt, evt2);
  addEvent(rpt, evt3);
  laser_event *evt4 = createReductionEvent(rdc, LASER_AGG_SUM, "Reduction Event", "This is a reduction event before the loop. It contains only a sum.");
  addEvent(rpt, evt4);
  int i;
  char description[128];
  for(i=1; i< 10000; i++) {
    reduce(rdc, (double)i);
    if(i % 1000 == 0) {
      sprintf(description, "This is a reduction event for loop iteration %d. It contains all of the available reductions.", i);
      evt4 = createReductionEvent(rdc, LASER_AGG_COUNT | LASER_AGG_SUM | LASER_AGG_MEAN | LASER_AGG_MIN | LASER_AGG_MAX | LASER_AGG_VAR | LASER_AGG_CUSTOM, "Reduction Event", description);
      addEvent(rpt, evt4);
    }
  }

  evt4 = createReductionEvent(rdc, LASER_AGG_CUSTOM, "Reduction Event", "This is a reduction event after the loop. It contains only the custom reduction.");
  addEvent(rpt, evt4);

  generateReport(rpt);
  return 0;
}
