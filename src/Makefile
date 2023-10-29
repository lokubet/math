CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 #-pedantic -fsanitize=address
TEST_FLAGS = -lcheck -lpthread -lm
COV_FLAG = --coverage
LIB = s21_math.a
SOURCE = s21_math.c
OBJECT = s21_math.o

ifeq ($(shell uname), Linux)
        TEST_FLAGS += -lrt -lsubunit
endif

all: s21_math.a test gcov_report

s21_math.a: s21_math.c
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rcs $(LIB) $(OBJECT)

test: s21_math.a tests.o
	$(CC) -o tests $(CFLAGS) *.o -L. $(LIB) $(COV_FLAG) $(TEST_FLAGS)
	./tests

tests.o:
	$(CC) $(CFLAGS) -c s21_math_test.c
	$(CC) $(CFLAGS) $(COV_FLAG) -c $(SOURCE)

gcov_report:
	gcovr -r . --html --html-details -o report.html
	open report.html

clang:
	@cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	@rm .clang-format

clean:
	@rm -rf *.html *.gcno *.gcda *.o *.out *.css *coverage* *.a tests

rebuild:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all test gcov_report clang clean rebuild
