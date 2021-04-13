COMPILER  := clang
FORMATTER := clang-format

PREPROCESSOR_FLAGS = -I ../include -I ../src -I ../../common
COMPILER_FLAGS = -Werror -Wpedantic -std=c11 -pedantic -g
LINKER_FLAGS   = -g

OBJ_DIR := obj

ifeq ($(OS), Windows_NT)
	SHELL := pwsh.exe
	.SHELLFLAGS := -NoProfile -Command
	RM := rm -Force
endif

.PHONY: help compile test clean

help:
	@echo 'Type "make compile" to compile the test.'
	@echo 'Type "make test" to compile & run the test.'
	@echo 'Type "make clean" to clean all ouput.'
	@echo 'Type "make help" or "make" for this message.'

preprocess : slist-str.h
	$(COMPILER) $^ -E -o slist-str.i $(PREPROCESSOR_FLAGS)
	$(FORMATTER) slist-str.i --assume-filename=.c -i


compile: test.exe

test: compile
	@./test

clean:
	$(RM) obj/*
	$(RM) *.exe

$(OBJ_DIR)/%.o: %.c
	$(COMPILER) $< -o $@ $(PREPROCESSOR_FLAGS) $(COMPILER_FLAGS) -c

test.exe: $(OBJ_DIR)/test.o $(OBJ_DIR)/slist-str.o
	$(COMPILER) $^ -o test.exe $(LINKER_FLAGS)
