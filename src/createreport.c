#include "taccreport.h"
#include <stdlib.h>
#include <string.h>

report_type *createreport(char *fname, short ftype, char *ftemplate, char *title, char *abstract, char **authors, int numauths) {
  report_type *rpt = (report_type*)malloc(sizeof(report_type));
  
  rpt->filename = (char*)malloc(sizeof(char)*(strlen(fname)+1));
  strcpy(rpt->filename, fname);

  rpt->filetype = ftype;

  rpt->filetplate = (char*)malloc(sizeof(char)*(strlen(ftemplate)+1));
  strcpy(rpt->filetplate, ftemplate);

  rpt->header.title = (char*)malloc(sizeof(char)*(strlen(title)+1));
  strcpy(rpt->header.title, title);

  rpt->header.abstract = (char*)malloc(sizeof(char)*(strlen(abstract)+1));
  strcpy(rpt->header.abstract, abstract);

  rpt->header.authors = (char**)malloc(sizeof(char*)*numauths);
  int i;
  for(i=0; i<numauths; i++) {
    rpt->header.authors[i] = (char*)malloc(sizeof(char)*(strlen(authors[i])+1));
    strcpy(rpt->header.authors[i], authors[i]);
  }
  rpt->header.numauths = numauths;

  rpt->events = NULL;
  rpt->numevents = 0;

  return rpt;
}