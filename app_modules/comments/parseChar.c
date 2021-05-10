void comments_parseChar(char c, char d, String *out) {
	// Skip changes if module was not activated
	if (comments_mode == 0) return;

	// 1. ENTER comment state
	if (comments_state == 0 && c == '/' && d == '*') {
		comments_state = STATE_MULTI_LINE_COMMENT;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
	else if (comments_state == 0 && c == '/' && d == '/') {
		comments_state = STATE_SINGLE_LINE_COMMENT;
		SET_MODE(MODE_HIDE_OUTPUT);
	}
	// 2. EXIT comment state
	else if (comments_state == STATE_MULTI_LINE_COMMENT && c == '*' && d == '/') {
		comments_state = 0;
		SET_MODE(MODE_HIDE_NEXT_2CHAR);
		CLEAR_MODE(MODE_HIDE_OUTPUT);
	}
	else if (comments_state == STATE_SINGLE_LINE_COMMENT && c == '\n') {
		comments_state = 0;
		SET_MODE(MODE_HIDE_NEXT_CHAR);
		CLEAR_MODE(MODE_HIDE_OUTPUT);
		
	}

}
