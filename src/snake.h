enum Direction { UP, DOWN, LEFT, RIGHT };
enum Status { SUCCESS, FAIL };
struct Snake;
void display_snake(struct Snake* snake);
enum Status move_snake(struct Snake* snake, enum Direction dir);
struct Snake* next_move(int x, int y, enum Direction dir);
struct Snake* create_cell(int x, int y);
struct Snake* create_snake();
enum Direction get_next_move();
