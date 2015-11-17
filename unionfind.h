/*****************************************
*  Programmer: Tyler Potochnik           *
*  The University Of Akron               *
*                                        *
*  Last Edited:11/17/15                  *
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
	double percolates; // adds one if the board percolates

public:
	Percolation(double, int, int);
	int find(int, int[]);
	void Union(int, int, int[]);
	void CreateBoard();
	double GetPercolates();
	int NumberOfClusters(std::string);
};


#endif 