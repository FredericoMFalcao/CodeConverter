/*
*   SAMPLE 
*
*/
#include "main.h"
int sample_mode = 0;
int sample_state = 0;

void sample_new_char(char c, char d) {
	
	// to enable the module comment the next line
	return;

	// Skip changes if module was not activated
	if (sample_mode == 0) return;


	// 1. ENTER sample state
	if (sample_state == 0 && c == '-' && d == '-') {
		sample_state = 1;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
	// 2. EXIT comment state
	else if (sample_state == 1 && c == '-' && d == '-') {
		sample_state = 0;
		SET_MODE(MODE_HIDE_NEXT_CHAR);
		CLEAR_MODE(MODE_HIDE_OUTPUT);
	}

}

void sample_command_line_mode(char *str) { if (streq(str, CLI_FLAG)) sample_mode = 1; }
void sample_help() { fprintf(stderr, "\t%s\n\t\t%s\n",CLI_FLAG,CLI_HELPER_DESCRIPTION); }
