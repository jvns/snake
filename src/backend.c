#include "backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

PointList* move_snake(PointList* snake, enum Direction dir, int xmax, int ymax) {
  // Create a new beginning. Check boundaries.
  PointList* beginning = next_move(snake, dir, xmax, ymax);
  if (beginning == NULL) {
    return NULL;
  }

  // If we've gone backwards, don't do anything
  if (snake->next && is_same_place(beginning, snake->next)) {
    beginning->next = NULL;
    free(beginning);
    return snake;
  }

  // Check for collisions
  if (list_contains(beginning, snake)) {
    return NULL;
  }

  // Attach the beginning to the rest of the snake
  beginning->next = snake;
  snake = beginning;


  // Cut off the end
  PointList* end = snake;
  while(end->next->next) {
    end = end->next;
  }
  free(end->next);
  end->next = NULL;

  return snake;
}

bool is_same_place(PointList* cell1, PointList* cell2) {
  return cell1->x == cell2->x && cell1->y == cell2->y;
}


PointList* next_move(PointList* snake, enum Direction dir, int xmax, int ymax) {
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
  if (new_x < 0 || new_y < 0 || new_x >= xmax || new_y >= ymax) {
    return NULL;
  } else {
    return create_cell(new_x, new_y);
  }
}

PointList* create_random_cell(int xmax, int ymax) {
  return create_cell(rand() % xmax, rand() % ymax);
}

PointList* add_new_food(PointList* foods, PointList* snake, int xmax, int ymax) {
  PointList* new_food;
  do {
    new_food = create_random_cell(xmax, ymax);
  } while(list_contains(new_food, foods) || list_contains(new_food, snake));
  new_food->next = foods;
  return new_food;
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

PointList* create_snake() {
  PointList* a = create_cell(2,3);
  PointList* b = create_cell(2,2);
  a->next = b;
  return a;
}

