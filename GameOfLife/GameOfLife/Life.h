#pragma once
// Ширина поля 
#define FIELD_HEIGHT 10

// Высота поля 
#define FIELD_WIDTH 10
const int HEIGHT = FIELD_HEIGHT + 2;
const int WIDTH = FIELD_WIDTH + 2;

class Life
{
  int field[HEIGHT][WIDTH];

  int checkRule(int i, int j);
  void printField();
  void generateLife();

public:
  Life();
  ~Life();
  void runLife();
};

