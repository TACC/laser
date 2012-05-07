#include "laser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void generateReport(laser_report *report) {
  FILE *fp, *tp;
  fp = fopen(report->filename, "w");
  char line[1024];
  int i, j, cols, inbold;
  char buf[128];

  if(fp) {
    if(report->filetplate) {
      //User-supplied LaTeX template
      tp = fopen(report->filetplate, "r");
    } else {
      //Default LaTeX template
      //tp = fopen("default.tpl", "r");
    }



    switch (report->filetype) {
      case LASER_OUTPUT_TXT: //Output a plain text file
        
        break;
      case LASER_OUTPUT_TEX: //Output a LaTeX file or generated PDF
      case LASER_OUTPUT_PDF:
        //Print the LaTex documentclass header
        fprintf(fp, "\\documentclass{article}\n\\usepackage{authblk}\n\\usepackage{graphicx}\n");
        
        //Generate the title and the authorlist
        fprintf(fp, "\\title{%s}\n", report->header.title);
        fprintf(fp, "\\author{");
        for(i=0; i<report->header.numauths; i++) {
          if(i > 0)
            if(i == report->header.numauths-1)
              fprintf(fp, ", and ");
            else 
              fprintf(fp, ", ");
          fprintf(fp, "%s", report->header.authors[i]);
        }
        fprintf(fp, "}\n");
        
        //Begin the document, write the title and authorlist
        fprintf(fp, "\\begin{document}\n\\maketitle\n");

        //Write the abstract
        fprintf(fp, "\\begin{abstract}\n%s\n\\end{abstract}\n", report->header.abstract);

        //Write the submission characteristics section
        fprintf(fp, "{\\bf Submission information:}\n\n");
        fprintf(fp, "\\begin{tabular}{|c|c|}\n\\hline\n");
        fprintf(fp, "JobID & %ld\\\\ \\hline\n", report->header.jobID);
        fprintf(fp, "Call-line & %s\\\\ \\hline\n", report->header.invocation);
        fprintf(fp, "Num Procs & %d\\\\ \\hline\n", report->header.NP);
        fprintf(fp, "Walltime & %ld secs.\\\\ \\hline\n", report->header.walltime);
        fprintf(fp, "\\end{tabular}\n\n");

        //For each event, create a section with the associated information
        for(i=0; i<report->numevents; i++) {
          strftime(buf, 127, "%Y-%m-%d %H:%M:%S", localtime(&(report->events[i]->generated)));
          fprintf(fp, "\\section{%s {\\small (Generated at %s)}}\n", report->events[i]->title,buf);
          switch(report->events[i]->eventtype) {
            case LASER_EVENT_BASIC:
              fprintf(fp, "%s\n\n%s\n\n", report->events[i]->desc, report->events[i]->data);
              break;
            case LASER_EVENT_IMAGE:
              fprintf(fp, "%s\n\n", report->events[i]->desc);
              //fprintf(fp, "\\begin{figure}\n");
              fprintf(fp, "\\includegraphics[width=.8\\columnwidth]{%s}\n", report->events[i]->data);
              //fprintf(fp, "\\caption{%s}\n", report->events[i]->desc);
              //fprintf(fp, "\\end{figure}\n\n");
              break;
            case LASER_EVENT_TABLE:
              cols=0;
              inbold=0;
              for(j=0; report->events[i]->data[j] != ';'; j++) if(report->events[i]->data[j] == ',') cols++;
              fprintf(fp, "%s\n\n\\begin{tabular}{|c", report->events[i]->desc);
              for(j=1; j<=cols; j++) fprintf(fp, "|c");
              fprintf(fp, "|}\\hline\n");
              for(j=0; j<strlen(report->events[i]->data); j++) 
                switch(report->events[i]->data[j]) {
                  case '*':
                    fprintf(fp, "{\\bf ");
                    inbold = 1;
                    break;
                  case ',':
                    if(inbold) {
                      fprintf(fp, "}");
                      inbold=0;
                    }
                    fprintf(fp, " & ");
                    break;
                  case ';':
                    if(inbold) {
                      fprintf(fp, "}");
                      inbold=0;
                    }
                    fprintf(fp, "\\\\ \\hline\n");
                    break;
                  default:
                    fprintf(fp, "%c", report->events[i]->data[j]);
                    break;
                };
              fprintf(fp, "\\end{tabular}\n\n");
              break;
          };
        }

        //End the document
        fprintf(fp, "\\end{document}");
        break;
    };
  }
  //fclose(tp);
  fclose(fp);

  //Clean up report memory
}
