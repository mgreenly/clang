CFILES=$(sort $(wildcard src/*/*.c))
HFILES=$(sort $(wildcard src/*/*.h))
SOURCE_FILES=$(sort $(CFILES) $(HFILES))

PROG=hello
PROG_FILES=src/$(PROG).c $(SOURCE_FILES)

TEST=test
TEST_FILES=src/$(TEST).c $(SOURCE_FILES)

CFLAGS=-std=c17 -pedantic -Werror -Wall

out/dbg/$(PROG): $(PROG_FILES) makefile out/dbg
	$(CC) $(CFLAGS) -O0 -g -o $@ $(filter %.c, $^)

out/dbg/$(TEST): $(TEST_FILES) makefile out/dbg
	$(CC) $(CFLAGS) -fanalyzer -fprofile-arcs -ftest-coverage -O0 -g -o $@ $(filter %.c, $^)

out/dbg:
	mkdir -p $@

out/rel/$(PROG): $(PROG_FILES) makefile out/rel
	$(CC) $(CFLAGS) -O2 -s -DNDEBUG -o $@ $(filter %.c, $^)

out/rel:
	mkdir -p $@

all: out/dbg/$(PROG) out/dbg/$(TEST) out/rel/$(PROG)

tags: $(SOURCE_FILES)
	ctags $^

.PHONY: debug
debug: out/dbg/$(PROG)

.PHONY: release
release: out/rel/$(PROG)

.PHONY: test-runner
test-runner: out/dbg/$(TEST)

.PHONY: gcov
gcov: out/rel/$(TEST)
	gcov src/test.c

.PHONY: run
run: out/dbg/$(PROG)
	@./$<

.PHONY: test
test: out/dbg/$(TEST)
	@./$<

.PHONY: clean
clean:
	rm -rf out
	rm -rf tags
	rm -rf *.gcno

.PHONY: fmt
fmt:
	find src/ -iname '*.h' -o -iname '*.c' -exec clang-format --verbose -i {} \;

.PHONY: gdb
gdb: dbg
	gdb --tui out/dbg/$(PROG)

.PHONY: grind
grind: out/dbg/$(TEST)
	valgrind -s $<


.PHONY: info
info:
	$(info CC=[$(CC)])
	$(info CFLAGS=[$(CFLAGS)])
	$(info SOURCE_FILES=[$(SOURCE_FILES)])
	$(info TEST=[$(TEST)])
	$(info TEST_FILES=[$(TEST_FILES)])
	$(info PROG=[$(PROG)])
	$(info PROG_FILES=[$(PROG_FILES)])
	@:

.PHONY: help
help:
	@echo "Targets:"
	@echo "   debug        - compile 'src/$(PROG).c' with debug flags"
	@echo "   release      - compile 'src/$(PROG).c' with release flags"
	@echo "   test-runner  - compile 'src/$(TEST).c'"
	@echo "   run          - run 'src/$(PROG).c'"
	@echo "   test         - run 'src/$(TEST).c'"
	@echo "   all          - make 'debug', 'release' and 'test-runner'"
	@echo "   tags         - generate ctags"
	@echo "   fmt          - reformat the source code"
	@echo "   gdb          - run gdb"
	@echo "   gcov         - run gcov"
	@echo "   clean        - delete all generated files"
