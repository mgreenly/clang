TARGET=hello
SOURCE=$(sort $(shell find src -iname '*.c' -or -iname '*.h'))
CFLAGS=-std=c17 -pedantic -Werror -Wall

dbg: $(SOURCE) makefile out/dbg
	$(CC) $(CFLAGS) -O0 -g -o out/dbg/$(TARGET) $(filter %.c, $^)

out/dbg:
	mkdir -p $@

rel: $(SOURCE) makefile out/rel
	$(CC) $(CFLAGS) -O2 -s -DNDEBUG -o out/rel/$(TARGET) $(filter %.c, $^)

out/rel:
	mkdir -p $@

sta: $(SOURCE) makefile out/dbg
	$(CC) $(CFLAGS) -fanalyzer -O0 -g -o out/dbg/$(TARGET) $(filter %.c, $^)

all: dbg sta rel

.PHONY: clean
clean:
	rm -rf out

.PHONY: run
run: out/dbg/$(TARGET)
	@./$^

.PHONY: fmt
fmt:
	find src/ -iname '*.h' -o -iname '*.c' -exec clang-format --verbose -i {} \;

.PHONY: gdb
gdb: dbg
	gdb --tui out/dbg/$(TARGET)

.PHONY: grind
grind: dbg
	valgrind -s out/dbg/$(TARGET)

.PHONY: help
help:
	@echo "Targets:"
	@echo "   dbg         - compile with debug symbols"
	@echo "   rel         - compile release out"
	@echo "   all         - out dbg, sta and rel"
	@echo "   run         - run the debug out"
	@echo "   fmt         - reformat the source code"
	@echo "   gdb         - run the dbg out in gdb"
	@echo "   sta         - compile is -fanalyzer"
	@echo "   clean       - delete all generated files"

