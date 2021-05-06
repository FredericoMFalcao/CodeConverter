<?php require_once "base.php"; ?>

#include "main.h"

int help(char *argv0) {
	fprintf(stderr, "Usage: %s [Options]\n[Options]:\n", argv0);
<?php foreach($modules as $module_name) : ?> 
	<?=$module_name?>_help();
<?php endforeach; ?>

	return 1;
}


int main( int argc, char**argv) {

	char *in_str = NULL;
	char *out_str = NULL;
	int cursor = 0;

	/* 1. Get operations MODE */
	for(int i = 0; i < argc; i++) {
		if (streq(argv[i], "--help")) return help(argv[0]);
<?php foreach($modules as $module_name) : ?> 
		<?=$module_name?>_command_line_mode(argv[i]);
<?php endforeach; ?>
	}


	/* 2. Read INPUT into a variable */
	while(!feof(stdin)) {
		if (cursor % 1024 == 0)
			in_str = realloc(in_str, cursor + 1024);
		char c = fgetc(stdin);
		if (c == -1 ) break;
		in_str[cursor++] = c;
	}
	
	in_str[cursor] = '\0';

	int out_str_length = cursor * 2;
	out_str = malloc(out_str_length);

	/* 3. Call MAIN ACTION function */
	parseInput(in_str, out_str, out_str_length);

	/* 4. Print OUTPUT */
	cursor = 0;
	while(out_str[cursor] != '\0')
		fputc(out_str[cursor++], stdout);




	return 0;

}
/* vim:set syntax=c: */
