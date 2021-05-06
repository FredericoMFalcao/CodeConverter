<?php require_once "base.php"; ?>
#ifndef _parseInput_h
#define _parseInput_h

/*
* 1. EXTERNAL LIBs
*
*/

#include <stdlib.h> /* size_t */

/*
* 2. INTERNAL LIBs
*
*/
<?php foreach($modules as $module_name) : ?>
	#include "modules/<?=$module_name?>/main.h"
<?php endforeach; ?> 

#define MODE_REPLACE_STR_LITERALS    1
#define MODE_HIDE_COMMENTS           2
#define MODE_PRINT_STR_LITERALS_LIST 4
#define MODE_HIDE_OUTPUT             8
#define MODE_HIDE_NEXT_CHAR          16
#define MODE_HIDE_NEXT_2CHAR         32


#define STATE_SOURCE_CODE        0
#define STATE_MULTILINE_COMMENT  1
#define STATE_SINGLELINE_COMMENT 2
#define STATE_DBL_QUOTE_STR      3
#define STATE_SGL_QUOTE_STR      4

#define SET_MODE(f)   mode |= f
#define CLEAR_MODE(f) mode &= (~f)

extern int mode;
extern int state;


int parseInput(char *in_str, char *out_str, size_t out_length);


#endif
/* vim:set syntax=c: */
