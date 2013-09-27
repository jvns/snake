#include <ncurses.h>
#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_snake(struct Snake* snake) {
  while(snake) {
    mvprintw(snake->x, snake->y, "#");
    snake = snake->next;
  }

}


struct Snake* move_snake(struct Snake* snake, enum Direction dir, int xmax, int ymax) {
  // Create a new beginning. Check boundaries.
  struct Snake* beginning = next_move(snake, dir, xmax, ymax);
  if (beginning == NULL) {
    return NULL;
  }

  // If we've gone backwards, don't do anything
  if (snake->next && is_same_place(beginning, snake->next)) {
    beginning->next = NULL;
    free(beginning);
    return snake;
  }

  // Attach the beginning to the rest of the snake
  beginning->next = snake;
  snake = beginning;

  // Cut off the end
  struct Snake* end = snake;
  while(end->next->next) {
    end = end->next;
  }
  free(end->next);
  end->next = NULL;

  return snake;
}

bool is_same_place(struct Snake* cell1, struct Snake* cell2) {
  return cell1->x == cell2->x && cell1->y == cell2->y;
}


struct Snake* next_move(struct Snake* snake, enum Direction dir, int xmax, int ymax) {
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
  if (new_x < 0 || new_y < 0 || new_x > xmax || new_y > ymax) {
    return NULL;
  } else {
    return create_cell(new_x, new_y);
  }
}

struct Snake* create_cell(int x, int y) {
  struct Snake* cell = malloc(sizeof(*cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

struct Snake* create_snake() {
  struct Snake* a = create_cell(2,3);
  struct Snake* b = create_cell(2,2);
  a->next = b;
  return a;
}

enum Direction get_next_move() {
  return UP;
}

