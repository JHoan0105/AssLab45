
#include "header.h"

/*******************************************************************************************************************
Filename: card_game.c
Version: 1.0
Student Name: John Hoang; Spencer Proulx
Student Number: #####6360
Course Name and number: C Language CST 8234_010
Lab Section Number: CST 8234_014
Assignment Number: LabAssessment4_5
Assignment Name: Card Game

Due date of assignment: November 28, 2021
Re-Submission date: December ##, 2021
Professor's Name: Professor Surbhi Bahri

Purpose:  

List of source and header files in the project: 1.card_game.c(main) 2.cardgamefunctions.c 3.header.h (header)

**********************************************************************************************************************/
/*******************************************************************************************************************
Filename: card_game.c
Contains: The main function where the program starts. 
**********************************************************************************************************************/
/*******************************************************************************************************************
 * Function Name: main
 * Purpose: This is the main function that starts the program.
 * Function in parameter: void
 * Function out parameter: EXIT_SUCCESS
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
int main(void)
{
    card *cards = (card*) malloc (sizeof(card));
    deck *deckC = (deck*) malloc(sizeof(deck));
    newDeck *newD = (newDeck*) malloc(sizeof(newDeck));
    

    initCard(cards);

    newD = initDeck(newD, cards);

    display(newD);

    deck *deckShuffle;
    
    deckShuffle = shuffle(*newD); 
    int j;
    for(j = 0; j < 52; j++){
        printf("%-5s",(char*) deckShuffle[j] );
        if ((j+1)%4 == 0) printf("\n");
    }

    hands *gameHands;

    /* enter number of cards to be dealt,  max 26*/
    int input = 5;
    gameHands = deal(deckShuffle, input);

    /*print players and computer cards */
    // printf("%s%22s\n","Player card", "Computer card");
    // for (j = 0; j < 5; j++){
    //     printf("%-20s", gameHands->player[j]);
    //     printf("%s\n", gameHands->computer[j]);
    // }

    playTheCards(gameHands);

    input = 10;
    gameHands = deal(deckShuffle, input);
    
    playTheCards(gameHands);

    free(cards);
    free(deckShuffle);
    free(newD);
    free(deckC);
    return EXIT_SUCCESS;
}