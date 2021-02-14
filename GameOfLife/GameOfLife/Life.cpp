#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

int Life::checkRule(int i, int j)
{
  int lifeCount = 0;
  for (int k = i - 1; k < i + 2; i++)
    for (int n = j - 1; n < j + 2; j++)
      lifeCount = lifeCount + field[k][n];
  lifeCount = lifeCount - field[i][j];

  if (lifeCount == 3 && field[i][j] == 0)
    field[i][j] = 1;
  if ((lifeCount < 2 || lifeCount > 3) && field[i][j] == 1)
    field[i][j] = 0;
  return field[i][j];
}

void Life::printField()
{
  for (int i = 1; i < HEIGHT - 1; i++)
  {
    for (int j = 1; j < WIDTH - 1; j++)
      if (field[i][j] == 1)
        cout << "*";
      else cout << " ";
    cout << endl;
  }
}

void Life::generateLife()
{
  for (int i = 1; i < HEIGHT - 1; i++)
    for (int j = 1; j < WIDTH - 1; j++)
      field[i][j]= rand() % 2;
}

Life::Life()
{
  for (int i = 1; i < HEIGHT; i++)
    for (int j = 1; j < WIDTH; j++)
      field[i][j] = 0;
}

Life::~Life()
{
}

void Life::runLife()
{
  generateLife();
  printField();
  Sleep(100);
  system("cls");
  while (1)
  {
    for (int i = 1; i < HEIGHT - 1; i++)
      for (int j = 1; j < WIDTH - 1; j++)
        checkRule(i, j);
    printField();
    Sleep(5);
    system("cls");
  }
}
