CC=gcc

main:
	${CC} -c argumentize.c builtin_pk_ls.c commandParser.c display.c exec_clock.c execCmd.c input.c lineParser.c pinfo.c
	$(CC) main.c argumentize.o builtin_pk_ls.o commandParser.o display.o exec_clock.o execCmd.o input.o lineParser.o pinfo.o -o ItsPKsshell

clean:
	rm *.o
	rm ItsPKsshell
