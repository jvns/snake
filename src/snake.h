enum Direction { UP, DOWN, LEFT, RIGHT };
enum Status { SUCCESS, FAILURE };
struct Snake {
  int x;
  int y;
  struct Snake* next;
};
void display_snake(struct Snake* snake);
struct Snake* move_snake(struct Snake* snake, enum Direction dir, int xmax, int ymax);
struct Snake* next_move(struct Snake* snake, enum Direction dir, int xmax, int ymax);
struct Snake* create_cell(int x, int y);
struct Snake* create_snake();
enum Direction get_next_move();
