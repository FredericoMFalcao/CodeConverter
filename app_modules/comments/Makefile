SHELL=bash
MODULE_NAME=comments
all:
	$(CC) -c '-DCLI_FLAG="$(file < flag)"' -o main.o main.c

test: produced.test

produced.test: in.test out.test main.o
	./$(MAIN_EXECUTABLE) $(file < flag) < $< > $@
	@diff -q produced.test out.test 2>&1 > /dev/null && echo -e '[ $(GREEN)SUCCESS$(NC) ] Test '$(MODULE_NAME)' passed.' || echo -e '[ $(RED)FAILED$(NC) ] Test '$(MODULE_NAME)' failed.'	
