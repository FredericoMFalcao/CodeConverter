<?php require_once "base.php"; ?>

#include "parseInput.h"
int mode = 0;
int state = STATE_SOURCE_CODE;

int parseInput(String *in, String *out) {
	size_t in_cursor = 0;

	while (in->value[in_cursor] != '\0' ) {
		char c = in->value[in_cursor++];
		char d = (c=='\0'?'\0':in->value[in_cursor]);
<?php foreach($modules as $module_name) : ?>
		<?=$module_name?>_parseChar(c, d, out);
<?php endforeach; ?> 
		// printf("read char %c, current length : %d, current capacity: %d, current value : %s\n",c,out->length, out->capacity, out->value);
		if (!(mode & MODE_HIDE_OUTPUT)) {
			if (mode & MODE_HIDE_NEXT_2CHAR) {
				CLEAR_MODE(MODE_HIDE_NEXT_2CHAR); SET_MODE(MODE_HIDE_NEXT_CHAR);
			}
			else if (mode & MODE_HIDE_NEXT_CHAR)
				CLEAR_MODE(MODE_HIDE_NEXT_CHAR);
			else
				appendCharToString(out, c);
		
		}
	}
	appendCharToString(out, '\0');

	return 0;
}


/* vim:set syntax=c: */
