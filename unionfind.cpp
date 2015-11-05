/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:                          *
*                                        *
*****************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "unionfind.h"

using namespace std;

Percolation::Percolation(double per, int number, int size){
	numOfBoards = number;
	percent = per * 100;
	boardSize = size;
	percolates = 0;
}

void Percolation::CreateBoard(){
	Board board[boardSize][boardSize];
	srand(time(NULL));
	int random;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			random = int(rand()%100);
			std::cout << random << " ";
			if(random >= percent){
				board[i][j].OpenOrClosed = 1;
			}
			else{
				board[i][j].OpenOrClosed = 0;
			}
		}
		cout << endl;
	}
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){

			cout << board[i][j].OpenOrClosed << " ";
		}
		cout << endl;
	}
}
