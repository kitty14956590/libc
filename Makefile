BUILD_DIR := build

CC := gcc
S := gcc
CCFLAGS := -O1 -march=native -fomit-frame-pointer -fallow-store-data-races -Wno-pointer-to-int-cast -I includes -nostdlib -g
LD := ld
MAKE := make
AR := ar


SOURCES=$(wildcard src/*.c)

OBJECTS=$(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

OUTPUT := libc.a

TEST_PROGRAM := test.c
TEST_OUTPUT := test

default: mkdir build test

mkdir:
	mkdir -p ${BUILD_DIR}

$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CCFLAGS) $^ -c -o $@

build: ${OBJECTS}
	${AR} cr ${OUTPUT} $^

clean:
	rm -rf ${BUILD_DIR} ${OUTPUT} ${TEST_OUTPUT}

test: ${OUTPUT}
	$(CC) $(CCFLAGS) ${TEST_PROGRAM} ${OUTPUT} -o ${TEST_OUTPUT}
