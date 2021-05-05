#include "parseInput.h"
int mode = 0;
int state = STATE_SOURCE_CODE;

int parseInput(char *in_str, char *out_str, size_t out_length) {
	int out_cursor = 0;
	int in_cursor = 0;
	while (in_str[in_cursor] != '\0' && out_cursor < out_length) {
		char c = in_str[in_cursor++];
		char d = (c=='\0'?'\0':in_str[in_cursor]);

#ifdef module_multiline_comments
		multiline_comments_new_char(c, d);
#endif
#ifdef module_singleline_comments
		singleline_comments_new_char(c, d);
#endif

		if (!(mode & MODE_HIDE_OUTPUT)) {
			if (mode & MODE_HIDE_NEXT_2CHAR) {
				CLEAR_MODE(MODE_HIDE_NEXT_2CHAR); SET_MODE(MODE_HIDE_NEXT_CHAR);
			}
			else if (mode & MODE_HIDE_NEXT_CHAR)
				CLEAR_MODE(MODE_HIDE_NEXT_CHAR);
			else
				out_str[out_cursor++] = c;
		}
	}
	out_str[out_cursor] = '\0';

	return 0;
}


