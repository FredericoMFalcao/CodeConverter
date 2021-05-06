/*
*   SAMPLE
*
*/

/* 1. EXTERNAL LIBs */

/* All the Unix Libraries your module needs should go here. */
/* e.g. #include <stdio.h>
*       #include <stdlib.h>
*       etc...
*/

/* 2. INTERNAL LIBs */

/* if you want access to the main STATE and MODE */
/* then #include "../parseInput.h" */

/* 3. CONSTANTS */

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
