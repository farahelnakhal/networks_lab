# C Review

This repo is provides the first lab content for the networks class
as taught at New York University Abu Dhabi. Familiarity with C is
expected from pre-requisite courses. This is a quick overview of C
before we dive into network programming with it.

## Pre-Requisite

- C compiler installed
- This repo is tested on a fresh install of ubuntu 25.04.

## Exercises

Where a question asks for a fix, there are more than one way to fix it.
Consider these exercises to be more of lecture notes for in-person discussion
rather than a strict guided path into c prowess.

### Playing around with makefile

1. Run the `make` command. What is the error? What is the fix?
2. It is usually NOT a good idea to commit an executable file on git. Why?
How can you make git ignore the executable you are producing in this repo?
3. Run `make` twice. What is the inefficiency? What is the fix (at least two possible)?
4. From your `main.c` file, print the value of only constant
defined in `status.h`. What is the error? What is the fix (at least two possible)?
5. Change the value of the constant in `status.h` from `true` to `false`.
Run `make`. What is the problem? What is the fix?
6. Warnings are a great tool to have when programming.
Enable all the possible warnings you will ever get from your compiler.
7. Include `student.h` into your `makefile`. In addition to step 4,
also define a student. What is the error? What is the fix?

### Data Types

1. What is a variable (take a minute to write it down)?
2. Each variable has a type in C. What are all the types defined in C?
3. Create two files `sizeinfo.h` and `sizeinfo.c`. `sizeinfo.h` should
expose a function `void system_sizes()`. This function

As you work with multiple files, ensure that your editor recognizes
symbols and errors from other files. Remember the `bear` software
that was discussed in lab setup videos.

### Building blocks of Programming

1. Sequence: Covered in `Playing around with makefile`
2. Assignment: Covered in `Data Types`
1. Selection: Write a program that will take a number from the user,
and produce output as follows:

| condition | output |
|-----------|--------|
| divisible by 3 | "foo" |
| divisible by 5 | "bar" |
| divisible by 3 and 5 | "foobar" |

4. Repetition: Write a program to sort an array of integers using bubble sort.
