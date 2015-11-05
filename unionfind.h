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

class Percolation{
private:
	int numOfBoards, boardSize;
	double percent;
	int percolates; // adds one if the board percolates

public:
	Percolation(double, int, int);
	void CreateBoard();
	double FindPercPercent();
	int NumberOfClusters();
};


#endif 