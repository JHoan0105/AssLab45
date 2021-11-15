/*******************************************************************************************************************
Filename: header.h
Version: 1.0
Student Name: John Hoang ; Spencer Proulx
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
Filename:  header.h
Contains: This header file contains all the prototype functions and variable declareation required for
          the card_game.c program
**********************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*******************************************************************************************************************
 * Directive for 1 for true. Provides for boolean implementation.
********************************************************************************************************************/
#define TRUE 1

/*******************************************************************************************************************
 * Directive for 0 for false. Provides for boolean implementation.
********************************************************************************************************************/
#define FALSE 0

/*******************************************************************************************************************
 * Directive the len of array for suits.
********************************************************************************************************************/
#define lensuit 4

/*******************************************************************************************************************
 * Directive the len of array for faces.
********************************************************************************************************************/
#define lenface 14

/*******************************************************************************************************************
 * Directive for improvised boolean method returns. Return integer or -1 for false.
********************************************************************************************************************/
#define flip -1

/*******************************************************************************************************************
 * Structure type declaration for card. Holding 2 arrays, 1 for faces(13 string value of 8 char) 
 * and 1 for suits(4 string value with 8 char).
********************************************************************************************************************/
typedef struct card{
    char faceArr[13][8];
    char suitArr[4][8];
}card;

/*******************************************************************************************************************
 * Structure type declaration for hand dealt holding 2 arrays and an integer type. 1 array for player,
 * 1 array for computer and integer holding the number of cards dealt. Arrays can hold max 26 coded 3 char string.
********************************************************************************************************************/
typedef struct hands{
    char player[26][4];
    char computer[26][4];
    int numCards;
}hands ;

/*******************************************************************************************************************
 * Deck of card array type declaration. This type holds 52 string value.
********************************************************************************************************************/
typedef char deck[52][8];

/*******************************************************************************************************************
* 2D array type for string. The suits and faces array table. first column holds the suit followed by the faces. 
* ie [0][13] is King of Spade, [1][13] King of Heart, [2][13] King of Diamond and [3][13] King of Club 
********************************************************************************************************************/
typedef char* newDeck[4][14];

/*******************************************************************************************************************
 * Function Name: display
 * Purpose: Display the array of cards to reference 2D array table.
 * Function in parameter: Takes a type newDeck 2D array. Holding 4 row x 14 column string. 
 * Function out parameter: Console Output
 * Version: 1
 * Author: John Hoang , Spencer
********************************************************************************************************************/
void display(newDeck*);

/*******************************************************************************************************************
 * Function Name: initCard
 * Purpose: This function initializes the values for the card structure for the faces and suits array.
 * Function in parameter: Pointer to card type.
 * Function out parameter: void - Initialization by pointer to card type.
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
void initCard(card*);

/*******************************************************************************************************************
 * Function Name: initDeck
 * Purpose: This function initializes the newDeck type (array of char pointer) with the values of the initialized
 * type card (structure). To create the array holding the reference table for cards in the game.
 * Function in parameter: pointer to type newDeck(2D string array), card type (structure with 2 arrays , face and suit) 
 * Function out parameter: Returns a pointer to newDeck a 2D string array
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
newDeck* initDeck(newDeck*, card*);

/*******************************************************************************************************************
 * Function Name: shuffle
 * Purpose: This function shuffles the faces to suits to initialized 52 posible cards mixed.
 * Function in parameter: Type newDeck holding the values to mix.
 * Function out parameter: Pointer to type deck (array of 52 strings)
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
deck* shuffle(newDeck);

/*******************************************************************************************************************
 * Function Name: deal
 * Purpose: To deal out the cards from the array of mixed cards to player and computer.
 * Function in parameter: Type deck to deal to player or computer, Integer type hold the number of cards to deal to each.
 * Function out parameter: Type hands (structure to 2 arrays of string to player and computer and number of cards dealt)
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
hands* deal(deck*,int);

/*******************************************************************************************************************
 * Function Name: playTheCards
 * Purpose: This function provides the frame to compare the player and computer hands to determine winners and losers.
 * Function in parameter: Type hands pointer. To access the records for the player and computer hands.
 * Function out parameter: Boolean Return True if player wins else false, including tie.
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
int playTheCards(hands*);

/*******************************************************************************************************************
 * Function Name: winOrlose
 * Purpose: This function compares the player and computer hands to determine winnner and loser
 * Function in parameter: char* string of player hand, char* string of computer hand
 * Function out parameter: True for player win, False for player lose, no tie.
 * Version: 1
 * Author: John Hoang, Spencer
********************************************************************************************************************/
int winOrlose(char*,char*);


