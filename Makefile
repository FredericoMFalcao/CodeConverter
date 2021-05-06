MAIN_EXECUTABLE=CodeConverter
MODULES=$(shell ls modules/)

SHELL=bash
OBJECTS=$(addsuffix /main.o,$(addprefix modules/,$(MODULES)))
TESTS=$(addsuffix /produced.test, $(addprefix modules/,$(MODULES)))
define STRIP_MODULE_NAME_FROM_TEST
	$(strip $(subst /produced.test,,$(subst modules/,,$1)))
endef

CC=gcc
SOURCES=main.c parseInput.c $(OBJECTS) 

RED:=\033[0;31m
GREEN:=\033[0;32m
YELLOW:=\033[0;33m
NC:=\033[0m

##################################
#
# 1. BUILD
#
##################################



all: $(SOURCES) $(OBJECTS)
	$(CC) -o $(MAIN_EXECUTABLE) $^

%.h: %.h.php
	$(shell [ -f $< ] && php $< > $@)
%.c: %.c.php %.h
	$(shell php $< > $@)

%.o: %.c
	$(CC) -c -o $@ $<


##################################
#
# 2. TEST
#
##################################

all-tests: $(MODULES)
	@diff -q $(dir $@)/produced.test $(dir $@)/out.test 2>&1 > /dev/null && echo -e '[ $(GREEN)SUCCESS$(NC) ] Test $@ Passed.' || echo -e '[ $(RED)FAILED$(NC) ] Test $@ failed.'

test: $(TESTS)

%/produced.test: %/in.test %/out.test $(SOURCES)
	@./$(MAIN_EXECUTABLE) $(file < $(dir $@)flags.test) < $< > $@
	@diff -q $(dir $@)/produced.test $(dir $@)/out.test 2>&1 > /dev/null && echo -e '[ $(GREEN)SUCCESS$(NC) ] Test $(call STRIP_MODULE_NAME_FROM_TEST,$@) passed.' || echo -e '[ $(RED)FAILED$(NC) ] Test $(call STRIP_MODULE_NAME_FROM_TEST,$@) failed.'

clean:
	@rm $(SOURCES) $(TESTS)
	@rm parseInput.h
