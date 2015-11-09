/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:                          *
*                                        *
*****************************************/

#ifndef UNION_FIND_H
#define UNION_FIND_H

struct Board{
	int OpenOrClosed; // 1 is for an open cell and 0 is for a closed cell
	int x, y; //positon on board
};
struct node{
	int x,y; //nodes location
	int px,py; //parents location
};

class Percolation{
private:
	int numOfBoards, boardSize;
	double percent;
	int percolates; // adds one if the board percolates

public:
	Percolation(double, int, int);
	int find(int, int, node[], int);
	void Merge(int, int, node[], int);
	void CreateBoard();
	bool DoesPercolate();
	double FindPercPercent();
	int NumberOfClusters();
};


#endif 