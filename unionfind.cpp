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

int Percolation::find(int root, int arr[]){
	if(arr[root] != root){
		find(arr[root], arr);
	}
	else{
		return root;
	}
}

void Percolation::Union(int x, int y, int arr[]){
	int a = find(x, arr);
	int b = find(y, arr);
	if(a < b){
		arr[b] = a;
	}
	else{
		arr[a] = b;
	}
}

void Percolation::CreateBoard(){
	Board board[boardSize][boardSize];
	srand(time(NULL));
	int random;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			random = int(rand()%100);
			if(random <= percent){
				board[j][i].OpenOrClosed = 1;
			}
			else{
				board[j][i].OpenOrClosed = 0;
			}
		}
		
	}
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			cout << board[j][i].OpenOrClosed << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			if(board[i][j].OpenOrClosed == 1){
			
			}	
		}
	}

	int arr[boardSize*boardSize];
	int above;

	for(int i = 0; i < boardSize*boardSize; i++){
		arr[i] = -1;
	}
	for(int i = 0; i < boardSize*boardSize; i++){
		if(board[i%boardSize][i/boardSize].OpenOrClosed == 1){
			arr[i] = i;
			above = i - boardSize;
			if(above >= 0){
				if(board[above%boardSize][above/boardSize].OpenOrClosed == 1){
					Union(i, above, arr);
				}
			}
			if(i % boardSize != 0){
				if(board[i - 1][i / boardSize].OpenOrClosed == 1){
					Union(i, i - 1, arr);
				}
			}

		}
	}
	bool Perc = false;
	for(int i = 0; i < boardSize; i++){
		if(board[i][(boardSize - 1)].OpenOrClosed == 1){
			if(find((boardSize - 1)*boardSize + i, arr) < boardSize){
				Perc = true;
			}
		}
	}
	if(Perc){
		percolates++;
	}	
}

int Percolation::GetPercolates(){
	return percolates;
}

