#include "util.h"
#include<iostream>
using namespace std;


const int rows = 16;
const int columns = 16;
int grid[rows][columns];
int ships = 10;


void Clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int g=0; g < columns; g++)
        {
            grid[i][g] = 0;
        }
    }
}

//Make a 16x16 grid filled with 0s
void Build()
{
    for(int i=0; i < rows; i++)
    {
        for(int g=0; g < columns; g++)
        {
            cout << grid[i][g] << "";
        }
        cout << endl;
    }
}

//Randomly replace ten 0s with a 1 (occupied by 10 ships)
void PlaceShips()
{
  int n = 0;

  srand(time(NULL));

  while(n < ships)
  {
    int x = rand() % rows;
    int y = rand() % columns;

    if(grid[x][y] != 1)
    {
      n++;
      grid[x][y] = 1;
    }
  }

}

//Scan each coordinate and print what is there (HIT, MISS, NEAR MISS)
void Scan()
{
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      if(grid[x][y] == 1) //HIT = ship 
      {
        cout << x << ",";
        cout << y << ":";      
        printf("HIT \n");
      }

      //change this to only affect 0s that don't have a 1 adjacent
       if(grid[x][y] == 0) //MISS = no ship + no ship adjacent
      {ß
        cout << x << ",";
        cout << y << ":";  
        printf("MISS \n");
      }

      //NEAR MISS = ship is adjacent in up, down, left, right, or diagonal
      //if the coordinate is a 0 AND there is a 1 adjacent
      //print the coordinate 
      //printf("NEAR MISS"); 

    }
  }
}