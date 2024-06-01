
SOURCE=src/main.c src/foo.c
TARGET=hello

dbg: out/dbg/$(TARGET)
out/dbg/$(TARGET): $(SOURCE)
	mkdir -p $(shell dirname $@)
	gcc -std=c17 -Werror -Wall -O0 -g -o $@ $^

rel: out/rel/$(TARGET)
out/rel/$(TARGET): $(SOURCE)
	mkdir -p $(shell dirname $@)
	gcc -std=c17 -Werror -Wall -O2 -s -DNDEBUG -o $@ $^

.PHONY: clean
clean:
	rm -rf out

.PHONY: run
run: out/dbg/$(TARGET)
	@./$^

.PHONY: fmt
fmt:
	find src/ -iname '*.h' -o -iname '*.c' -exec clang-format --verbose -i {} \;
