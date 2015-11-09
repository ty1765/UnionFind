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

int Percolation::find(int x, int y, node n[], int size){
	int i = 0;
	bool isFound = false;

	for(i; i < size && !isFound; i=i){
		i++;
		if(n[i].x == x && n[i].y == y){
			isFound = true;
		}
	}

	cout << "Found x: " << x << " y: " << y << " at " << i << endl;
	return i;
}

void Percolation::Merge(int x, int y, node n[], int size){
	
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
	int count= 0;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			if(board[j][i].OpenOrClosed == 1){
				count++;
			}	
		}
	}
	node arr[count];
	int position = 0;
	for(int i = 0; i < boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			if(board[i][j].OpenOrClosed == 1){
				arr[position].x = j;
				arr[position].y = i;
				arr[position].px = j;
				arr[position].py = i;
				position++;
			}	
		}
	}
	for(int i = 0; i < count; i++){
		if(board[arr[i].x][arr[i].y + 1].OpenOrClosed == 1 && (arr[i].y + 1) < boardSize){
			position = find(arr[i].x, arr[i].y + 1, arr, count);
			arr[position].px = arr[i].px; 
			arr[position].py = arr[i].py;
		}
		if(board[arr[i].x + 1][arr[i].y].OpenOrClosed == 1 && (arr[i].x + 1) < boardSize){
			position = find(arr[i].x + 1, arr[i].y, arr, count);
			arr[position].px = arr[i].px; 
			arr[position].py = arr[i].py;
		}
	}
	for(int i = 0; i < count; i++){
		cout << i << "\tx: " << arr[i].x << " y: " << arr[i].y << " px: " << arr[i].px << " py: " << arr[i].py << endl;
	}
		
}

