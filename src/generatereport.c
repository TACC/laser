#include "taccreport.h"
#include <stdlib.h>
#include <stdio.h>

void generateReport(report_type *report) {
  FILE *fp, *tp;
  fp = fopen(report->filename, "w");
  char line[1024];
  int i;

  if(fp) {
    if(report->filetplate) {
      //User-supplied LaTeX template
      tp = fopen(report->filetplate, "r");
    } else {
      //Default LaTeX template
      tp = fopen("default.tpl", "r");
    }



    switch (report->filetype) {
      case RPT_OUTPUT_TXT: //Output a plain text file
        
        break;
      case RPT_OUTPUT_TEX: //Output a LaTeX file or generated PDF
      case RPT_OUTPUT_PDF:
        //Print the LaTex documentclass header
        fprintf(fp, "\\documentclass{article}\n\\usepackage{authblk}\n");
        
        //Generate the title and the authorlist
        fprintf(fp, "\\title{%s}\n", report->header.title);
        for(i=0; i<report->header.numauths; i++)
          fprintf(fp, "\\author{%s}\n", report->header.authors[i]);
        
        //Begin the document, write the title and authorlist
        fprintf(fp, "\\begin{document}\n\\maketitle\n");

        //Write the abstract
        fprintf(fp, "\\begin{abstract}\n%s\n\\end{abstract}\n", report->header.abstract);

        //Write the submission characteristics section
        fprintf(fp, "\\section{Job Information}\n");
        fprintf(fp, "JobID: %ld\n\n", report->header.jobID);
        fprintf(fp, "Call-line: %s\n\n", report->header.invocation);
        fprintf(fp, "Num Procs: %d\n\n", report->header.NP);
        fprintf(fp, "Walltime: %ld seconds\n\n", report->header.walltime);

        //End the document
        fprintf(fp, "\\end{document}");
        break;
    };
  }
  fclose(tp);
  fclose(fp);

  //Clean up report memory
}
