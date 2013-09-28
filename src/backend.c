#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum Status move_snake(Board* board, enum Direction dir) {
  // Create a new beginning. Check boundaries.
  PointList* beginning = next_move(board, dir);
  if (beginning == NULL) {
    return FAILURE;
  }

  // If we've gone backwards, don't do anything
  if (board->snake->next && is_same_place(beginning, board->snake->next)) {
    beginning->next = NULL;
    free(beginning);
    return SUCCESS;
  }

  // Check for collisions
  if (list_contains(beginning, board->snake)) {
    return FAILURE;
  }

  // Attach the beginning to the rest of the snake
  beginning->next = board->snake;
  board->snake = beginning;


  // Cut off the end
  PointList* end = board->snake;
  while(end->next->next) {
    end = end->next;
  }
  free(end->next);
  end->next = NULL;

  return SUCCESS;
}

bool is_same_place(PointList* cell1, PointList* cell2) {
  return cell1->x == cell2->x && cell1->y == cell2->y;
}


PointList* next_move(Board* board, enum Direction dir) {
  PointList* snake = board->snake;
  int new_x = snake->x;
  int new_y = snake->y;
  switch(dir) {
    case UP:
      new_y = snake->y - 1;
      break;
    case DOWN:
      new_y = snake->y + 1;
      break;
    case LEFT:
      new_x = snake->x - 1;
      break;
    case RIGHT:
      new_x = snake->x + 1;
      break;
  }
  if (new_x < 0 || new_y < 0 || new_x >= board->xmax || new_y >= board->ymax) {
    return NULL;
  } else {
    return create_cell(new_x, new_y);
  }
}

PointList* create_random_cell(int xmax, int ymax) {
  return create_cell(rand() % xmax, rand() % ymax);
}

void add_new_food(Board* board) {
  PointList* new_food;
  do {
    new_food = create_random_cell(board->xmax, board->ymax);
  } while(list_contains(new_food, board->foods) || list_contains(new_food, board->snake));
  new_food->next = board->foods;
  board->foods = new_food;
}

bool list_contains(PointList* cell, PointList* list) {
  PointList* s = list;
  while (s) {
    if (is_same_place(s, cell)) {
      return true;
    }
    s = s->next;
  }
  return false;
}

PointList* create_cell(int x, int y) {
  PointList* cell = malloc(sizeof(*cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

Board* create_board(PointList* snake, PointList* foods, int xmax, int ymax) {
  Board* board = malloc(sizeof(*board));
  board->foods = foods;
  board->snake = snake;
  board->xmax = xmax;
  board->ymax = ymax;
  return board;
}

PointList* create_snake() {
  PointList* a = create_cell(2,3);
  PointList* b = create_cell(2,2);
  a->next = b;
  return a;
}

