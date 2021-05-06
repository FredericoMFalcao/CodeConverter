MAIN_EXECUTABLE=CodeConverter
shell=bash
OBJECTS=modules/multiline_comments.o \
	modules/singleline_comments.o\
	modules/sample.o
CC=gcc




all: main.c parseInput.c $(OBJECTS)
	$(CC) -o $(MAIN_EXECUTABLE) $^

%.h: %.h.php
	$(shell [ -f $< ] && php $< > $@)
%.c: %.c.php %.h
	$(shell php $< > $@)

%.o: %.c
	$(CC) -c -o $@ $<

test:


clean:
	@rm main.c
	@rm parseInput.c
	@rm parseInput.h
