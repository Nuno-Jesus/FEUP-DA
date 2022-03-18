#include "exercises.h"
#include <iostream>

using namespace std;

Labyrinth::Labyrinth(int values[10][10]){
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      labyrinth[i][j] = values[i][j];
}

void Labyrinth::print() const
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cout << labyrinth[i][j] << " ";
    }
    cout << endl;
  }
}

bool Labyrinth::findGoal(int x, int y){
  initializeVisited();
  return findGoalHelper(x, y);
}

bool Labyrinth::findGoalHelper(int x, int y){
  //If the user reached a wall or a already visited cell return false
  if (labyrinth[y][x] == MAZE_WALL || visited[y][x]){
    return false;
  }

  //Otherwise visit it for the first time
  visited[y][x] = true;

  //If the cell is the maze exit return true
  if (labyrinth[y][x] == MAZE_EXIT)
    return true;

  //Try other cells in all 4 main directions
  else
  { 
    //Left
    if (findGoalHelper(x - 1, y)){
      cout << '('<< x - 1 << ", " << y << ')' << " <- ";
      return true;
    }
    //Right
    if (findGoalHelper(x + 1, y)){
      cout << '('<< x + 1<< ", " << y << ')' << " <- ";
      return true;
    }
    //Up
    if (findGoalHelper(x, y - 1)){
      cout << '('<< x << ", " << y - 1 << ')' << " <- ";
      return true;
    }
    //Down
    if (findGoalHelper(x, y + 1)){
      cout << '('<< x << ", " << y + 1 << ')' << " <- ";
      return true;
    }
  }

  return false;
}

void Labyrinth::initializeVisited(){
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      visited[i][j] = false;
}

void Labyrinth::initializeSolution(){
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      solution[i][j] = false;
}

int main(){
  int lab1[10][10] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
      {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
      {0, 1, 1, 1, 0, 0, 1, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
      {0, 1, 1, 1, 0, 0, 1, 2, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  int lab2[10][10] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
      {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
      {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
      {0, 1, 1, 1, 0, 0, 1, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
      {0, 1, 1, 1, 0, 0, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  
  cout << "----> L1 <----" << endl;
  Labyrinth l1(lab1);
  if(l1.findGoal(1, 1))
    cout << "BEGIN" << endl;

  else
    cout << "No path available!" << endl;

  cout << endl << "----> L2 <----" << endl;
  Labyrinth l2(lab2);
  if(l2.findGoal(1, 1))
    cout << "BEGIN" << endl;

  else
    cout << "No path available!" << endl;
  return 0;
}