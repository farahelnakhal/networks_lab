## Exercise Soltions -  fqe9080
---

### Playing around with makefile

1. The error message that appears is as follows:

```
$ make
gcc main.c
/usr/bin/aarch64-linux-gnu-ld.bfd: /usr/lib/gcc/aarch64-linux-gnu/15/../../../aarch64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x1c): undefined reference to `main'
/usr/bin/aarch64-linux-gnu-ld.bfd: (.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
make: *** [makefile:2: main] Error 1
$
```
Going through the error, we see the problem is an "undefined reference to `main'". In the `makefile`, `main.c` is where the main() function should be, as seen in

```
main: main.c
	gcc main.c
```

As all C programs require a main function to compile, Going through `main.c`, we notice the file is empty. Including a simple main() function that always returns 0 (success) should solve that problem (see `main.c`). Running make now returns
```
$ make
gcc main.c
$
```
and we see `a.out`. Of course, executing it would return nothing, but make now compiles with no errors.

---
2. Executables are large files and can make a repo much larger than necessary. Also, history of all commits is stored in a hidden `.git` file, adding teh executable makes cloning take more time. Further, C compiles directly into native machine code, and is tied to your specific operating system and CPU architecture, meaning it may not execute on another stem, and whenever a small coding change is done, when creating a PR there will be a merge coflict that will need to be reviewed.

To solve this, we can create a `.gitignore` file, listing all undesirable file types. When commiting, git will automatically ignore all such files. The file has been added in this repo, and contains the following:

```
*.o      //extension of intermediate object files (part of C compilation process)
*.obj    //extension of intermediate object files (part of C compilation process)
*.out    //extension of an executable file in C
*.exe    //extension of an executable file in C
```

There are further files that would be good to ignore as well, but those are the required lines to not commit exectuables. If you are working on Github, you can also elect to include premade `.gitignore` templates based on stack.

---
3. When running `make` again, we get the exact same output as before (ref Q1, last block). What does that mean? The exact command was rerun, the entire 4 step compilation process was gone through again, and the old `a.out` file was overwritten by the output of the new command. But, nothing was changed in our codefiles, and resources were spent on the compilation of files that were previously compiled.

There are many possible fixes for this, all are simple modifications to `makefile`:

- add `-o main` flag to gcc so the generated binary name matches `makefile` target name main. Once main is produced on disk, make checks its modification timestamp against `main.c`. When running again, make sees that main is newer than `main.c` and outputs `make: 'main' is up to date` instead of recompiling. This is the change chosen, and the code can be seen in `makefile`.

- change target name from `main` to `a.out` so it aligns with gcc's default output file. When doing this, make will track the existing a.out file on disk and properly compare timestamps against `main.c`. The change will look as follows:

```
a.out: main.c
	gcc main.c

clean:
	rm a.out
```

Running our chosen fix, we observe the following output:

```
$ make
gcc main.c -o main
$ make
make: 'main' is up to date.
$
```
Exactly what we want.

---
4. When running make, we get the following error:

```
In file included from student.h:1,
                 from main.c:3:
status.h:1:12: error: redefinition of ‘ENROLLED’
    1 | const bool ENROLLED = true;
      |            ^~~~~~~~
In file included from main.c:2:
status.h:1:12: note: previous definition of ‘ENROLLED’ with type ‘_Bool’
    1 | const bool ENROLLED = true;
      |            ^~~~~~~~
make: *** [makefile:2: main] Error 1
```

Why is this happening? Well, the header file does not have the necessary guards. The following should be added likeso:

```
#ifndef STATUS_H //if this header file is not defined under this name
#define STATUS_H //define it under this name

//code...

//end definition
#endif // STATUS_H

```

Adding them, we recieve the correct output:

```
$./main
1
$
```
---
5. Because main was not modified, running `make` again returns "make: 'main' is up to date", and teh output remains 1 (true). To solve this, we simply add a `status.h` dependency to the `makefile`, and so the makefile will be as follows:

```
main: main.c status.h
	gcc main.c -o main
```

Running this again, we get:

```
$ make
gcc main.c -o main
$ ./main 
0
$
```
which is the expected output.

---
6. To do so, we add a variable `CFLAGS` in `makefile`, and add it after gcc (see `makefile`). The variable is set as follows:

```
CFLAGS = -Wall -Wextra -Werror --std=c2x
```
`-Wall` shows all the warnings, `-Wextra` shows all the extra warnings (the ones `-Wall` doesnt include), `-Werror` treats all warnings as errors, and `--std=c2x` uses the latest standard of C from 202x to compile.

---
7. Defining a student (see `main.c`), we get the following output:

```
$ make
gcc -Wall -Wextra -Werror --std=c2x main.c -o main
main.c: In function ‘main’:
main.c:7:15: error: variable ‘student1’ set but not used [-Werror=unused-but-set-variable]
    7 |     student_t student1;
      |               ^~~~~~~~
cc1: all warnings being treated as errors
make: *** [makefile:4: main] Error 1
$
```
This is because we set all warnings to be treated as errors with `-Werror`, and an unused variable causes a warning due to wasted memory space. To resolve this, we must simply tell the complier that we will not be using this variable by adding the keyword `(void)` after declaration (see `main.c`). Adding this solves the error, and running `make` returns

```
$ make
gcc -Wall -Wextra -Werror --std=c2x main.c -o main
$
```

No errors, as expected.
---
### Data Types

1. What is a variable (take a minute to write it down)?
it reserves a spot in memory to hold a value (integer, float, etc) that can change while the program runs

---
2. Each variable has a type in C. What are all the types defined in C?
void, char, short, int, long, float, double, auto.
---
3. Create two files `sizeinfo.h` and `sizeinfo.c`. `sizeinfo.h` should
expose a function `void system_sizes()`. This function

As you work with multiple files, ensure that your editor recognizes
symbols and errors from other files. Remember the `bear` software
that was discussed in lab setup videos.

---
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
