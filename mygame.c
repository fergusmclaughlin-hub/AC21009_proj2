/*
	Name: Fergus McLaughlin
	ID: 170015911
	Module: AC21008
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

//board size
#define Width  10
#define Height 10

/*//create the board
void createBoard(int board[Width][Height])
{
     //board is decalred 
    //used in chreating the board
    int i;
    int j;

    for (i = 0; i < Width; i++) 			//if i is less than the board width then add to i
    {									

        for (j = 0; j < Height; j++) 		//if j is less than the board height then add to j
        {
            board[i][j] = '0';				// what to fill the board with '0' = dead
            printf("%c ", board[i][j]);		//print baord
        }
        printf("\n"); 						//space at end of board
    }
}
*/
/*void deadState()
{
    
    //used in chreating the board
    int i;
    int j;

    for (i = 0; i < Width; i++) 			//if i is less than the board width then add to i
    {									

        for (j = 0; j < Height; j++) 		//if j is less than the board height then add to j
        {
            board[i][j] = '0';				// what to fill the board with '0' = dead
            printf("%c ", board[i][j]);		//print baord
        }
        printf("\n"); 						//space at end of board
    }
}
*/
void randomState(int rboard[Width][Height];)
{
   // int board[Width][Height]; //board is decalred //NOT RANDOMN 
    //used in chreating the board
    int i;
    int j;
    int ri = (rand() % 10); 
    int rj = (rand() % 10); 

    int rk = (rand() % 10); 
    int rl = (rand() % 10);

    int rm = (rand() % 10); 
    int rn = (rand() % 10);

    int ro = (rand() % 10); 
    int rp = (rand() % 10); 

int rboard[Width][Height];

    for (i = 0; i < Width; i++) 			//if i is less than the board width then add to i
    {									

        for (j = 0; j < Height; j++) 		//if j is less than the board height then add to j
        {
           
            rboard[i][j] = '0';
            

            rboard[ri][rj] = '1'; // random part is 1
            rboard[rk][rl] = '1'; //random part is 1
            rboard[rm][rn] = '1'; // random part is 1
            rboard[ro][rp] = '1'; //random part is 1
            printf("\033[0;32m"); // make the board green
            printf("%c ", rboard[i][j] /*? '0':'1'*/); // print board
            printf("\033[0m");    //remove colour
        }
        printf("\n");                   		 
    }    

    printf("\n"); 
    printf("\n");				
}
/*
1- less than two neighbours = dead
2- more than three neighbours = dead
3- two - three neighbours = lives
4- dead  cell with three neighbours = life
*/
void nextState(int rboard)
{
    int i;
    int j;

    randomState(rboard);

    int nextBoard [Width] [Height];

    int cellCount = 0;

    for (i = 0; i < Width -1; i++) for (j = 0; j < Height-1; j++) 
    {

        if (rboard[i-1][j-1]) cellCount++;
        if (rboard[i][j-1]) cellCount++;
        if (rboard[i+1][j-1]) cellCount++;
        if (rboard[i+1][j]) cellCount++;
        if (rboard[i+1][j+1]) cellCount++;
        if (rboard[i][j+1]) cellCount++;
        if (rboard[i-1][j+1]) cellCount++;
        if (rboard[i-1][j]) cellCount++;

        if (cellCount < 2)
        {
            nextBoard[i][j] = '-';

        } 
        else if (cellCount > 3)
        {
            nextBoard[i][j] = '-';

        }
        else if (cellCount == 2 || cellCount == 3)
        {
            nextBoard[i][j] == '0';
        }
        else if (rboard[i][j] == '-' && cellCount == 3)
        {
            nextBoard[i][j] = '0' ;       
        }

    }
    for(j = 0; j < Height; j++) 
    {
        for (i = 0; i < Width; ++i)
        {
            rboard[i][j] = nextBoard[i][j];
        }
    }
}


int main(int *rboard)
{
    int Gen = 0;

    randomState(rboard);
    for (int i = 0; i < 101; i++){
    
    Gen++;

    printf("--Generation : %d--", Gen);
    printf("\n");

    nextState(rboard);
    //nextState(board);

    sleep (1);
    system("clear");
}
    return 0;
}

