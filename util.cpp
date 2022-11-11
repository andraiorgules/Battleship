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
      //HIT = ship 
      if(grid[x][y] == 1) 
      {
        cout << x << ",";
        cout << y << ":";      
        printf("HIT \n");
      }

      // MISS and NEAR MISS
      //This cycles through the coordinates that surround a 0
       if(grid[x][y] == 0) 
      {
        if (grid[x - 1][y] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n"); //NEAR MISS = this cordinate is 0 BUT a ship is adjacent in up, down, left, right, or diagonal
        }

        if (grid[x][y - 1] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }

        if (grid[x + 1][y] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }

         if (grid[x + 1][y] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }

        if (grid[x][y + 1] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }

         if (grid[x - 1][y] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }

         if (grid[x - 1][y] == 1)
        {
          cout << x << ",";
          cout << y << ":";  
          printf("NEAR MISS \n");
        }
        
        //MISS = no ship + no ship adjacent
        else 
        {
        cout << x << ",";
        cout << y << ":";  
        printf("MISS \n");
        }
      }
    }
  }
}