/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:                          *
*                                        *
*****************************************/
#include <iostream>
#include <stdlib.h>
#include "unionfind.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc == 2){

	}
	else if(argc == 4){
		double percent = atof(argv[1]);
		int number = atoi(argv[2]);
		int total = atoi(argv[2]);
		int size = atoi(argv[3]);

		Percolation Perc(percent, number, size);
		while(number > 0){
			Perc.CreateBoard();
			number--;
		}
		cout << "Percolation Rate: " << Perc.GetPercolates()/total << endl;
	}
	else{
		cerr << "Invalid Number of Arguments!" << endl;
	}
	return 0;
}