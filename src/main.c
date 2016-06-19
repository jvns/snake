#include "backend.h"
#include "frontend.h"
#include <ncurses.h>
#include <string.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // make keys work
  curs_set(0); // hide cursor
  timeout(100);
  char game_over[] = "Game Over!\n";
  int end;

  int xmax;
  int ymax;
  getmaxyx(stdscr, ymax, xmax);
  enum Direction dir = RIGHT;

  Board* board = create_board(create_snake(), NULL, xmax, ymax);
  int i;
  for (i = 0; i < 6; i++) {
    add_new_food(board);
  }

  while(true) {
    erase();
    display_points(board->snake, ACS_BLOCK);
    display_points(board->foods, ACS_DIAMOND);
    dir = get_next_move(dir);
    enum Status status = move_snake(board, dir);
    if (status == FAILURE) break;
  }

  attron(A_BOLD);
  mvprintw(ymax/2, (xmax - strlen(game_over))/2, game_over);
  echo();
  refresh();
  sleep(2);
  endwin();

  return 0;
}
