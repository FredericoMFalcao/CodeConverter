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

	String *in = stringAllocAndInit();
	int cursor = 0;

	/* 1. Get operations MODE */
	if (argc == 1) return help(argv[0]);
	for(int i = 0; i < argc; i++) {
		if (streq(argv[i], "--help")) return help(argv[0]);
<?php foreach($modules as $module_name) : ?> 
		<?=$module_name?>_command_line_mode(argv[i]);
<?php endforeach; ?>
	}


	/* 2. Read INPUT into a variable */
	while(!feof(stdin)) {
		char c = fgetc(stdin);
		if (c == -1 ) break;
		appendCharToString(in, c);
	}
	
	appendCharToString(in, '\0');

	/* 3. Call MAIN ACTION function */
	String *out = stringAllocAndInit();
	parseInput(in, out);

	/* 4. Print OUTPUT */
	cursor = 0;
	while(out->value[cursor] != '\0')
		fputc(out->value[cursor++], stdout);




	return 0;

}
/* vim:set syntax=c: */
