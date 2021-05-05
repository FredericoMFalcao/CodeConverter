/*
* 1. EXTERNAL LIBs
*
*/

#include <strings.h> /* strcmp() */

/*
* 2. INTERNAL LIBs
*
*/
#include "../parseInput.h"

/*
* 3. CONSTANTS
*
*/

/*
* 4. INTERNAL FUNCTIONS
*
*/
#define streq(a,b) (strcmp(a,b) == 0)

void multiline_comments_new_char(char c, char d);
void multiline_comments_command_line_mode(char *str);
