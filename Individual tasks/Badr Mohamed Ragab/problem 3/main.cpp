// This is a maze. A mouse wants to get from
// corner 0, 0 to N-1, N-1
// It can move only to right or down
// It uses backtracking to find 1st way out
#include<stdio.h>
#include <iostream>

// Maze size
#define N 9

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* A recursive utility function to solve Maze problem,It dosen't work if no
   path is possible, otherwise prints all possible pathes.*/
void PrintAllSolutions(int maze[N][N], int x, int y, int sol[N][N]) {
    // if (x,y is goal) return true
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        std::cout << "--------------------------\n";
        printSolution(sol);
        std::cout << "--------------------------\n";
        return;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true && sol[x][y] == 0)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in down direction */
        PrintAllSolutions(maze, x + 1, y, sol);

        /* If moving in down direction doesn't give solution then
            Move down in right direction  */
        PrintAllSolutions(maze, x, y + 1, sol);

        /* If moving in right direction doesn't give solution then
           Move down in up direction  */
        PrintAllSolutions(maze, x - 1, y, sol);

        /* If moving in up direction doesn't give solution then
           Move down in left direction  */
        PrintAllSolutions(maze, x, y - 1, sol);

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return;
    }
    return;
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses solveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s in case the choice is 2, 
   otherwise it print all the possible solutions,if the choice is 1.*/
bool solveMaze(int maze[N][N], int choice)
{
    int sol[N][N] = { {0} };
    if (choice == 2) {
        if (solveMazeUtil(maze, 0, 0, sol) == false)
        {
            printf("Solution doesn't exist");
            return false;
        }

        printSolution(sol);
        return true;
    }
    else {
        if (solveMazeUtil(maze, 0, 0, sol) == false)
        {
            printf("Solution doesn't exist");
            return false;
        }
        int sol1[N][N] = { {0} };
        PrintAllSolutions(maze, 0, 0, sol1);
        return true;
    }
}

/* A recursive utility function to solve Maze problem,It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x,y is goal) return true
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true && sol[x][y] == 0)
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in down direction */
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        /* If moving in down direction doesn't give solution then
           Move down in right direction  */
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        /* If moving in right direction doesn't give solution then
           Move down in up direction  */
        if (solveMazeUtil(maze, x - 1, y, sol) == true)
            return true;

        /* If moving in up direction doesn't give solution then
           Move down in left direction  */
        if (solveMazeUtil(maze, x, y - 1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// driver program to test above function
int main()
{
    int maze[N][N] = {
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 1}
    };
    int choice = 0;
    while ((choice != 1) && (choice != 2)) {
    std::cout << "Are you want to..\n"
        << "1. Prints all possible solutions?.\n"
        << "2. Prints the optimal solution.\n"
        << "Your choice (1, 2)--> ";
    std::cin >> choice;
    }
    solveMaze(maze, choice);
    return 0;
}
