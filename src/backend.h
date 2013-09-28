#include <stdbool.h>

enum Direction { UP, DOWN, LEFT, RIGHT };
struct PointList {
  int x;
  int y;
  struct PointList* next;
};
typedef struct PointList PointList;
bool is_same_place(PointList* cell1, PointList* cell2);
PointList* move_snake(PointList* snake, enum Direction dir, int xmax, int ymax);
PointList* next_move(PointList* snake, enum Direction dir, int xmax, int ymax);
PointList* create_cell(int x, int y);
PointList* create_random_cell(int xmax, int ymax);
PointList* create_snake();
bool list_contains(PointList* cell, PointList* list);
PointList* add_new_food(PointList* foods, PointList* snake, int xmax, int ymax);
