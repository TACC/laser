#include <stdlib.h>
#include <stdio.h>
#include "taccreport.h"

int main(int argc, char **argv) {

  char **authors = (char**)malloc(sizeof(char*)*3);
  authors[0] = "Lucas A. Wilson"; 
  authors[1] = "John Q. Public"; 
  authors[2] = "James T. Kirk";

  report_type *rpt = createReport("foo.tex", RPT_OUTPUT_TEX, NULL, "TACC In-Job Report Generation Library Test", 
                                  "I am testing the new TACC Report Generation Library, written by Luke Wilson(lwilson@tacc.utexas.edu) and Carlos Rosales(carlos@tacc.utexas.edu).", authors, 3);

  event_type *evt = createEvent("Basic Event", "This is a basic event", RPT_EVENT_BASIC, "This is an example basic event. Basic events are simply text blobs describing something of note.");

  event_type *evt2 = createEvent("Image Event", "This is an image event. Filename stored in data field.", RPT_EVENT_IMAGE, "repeats-surface.png");

  event_type *evt3 = createEvent("Table Event", "This is a table event. You can separate fields with a comma, rows with a semicolon, and bold elements with a leading asterisk.", RPT_EVENT_TABLE, "*Val1, Val2, Val3, Val4; Val5, *Val6, Val7, Val8; Val9, Val10, Val11 multi word, *Val12 multi word;");
 
  addEvent(rpt, evt);
  addEvent(rpt, evt2);
  addEvent(rpt, evt3);

  generateReport(rpt);
  return 0;
}
