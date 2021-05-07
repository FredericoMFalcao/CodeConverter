#include <stdlib.h> /* malloc(), realloc() */
#include <string.h> /* strlen() */

typedef struct {
	size_t capacity;
	size_t length;
	char *value;
} String;

String* stringAlloc();
String* stringInit(String *str);
String *stringAllocAndInit();
void stringDestroy(String *str);

void appendCharsToString(String *str, char *extension);
void appendCharToString(String *str, char c);

void stringClear(String *str);
