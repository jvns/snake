#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

struct Snake {
  int x;
  int y;
  struct Snake* next;
};

void display_snake(struct Snake* snake) {
  while(snake) {
    mvprintw(snake->x, snake->y, "#");
    snake = snake->next;
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

int main() {
  //int x;
  //int y;
  initscr();
  //getmaxyx(stdscr, y, x);
  display_snake(create_snake());
  getch();
  //printf("Size: %d %d", x, y);
  return 0;
}
