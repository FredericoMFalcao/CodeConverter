MAIN_EXECUTABLE=CodeConverter
APP_MODULES=$(shell ls app_modules/)
SYS_MODULES=$(shell ls sys_modules/)

SHELL=bash
SYS_OBJECTS=$(addsuffix /main.o,$(addprefix sys_modules/,$(SYS_MODULES)))
APP_OBJECTS=$(addsuffix /main.o,$(addprefix app_modules/,$(APP_MODULES)))

TESTS=$(addsuffix /produced.test, $(addprefix app_modules/,$(APP_MODULES)))
define STRIP_MODULE_NAME_FROM_TEST
	$(strip $(subst /produced.test,,$(subst app_modules/,,$1)))
endef

CC=gcc
SOURCES=main.c parseInput.c $(APP_OBJECTS) $(SYS_OBJECTS)
SOURCE_HEADERS=main.h parseInput.h

RED:=\033[0;31m
GREEN:=\033[0;32m
YELLOW:=\033[0;33m
NC:=\033[0m

##################################
#
# 1. BUILD
#
##################################



all: $(SOURCES) $(SOURCE_HEADERS)
	$(CC) -o $(MAIN_EXECUTABLE) $(SOURCES)

%.h: %.h.php
	$(shell [ -f $< ] && php $< > $@)
%.c: %.c.php %.h
	$(shell php $< > $@)

%.o: %.c
	$(CC) -c '-DCLI_FLAG="$(file < $(dir $@)flag)"' -o $@ $<


##################################
#
# 2. TEST
#
##################################

test: $(TESTS)

%/produced.test: %/in.test %/out.test $(MAIN_EXECUTABLE)
	@./$(MAIN_EXECUTABLE) $(file < $(dir $@)flag) < $< > $@
	@diff -q $(dir $@)/produced.test $(dir $@)/out.test 3>&1 > /dev/null && echo -e '[ $(GREEN)SUCCESS$(NC) ] Test $(call STRIP_MODULE_NAME_FROM_TEST,$@) passed.' || echo -e '[ $(RED)FAILED$(NC) ] Test $(call STRIP_MODULE_NAME_FROM_TEST,$@) failed.'

clean:
	@rm $(SOURCES) $(TESTS) $(SOURCE_HEADERS)
