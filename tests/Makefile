CFLAGS = -Wall -g
LDFLAGS = -lpthread -lrt -lncurses
CC = gcc
SOURCES = $(wildcard *.c)
BINARIES = $(patsubst %.c,%,$(SOURCES))
DEPS = $(patsubst %.c,%.d,$(SOURCES))

all: $(BINARIES)

%: %.c
	$(CC) $(CFLAGS) $< -o $(patsubst %.c,%,$<) $(LDFLAGS)

ipctest: ipctest.c ../src/ui_ipc.c
	$(CC) $(CFLAGS) ipctest.c ../src/ui_ipc.c -o ipctest $(LDFLAGS)

clean:
	rm -f $(DEPS)
	rm -f $(BINARIES)

run: all
	@echo "* running tests"
	for test in $(patsubst %.c,%,$(SOURCES)); do \
		echo -n "* running $${test}"; \
		./$${test} >/dev/null; \
		if [ $$? -ne 0 ]; then \
			echo " FAILED!"; \
		else \
			echo " OK!"; \
		fi; \
	done

.PHONY: all install clean
