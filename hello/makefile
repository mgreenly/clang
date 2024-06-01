CC=gcc
CFLAGS = -std=c17 -Werror -Wall
SOURCE=$(shell find src -iname '*.c')
TARGET=hello

default: out/dbg/$(TARGET)
out/dbg/$(TARGET): $(SOURCE)
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -O0 -g -o $@ $^

release: out/rel/$(TARGET)
out/rel/$(TARGET): $(SOURCE)
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -O2 -s -DNDEBUG -o $@ $^

.PHONY: clean
clean:
	rm -rf out

.PHONY: run
run: out/dbg/$(TARGET)
	@./$^

.PHONY: fmt
fmt:
	find src/ -iname '*.h' -o -iname '*.c' -exec clang-format --verbose -i {} \;

.PHONY: debug
debug: default
	gdb --tui out/dbg/$(TARGET)

.PHONY: grind
grind: default
	valgrind -s out/dbg/$(TARGET)

.PHONY: help
help:
	@echo "Targets:"
	@echo "   default     - compile debug build"
	@echo "   release     - compile release build"
	@echo "   run         - run the debug build"
	@echo "   fmt         - reformat the source code"
	@echo "   debug       - run debug build in gdb"
	@echo "   clean       - delete all generated files"

