/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:11/17/15                  *
*                                        *
*****************************************/
#include <iostream>
#include <stdlib.h>
#include "unionfind.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc == 2){
		string file = argv[1];
		Percolation Perc(1,1,1);
		Perc.NumberOfClusters(file);
	}
	else if(argc == 4){
		double percent = atof(argv[1]);
		int number = atoi(argv[2]);
		double total = atof(argv[2]);
		int size = atoi(argv[3]);
		double rate;
		srand(time(NULL));

		Percolation Perc(percent, number, size);
		while(number > 0){
			Perc.CreateBoard();
			number--;
		}
		rate = Perc.GetPercolates()/total;
		cout << "Percolation Rate: " << rate << endl;
	}
	else{
		cerr << "Invalid Number of Arguments!" << endl;
	}
	return 0;
}