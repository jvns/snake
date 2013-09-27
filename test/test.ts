#include <stdio.h>
#include "../src/snake.h"

#test test_create_cell
    struct Snake* snake = create_cell(2, 3);
    fail_unless(snake->x == 2);
    fail_unless(snake->y == 3);


#test test_move_snake_walls
    struct Snake* snake = create_cell(0, 0);
    fail_unless(move_snake(snake, LEFT, 2, 2) == NULL);
    fail_unless(move_snake(snake, UP, 2, 2) == NULL);
    fail_unless(move_snake(snake, DOWN, 2, 2)->x == 2);
    fail_unless(move_snake(snake, DOWN, 2, 2)->y == 1);
    fail_unless(move_snake(snake, RIGHT, 2, 2)->x == 1);
    fail_unless(move_snake(snake, RIGHT, 2, 2)->y == 2);
