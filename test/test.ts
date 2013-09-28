#include <stdio.h>
#include "../src/backend.h"

#test test_create_cell
    PointList* snake = create_cell(2, 3);
    fail_unless(snake->x == 2);
    fail_unless(snake->y == 3);


#test test_move_snake_length_1
    PointList* snake = create_cell(0, 0);
    fail_unless(move_snake(snake, LEFT, 2, 2) == NULL);
    fail_unless(move_snake(snake, UP, 2, 2) == NULL);

#test test_move_snake_backwards
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    PointList* moved = move_snake(snake, DOWN, 4, 4);
    fail_unless(moved->x == 2);
    fail_unless(moved->y == 2);

#test test_move_snake_collision
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    snake->next->next = create_cell(3, 3);
    snake->next->next->next = create_cell(3, 2);
    fail_unless(move_snake(snake, RIGHT, 4, 4) == NULL);

#test test_move_snake_down
    PointList* snake = create_cell(2, 2);
    PointList* moved = move_snake(snake, DOWN, 4, 4);
    fail_unless(moved->x == 2);
    fail_unless(moved->y == 3);


#test test_move_snake_normally
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    PointList* moved = move_snake(snake, UP, 4, 4);
    fail_unless(moved->x == 2);
    fail_unless(moved->y == 1);
    fail_unless(moved->next->x == 2);
    fail_unless(moved->next->y == 2);
    fail_unless(moved->next->next == NULL);

#test test_next_move_corner
    PointList* snake = create_cell(0, 0);
    fail_unless(next_move(snake, UP, 2, 2) == NULL);
    fail_unless(next_move(snake, LEFT, 2, 2) == NULL);
    fail_unless(next_move(snake, DOWN, 2, 2) != NULL);
    fail_unless(next_move(snake, RIGHT, 2, 2) != NULL);

#test test_next_move_bottom
    PointList* snake = create_cell(0, 1);
    fail_unless(next_move(snake, DOWN, 2, 2) == NULL);
    fail_unless(next_move(snake, LEFT, 2, 2) == NULL);
    fail_unless(next_move(snake, UP, 2, 2) != NULL);
    fail_unless(next_move(snake, RIGHT, 2, 2) != NULL);

#test test_next_move_left
    PointList* snake = create_cell(1, 2);
    PointList* moved = next_move(snake, LEFT, 4, 4);
    fail_unless(moved->x == 0);
    fail_unless(moved->y == 2);

#test test_next_move_up
    PointList* snake = create_cell(2, 2);
    PointList* moved = next_move(snake, UP, 4, 4);
    fail_unless(moved->x == 2);
    fail_unless(moved->y == 1);
