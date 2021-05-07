/*
*   MULTI LINE COMMENTS 
*
*/
#include "main.h"
int multiline_comments_mode = 0;
int multiline_comments_state = 0;

void multiline_comments_new_char(char c, char d, String *out) {
	// Skip changes if module was not activated
	if (multiline_comments_mode == 0) return;

	// 1. ENTER comment state
	if (multiline_comments_state == STATE_SOURCE_CODE && c == '/' && d == '*') {
		multiline_comments_state = STATE_MULTILINE_COMMENT;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
	// 2. EXIT comment state
	else if (multiline_comments_state == STATE_MULTILINE_COMMENT && c == '*' && d == '/') {
		multiline_comments_state = STATE_SOURCE_CODE;
		SET_MODE(MODE_HIDE_NEXT_2CHAR);
		CLEAR_MODE(MODE_HIDE_OUTPUT);
	}
}

void multiline_comments_command_line_mode(char *str) {
	if (streq(str, "--hide-comments")) multiline_comments_mode = 1;
}
void multiline_comments_help() {
	fprintf(stderr, "\t--hide-comments\n\t\thides all the inline and multi-line comments\n");
}
