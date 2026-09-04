CFLAGS = -Wall -Wextra -Werror --std=c2x

main: main.c status.h
	gcc $(CFLAGS) main.c -o main

clean:
	rm main
