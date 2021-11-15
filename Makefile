# -*- MakeFile -*-

CC = gcc

CFLAGS = -g -Wall -ansi -pedantic -w
INCLUDES = -I ~/{workSpaceDir}/{JohnHoang040896360}
OUT_EXE = card

all: $(OUT_EXE)

$(OUT_EXE):  card_game.o cardgamefunctions.o header.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUT_EXE) card_game.o cardgamefunctions.o

card_game.o: card_game.c header.h
	$(CC) -c card_game.c

cardgamefunctions.o: cardgamefunctions.c header.h	
	$(CC) -c cardgamefunctions.c


clean:
	rm *.o card