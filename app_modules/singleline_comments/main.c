/*
*   SINGLE LINE COMMENTS 
*
*/
#include "main.h"


#define streq(a,b) (strcmp(a,b) == 0)
int singleline_comments_mode = 0;

void singleline_comments_new_char(char c, char d, String *out) {
	// Skip changes if module was not activated
	if (!singleline_comments_mode) return;
	
	// 1. ENTER comment state
	if (state == STATE_SOURCE_CODE && c == '/' && d == '/') {
		state = STATE_SINGLELINE_COMMENT;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
	// 2. EXIT comment state
	else if (state == STATE_SINGLELINE_COMMENT && c == '\n') {
		state = STATE_SOURCE_CODE;
		SET_MODE(MODE_HIDE_NEXT_CHAR);
		CLEAR_MODE(MODE_HIDE_OUTPUT);
	}
}

void singleline_comments_command_line_mode(char *str) {
	if (streq(str, "--hide-comments")) singleline_comments_mode = 1;

}
void singleline_comments_help() {
}
