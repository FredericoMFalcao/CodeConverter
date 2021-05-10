void sample_parseChar(char c, char d, String *out) {
	
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
