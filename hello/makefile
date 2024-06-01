CC=gcc
CFLAGS = -std=c17 -Werror -Wall
SOURCE=$(shell find src -iname '*.c')
TARGET=hello

dbg: out/dbg/$(TARGET)
out/dbg/$(TARGET): $(SOURCE)
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -O0 -g -o $@ $^

rel: out/rel/$(TARGET)
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

.PHONY: help
help:
	@echo "Targets:"
	@echo "  dbg      - debug build"
	@echo "  rel      - release build"
	@echo "  clean    - delete output"
	@echo "  run      - run debug build"
	@echo "  fmt      - format the source"

