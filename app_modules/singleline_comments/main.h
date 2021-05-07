/*
*   SINGLE LINE COMMENTS 
*
*/

/* 1. EXTERNAL LIBs */
#include <strings.h> /* strcmp() */
#include <stdio.h>   /* fprintf(), stderr */

/* 2. INTERNAL LIBs */
#include "../../parseInput.h"

/* 3. CONSTANTS */

/* 4. INTERNAL FUNCTIONS */
#define streq(a,b) (strcmp(a,b) == 0)



void singleline_comments_new_char(char c, char d, String *out);
void singleline_comments_command_line_mode(char *str);
void singleline_comments_help();
