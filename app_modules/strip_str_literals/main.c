/*
*   strip_str_literals 
*
*/
#include "main.h"

#define streq(a,b) (strcmp(a,b) == 0)

#define DOUBLE_QUOTE_STRING 1
#define SINGLE_QUOTE_STRING 2
#define ESCAPE_NEXT_CHARACTER 4

int strip_str_literals_mode  = 0;

#define MODE_HIDE_STRING_LITERALS 1
#define MODE_DISPLAY_STR_LIST     2

int strip_str_literals_state = 0;

String *temp = NULL;
char temp_str[255];


int no_of_literals = 0;

void strip_str_literals_new_char(char c, char d, String *out_str	) {
	
	// to enable the module comment the next line
//	return;

	// Skip changes if module was not activated
	if (strip_str_literals_mode == 0) return;



	if (0) {}
	// 1.0 Exit ESCAPE NEXT CHARACTER mode
	else if ((strip_str_literals_state & 3 ) && strip_str_literals_state & ESCAPE_NEXT_CHARACTER) { strip_str_literals_state &= (~4); }
	// 1. ENTER strip_str_literals state
	else if (strip_str_literals_state == 0 && c == '"')  { strip_str_literals_state = DOUBLE_QUOTE_STRING; SET_MODE(MODE_HIDE_OUTPUT); }
	else if (strip_str_literals_state == 0 && c == '\'') { strip_str_literals_state = SINGLE_QUOTE_STRING; SET_MODE(MODE_HIDE_OUTPUT); }
	// 2. EXIT comment state
	else if (
		(strip_str_literals_state == DOUBLE_QUOTE_STRING && c == '"' )
			||
		(strip_str_literals_state == SINGLE_QUOTE_STRING && c == '\'' )
	) {
		if (strip_str_literals_mode == MODE_HIDE_STRING_LITERALS)
		{	sprintf(temp_str, "STR_%03d", no_of_literals++); appendCharsToString(out_str, temp_str);}
		if (strip_str_literals_mode == MODE_DISPLAY_STR_LIST)
		{	
			
			appendCharToString(temp,c); 
			appendCharToString(temp,'\n'); 
			appendCharToString(temp,0);
			sprintf(temp_str, "#define STR_%03d ",no_of_literals++); appendCharsToString(out_str,temp_str); 
			appendCharsToString(out_str, temp->value); 			
			stringClear(temp);
		}
			
		strip_str_literals_state = 0;
		if (strip_str_literals_mode == MODE_HIDE_STRING_LITERALS) {
			SET_MODE(MODE_HIDE_NEXT_CHAR);
			CLEAR_MODE(MODE_HIDE_OUTPUT);			
		}
	}
	else if (strip_str_literals_state > 0) {		
		// 1.2 Enter ESCAPE NEXT CHARACTER mode
		if ( c == '\\') strip_str_literals_state |= ESCAPE_NEXT_CHARACTER;
	}
	
	/*
	*  2. Save String Literals
	*
	*/

	// Save each character internally
	if (strip_str_literals_state & 3)
		appendCharToString(temp, c);
	
}

void strip_str_literals_command_line_mode(char *str) { 
	if (streq(str, CLI_FLAG)) 
		strip_str_literals_mode = MODE_HIDE_STRING_LITERALS; 
	if (streq(str, "--show-literals-list"))
	{
		strip_str_literals_mode = MODE_DISPLAY_STR_LIST;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
		
	
	if (!temp) temp = stringAllocAndInit();
}
void strip_str_literals_help() { fprintf(stderr, "\t%s\n\t\t%s\n",CLI_FLAG,CLI_HELPER_DESCRIPTION); }
