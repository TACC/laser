/********************************************************************
 *
 *  TACC In-job Report Library
 *  Authors: Lucas Wilson (lwilson@tacc.utexas.edu
 *           Carlos Rosales (carlos@tacc.utexas.edu)
 *
 *  The TACC In-job Report Library (libreport) provides an intuitive
 *  means of generating summary report for interesting scientific or
 *  computation events that occur in-job, in order to reduce the need
 *  for post-processing on large-scale data sets.
 *   
 *******************************************************************/

// EVENTTYPE DEFINES
#define RPT_EVENT_BASIC 0
#define RPT_EVENT_IMAGE 1
#define RPT_EVENT_TABLE 2

// FILETYPE DEFINES
#define RPT_OUTPUT_PDF 0
#define RPT_OUTPUT_TXT 1
#define RPT_OUTPUT_TEX 2

typedef struct {
  char *title;            //Title for the event to be generated
  char *desc;             //Description of the event
  time_t generated;       //Time the event was generated (UNIX epcoh)
  short eventtype;        //Type of event (defines provided above)
  char *data;             //String containting the event specifics
} event_type;

typedef struct {
  char *filename;    //Name of the file to be generated
  short filetype;    //Type of report to generate (defines provided above)
  char *filetplate;  //Name of the file containing the LaTeX template

  struct {
    char *title;     //Title for this report
    char **authors;  //Authors
    char *abstract;       //A brief description of what the job generating this report is doing
    unsigned long jobID;  //Batch ID from the scheduler
    char *invocation;     //Shell invocation line for the job generating this report
    unsigned int NP;      //Number of processors for the job
    time_t walltime;      //Time requested for job
  } header;

  event_type *events;     //The actual events that will be in the report

} report_type;


/********************************************************************
 *
 *   FUNCTION createReport
 *   Create a report object
 *
 *   Inputs:     fname - String containing the filename to generate
 *               ftype - Type of file to create (PDF, TXT, TEX) (Use RPT_OUTPUT defines)
 *           ftemplate - LaTeX template file to use (optional, for default use NULL)
 *               title - Title of the report
 *            abstract - Description of the report
 *             authors - List of author/contributor/researcher names
 *
 *   Outputs: Report object pointer (report_type *)
 *
 *******************************************************************/
report_type *createReport(char *fname, short ftype, char *ftemplate, char *title, char *abstract, char **authors);

/********************************************************************
 *
 *   FUNCTION createEvent
 *   Create an event object to add to a report
 *
 *   Inputs: title - Name for the event
 *            desc - Description of the event
 *           etype - Type of event to create (Use RPT defines)
 *            data - String containting the event specifics
 *
 *   Outputs: Event object pointer (event_type *)
 *
 *******************************************************************/
event_type *createEvent(char *title, char *desc, short etype, char *data);

/********************************************************************
 *
 *   FUNCTION addEvent
 *   Add an event to a report
 *
 *   Inputs: report - Pointer to report object
 *            event - Pointer to event object to be added
 *
 *   Outputs: None
 *
 *******************************************************************/
 void addEvent(report_type *report, event_type *event);

/********************************************************************
 *
 *   FUNCTION generateReport
 *   Generate final report from given report object
 *
 *   Inputs: report - Pointer to report object
 *
 *   Outputs: None
 *
 *******************************************************************/
void generateReport(report_type *report);
