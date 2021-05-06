/*
*   SAMPLE
*
*/

/* 1. EXTERNAL LIBs */
#include <stdio.h>
#include <stdlib.h>
/* All the Unix Libraries your module needs should go here. */
/* e.g. #include <stdio.h>
*       #include <stdlib.h>
*       etc...
*/

/* 2. INTERNAL LIBs */
#include "../../parseInput.h"

/* 3. CONSTANTS */
#define CLI_FLAG "--sample-mode"
#define CLI_HELPER_DESCRIPTION "this module does nothing. it's simply placeholder code for new developers."

/* 4. INTERNAL FUNCTIONS */

/* You should implement the following functions : 
*
*  
*  void sample_new_char(char c, char d);
*	- called everytime a new character is processed in the input stream
*
*  void sample_command_line_mode(char *str);
*       - called to process the command line arguments
*
*/
void sample_new_char(char c, char d);
void sample_command_line_mode(char *str);
void sample_help();
