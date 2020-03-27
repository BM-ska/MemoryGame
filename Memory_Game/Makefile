program: funkcje.o grafika.o
	gcc -std=c11 -Wall -Wextra funkcje.o grafika.o -o program `pkg-config gtk+-3.0 --libs`

grafika.o: grafika.c gra.h
	gcc `pkg-config gtk+-3.0 --cflags` -std=c11 -Wall -Wextra -c grafika.c -o grafika.o	

funkcje.o: funkcje.c gra.h
	gcc `pkg-config gtk+-3.0 --cflags` -std=c11 -Wall -Wextra -c funkcje.c -o funkcje.o	

.PHONY : clean
clean :
	rm program *.o
