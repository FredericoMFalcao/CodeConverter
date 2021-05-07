#include "main.h"



String* stringAlloc() {
	String *str   = malloc(sizeof(String));
	str->capacity = 0;
	str->length   = 0;
	str->value    = NULL;

	return str;
}
String* stringInit(String *str) {
	str->capacity = 255;
	str->value    = malloc(str->capacity);
	return str;
}

String *stringAllocAndInit() { return stringInit(stringAlloc()); }
void stringDestroy(String *str) { 
	if (str->capacity != 0 && str->value != NULL) free(str->value); 
	str->capacity = 0;
	str->length   = 0;
}

void appendCharsToString(String *str, char *extension) {
	/* Realloc space if there isn't enough */
	while ((str->capacity - str->length) < strlen(extension))
		str->value = realloc(str->value, (str->capacity*=2));
	/* Append the extension to the orignal string */
	for(unsigned int i = 0; extension[i] != '\0'; i++)
		str->value[str->length++] = extension[i];
}
void appendCharToString(String *str, char c) {
	/* Realloc space if there isn't enough */
	while ((str->capacity - str->length) < 2)
		str->value = realloc(str->value, (str->capacity*=2));
	/* Append the char to the orignal string */
	str->value[str->length++] = c;
}



void stringClear(String *str) {stringDestroy(str); stringInit(str);}
