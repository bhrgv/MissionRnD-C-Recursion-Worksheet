/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int check_path(int* maze, int rows, int columns, int x1, int y1, int d1, int d2)
{
	if (x1 < 0 || y1 < 0)
		return 0;
	if (x1 >= rows || y1 >= columns)
		return 0;
	if (maze[x1*columns + y1] == 0)
		return 0;
	if (x1 == d1 && y1 == d2)
		return 1;
	if (maze[x1*columns + y1] == 1)
	{
		maze[x1*columns + y1] = 0;
		return check_path(maze, rows, columns, x1 + 1, y1, d1, d2) + check_path(maze, rows, columns, x1, y1 + 1, d1, d2) + check_path(maze, rows, columns, x1 - 1, y1, d1, d2) + check_path(maze, rows, columns, x1, y1 -1, d1, d2);
	}
	return 0;
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0)
		return 0;
	if (x1 >= rows || x2 >= rows)
		return 0;
	if (y1 >= columns || y2 >= columns)
		return 0;
	if (check_path(maze, rows, columns, x1, y1, x2, y2) == 0)
		return 0;
	else
		return 1;
}
