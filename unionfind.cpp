/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:11/17/15                  *
*                                        *
*****************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cmath>
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
				int left = i - 1;
				if(board[left % boardSize][left / boardSize].OpenOrClosed == 1){
					Union(i, left, arr);
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

double Percolation::GetPercolates(){
	return percolates;
}

int Percolation::NumberOfClusters(string file){
	ifstream inFile;
	string line = "";
	char c;
	int size, count = 0;
	inFile.open(file.c_str());

	while(inFile >> c){
			line += c;
			count++;
		}
	inFile.close();
	size = sqrt(count);
	Board board[size][size];
	int temp = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			board[j][i].OpenOrClosed = int((line[temp] - 48));
			temp++;
		}
	}

	int above = 0, left = 0;
	int arr[size*size];
	for(int i = 0; i < size*size; i++){
		arr[i] = -1;
	}

	for(int i = 0; i < size*size; i++){
		if(board[i%size][i/size].OpenOrClosed == 1){
			arr[i] = i;
			above = i - size;
			if(above >= 0){
				if(board[above%size][above/size].OpenOrClosed == 1){
					Union(i, above, arr);
				}
			}
			if(i % size != 0){
				left = i - 1;
				if(board[left % size][left / size].OpenOrClosed == 1){
					Union(i, left, arr);
				}
			}

		}
	}
    int clusters = 0;
    for(int i = 0; i < size*size; i++){
    	if(i == arr[i]){
    		clusters++;
    	}
    }
    cout << "Number of Clusters: " << clusters << endl;
}
