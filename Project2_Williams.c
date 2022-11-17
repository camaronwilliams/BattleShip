/*
Program Name: Project2_Williams.c
Programmer: Camaron Williams
Class: CS 3335
Project: 02
*/ 
#define SIZE 10
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void setBoard(int *);

void setComputerBoard(int *);

int playGame(int *, int *);

void layoutboards(int*, int*);

int main(){
    int humanboard[SIZE] = {0};
    int computerboard[SIZE] = {0};
    srand(time(NULL));
    setBoard(humanboard);
    setComputerBoard(computerboard);
    layoutboards(humanboard, computerboard);
    int champion = playGame(humanboard, computerboard);
    if(champion){
        printf("\nHuman wins!\n");
    }
    else{
        printf("\nComputer Wins!\n");
    }
    layoutboards(humanboard,computerboard);
    return 0;
}
void setBoard(int *humanboard){
    int n = 0;
    printf("Enter position: ");
    scanf("%d", &n);
    humanboard[n] = 1;
}
void setComputerBoard(int* computerboard){
    computerboard[rand() % 10] = 1;
}
int playGame(int *humanboard, int *computerboard){
    int computerpick;
    int humanpick;
    int champion;
    while(1){
        computerpick = rand() % 10;
        if(humanboard[computerpick] == 1){
            champion = 0;
            humanboard[computerpick] = 3;
            printf("HIT!\n");
            break;
        }
        else{
            humanboard[computerpick] = 2;
            printf("\nComputer Guesses: %d\n", computerpick);
            printf("\nMISS!\n");
            layoutboards(humanboard, computerboard);
        }
        printf("\nEnter Guess: ");
        scanf("%d", &humanpick);
        printf("\nYou guessed %d\n",humanpick);
        if(computerboard[humanpick] == 1){
            champion = 1;
            computerboard[humanpick] = 3;
            printf("\nHIT!\n");
            break;
        }
        else{
            computerboard[humanpick] = 2;
            printf("\nMISS!\n");
            layoutboards(humanboard, computerboard);
        }
    }
    return champion;
}
void layoutboards(int *humanboard, int *computerboard){
    printf("\nHuman Board:\n");
    for(int  i = 0; i < SIZE; i++){
        if(humanboard[i] == 0){
            printf(" * ");
        }
        else if(humanboard[i] == 1){
            printf(" S ");
        }
        else if(humanboard[i] == 2){
            printf(" M ");
        }
        else if(humanboard[i] == 3){
            printf(" H ");
        }
    }
    printf("\nComputer Board: \n");
    for(int  i = 0; i < SIZE; i++){
        if(computerboard[i] == 0 || computerboard[i] == 1){
            printf(" * ");
        }
        else if(computerboard[i] == 2){
            printf(" M ");
        }
        else if(computerboard[i] == 3){
            printf(" H ");
        }
    }
}
