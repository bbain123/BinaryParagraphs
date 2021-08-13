#makefile for main

main:
	gcc -o main *.c
clean:
	rm -f $(OBJS)$(OUT)
