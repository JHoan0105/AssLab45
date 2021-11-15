
#include "header.h"

/*******************************************************************************************************************
Filename: cardgamefunctions.c
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

List of source and header files in the project: 1.

**********************************************************************************************************************/

void display(newDeck *d){
   int i , j;
     for (i = 0; i < 4 ; i++){
        for (j = 1; j < 14; j++){
            if ((j+i)%2 != 0)
                printf("%-5s of %-25s", (char*) (*(*d+i)+j),(char*) *(*d+i));
            else
                printf("%-5s of %s", (char*) (*(*d+i)+j),(char*) *(*d+i));
            if ( ((j+i+2)%2 == 0) ) printf("\n") ;
            }   
     }
     printf("\n");
}

void initCard(card *d){

    strcpy( d->faceArr[0], "Ace");
    strcpy( d->faceArr[1], "Two");
    strcpy( d->faceArr[2], "Three");
    strcpy( d->faceArr[3], "Four");
    strcpy( d->faceArr[4], "Five");
    strcpy( d->faceArr[5], "Six");
    strcpy( d->faceArr[6], "Seven");
    strcpy( d->faceArr[7], "Eight");
    strcpy( d->faceArr[8], "Nine");
    strcpy( d->faceArr[9], "Ten");
    strcpy( d->faceArr[10], "Jack");
    strcpy( d->faceArr[11], "Queen");
    strcpy( d->faceArr[12], "King");

    strcpy( d->suitArr[0], "Spade");
    strcpy( d->suitArr[1], "Heart");
    strcpy( d->suitArr[2], "Diamond");
    strcpy( d->suitArr[3], "Club");    


}

newDeck* initDeck(newDeck* d, card* c){
    int i , j;
    
    for (i = 0; i < lensuit ; i++){
        strcpy((char*) (*d)[i], c->suitArr[i]); 
            for (j = 1; j < lenface; j++){
                strcpy((char*) (*(*d+i)+j), c->faceArr[j-1]);
        }
    }

    return d;
}

deck* shuffle(newDeck d){
    /* note spencer ; i didnt use newDeck here
    I save the work for later. Not sure if i should parse the new deck for the abbreviated suits and faces...*/
    int i,h;
    int j =0; 
    int k[4][14] = {0};
    char* card = (char*) malloc(sizeof(char*));

    deck *shuffleDeck = (deck*) malloc(sizeof(deck));
 
    k[0][0]= -1;
    k[1][0]= -1;
    k[2][0]= -1;
    k[3][0]= -1;
    
    while (j < 45){
        srand(clock());
        h = rand()%14;
        i = rand()%4;
        if (k[i][h] != -1){
            k[i][h] = -1;
            if (h >=10 || h ==1){
                if (h == 1) strcat((char*) shuffleDeck[j], "A" );
                if (h == 10) strcat((char*) shuffleDeck[j], "10" );
                if (h == 11) strcat((char*) shuffleDeck[j], "J" );
                if (h == 12) strcat((char*) shuffleDeck[j], "Q" );
                if (h == 13) strcat((char*) shuffleDeck[j], "K" );
            }else {
                if (h == 2) strcat((char*) shuffleDeck[j], "2" );
                if (h == 3) strcat((char*) shuffleDeck[j], "3" );
                if (h == 4) strcat((char*) shuffleDeck[j], "4" );
                if (h == 5) strcat((char*) shuffleDeck[j], "5" );
                if (h == 6) strcat((char*) shuffleDeck[j], "6" );
                if (h == 7) strcat((char*) shuffleDeck[j], "7" );
                if (h == 8) strcat((char*) shuffleDeck[j], "8" );
                if (h == 9) strcat((char*) shuffleDeck[j], "9" );
            }
            strcat((char*) card, (char*) (d+i) );
            card[1] = '\0';
            strcat((char*) shuffleDeck[j], card );
            j++;
            strcpy((char*) card, "");
        }
    }
    for (i = 0;  i < lensuit ; i++){
        if (j == 52) break;
        for (h = 1;  h < lenface; h++){
            if (k[i][h] != -1){
            k[i][h] = -1;
            if (h >=10 || h ==1){
                if (h == 1) strcat((char*) shuffleDeck[j], "A" );
                if (h == 10) strcat((char*) shuffleDeck[j], "10" );
                if (h == 11) strcat((char*) shuffleDeck[j], "J" );
                if (h == 12) strcat((char*) shuffleDeck[j], "Q" );
                if (h == 13) strcat((char*) shuffleDeck[j], "K" );
            }else {
                if (h == 2) strcat((char*) shuffleDeck[j], "2" );
                if (h == 3) strcat((char*) shuffleDeck[j], "3" );
                if (h == 4) strcat((char*) shuffleDeck[j], "4" );
                if (h == 5) strcat((char*) shuffleDeck[j], "5" );
                if (h == 6) strcat((char*) shuffleDeck[j], "6" );
                if (h == 7) strcat((char*) shuffleDeck[j], "7" );
                if (h == 8) strcat((char*) shuffleDeck[j], "8" );
                if (h == 9) strcat((char*) shuffleDeck[j], "9" );
            }
            strcat((char*) card, (char*) (d+i) );
            card[1]='\0';
            strcat((char*) shuffleDeck[j], card );
            j++;
            strcpy((char*) card, "");
            }
            if (j == 52) break;
        }
    }
    free(card);
    return shuffleDeck;
}

hands* deal(deck* d, int numCards){
    hands *game  = malloc(sizeof(hands));
    static int pos_in_deck=1;
    int i = pos_in_deck;
    int h,j, numInd = (2*numCards + pos_in_deck-1);
/*index of deck */
    numInd = numInd < 52 ? numInd : 52;
/*Number of cards per hand */
    game->numCards = numInd < 52 ? numCards: ((2*numCards+i-1)-52)/2;

    char* temp = (char*) malloc(sizeof(char*));
    temp = NULL;
    for (h = 0, j =0; i <= numInd; i++){
        if (i%2 != 0){
            temp = (char*) d[i-1];
            temp[3] = '\0';
            strcpy(game->player[h], (char*) temp);
            h++;
        } 
        if (i%2 == 0){
            temp = (char*) d[i-1];
            temp[3] = '\0';
            strcpy(game->computer[j],(char*) temp); 
            j++;
        } 
    }
    pos_in_deck = i;
    
    temp = NULL;
    free(temp);

    return game;
}

int playTheCards(hands* h){
    int i,j, numWins=0,cards = h->numCards;
    char* player= (char*) malloc(sizeof(char*));
    char* computer= (char*) malloc(sizeof(char*));

    printf("%-20s%-20s%-20s\n","Player card", "Computer card","Played status");
    for (i = 0; i < cards; i++){
        printf("%-20s", h->player[i]);
        player = h->player[i];
        printf("%-20s", h->computer[i]);
        computer = h->computer[i];

        if (winOrlose(player,computer)) {numWins++;}

    }/*end for loop*/
    printf("rounds : %d\n", cards+1/2);
    if (numWins >= (cards+1)/2){
        if (numWins == (cards+1)/2) { printf("win matches: %d %s\n",numWins, "Tie Round"); return FALSE;}
        printf("win matches: %d %s\n",numWins, "Player WIN Round");
        return TRUE;
    }else printf("win matches: %d %s\n", numWins,"Player Lose Round");

    return FALSE;
}

int winOrlose(char* player, char* computer){
    if (computer[0] > 64 ){
            if ( player[0] < 64) {printf("%s\n", "Player Lose"); return FALSE;}
            if (player[0] == 'A' ){
                if (computer[0] != 'A') { printf("%s\n", "Player WIN"); return TRUE;}
                if (player[1] > computer[1]) { printf("%s\n", "Player WIN"); return TRUE;}
                else {printf("%s\n", "Player Lose"); return FALSE;}
            } 
            if (player[0] == 'K' ){
                if (computer[0] != 'K') { printf("%s\n", "Player WIN"); return TRUE;}
                if (player[1] > computer[1]) { printf("%s\n", "Player WIN"); return TRUE;}
                else {printf("%s\n", "Player Lose"); return FALSE;}
            }
            if (player[0] == 'Q' ){
                if (computer[0] != 'Q') { printf("%s\n", "Player WIN"); return TRUE;}
                if (player[1] > computer[1]) { printf("%s\n", "Player WIN"); return TRUE;}
                else {printf("%s\n", "Player Lose"); return FALSE;}
            }
            if (player[0] == 'J' ){
                if (computer[0] != 'J') { printf("%s\n", "Player WIN"); return TRUE;}
                if (player[1] > computer[1]) { printf("%s\n", "Player WIN"); return TRUE;}
                else {printf("%s\n", "Player Lose"); return FALSE;}
            }
        }else if (player[0] > 64) { 
            printf("%s\n", "Player WIN"); return TRUE;
        }
        
        if (computer[1]=='0'){
                if (player[1] == '0' ){
                    if (player[2] > computer[2]) { printf("%s\n", "Player WIN"); return TRUE;}
                    else {printf("%s\n", "Player Lose"); return FALSE;}          
            }else {printf("%s\n", "Player Lose"); return FALSE;} 
        }else if (player[1] == '0' ) { printf("%s\n", "Player WIN"); return TRUE;}

        if ( player[0] > computer[0]) { printf("%s\n", "Player WIN"); return TRUE;}
        if ( computer[0] > player[0]) {printf("%s\n", "Player Lose"); return FALSE;}

        if (computer[0] == player[0]){
            if (player[1] > computer[1]) { printf("%s\n", "Player WIN"); return TRUE;}
            else {printf("%s\n", "Player Lose"); return FALSE;}
        }
        return FALSE;
}