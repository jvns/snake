#include <stdio.h>
#include "../src/backend.h"

#test test_create_cell
    PointList* snake = create_cell(2, 3);
    fail_unless(snake->x == 2);
    fail_unless(snake->y == 3);

#test test_create_board
    PointList* snake = create_cell(0, 0);
    Board* board = create_board(snake, NULL, 2, 3);
    fail_unless(board->xmax == 2);
    fail_unless(board->ymax == 3);
    fail_unless(board->snake != NULL);
    fail_unless(board->snake->x == 0);



#test test_move_snake_length_1
    PointList* snake = create_cell(0, 0);
    Board* board = create_board(snake, NULL, 2, 2);
    fail_unless(move_snake(board, LEFT) == FAILURE);
    fail_unless(move_snake(board, UP) == FAILURE);
    fail_unless(move_snake(board, DOWN) == SUCCESS);
    fail_unless(move_snake(board, DOWN) == FAILURE);

#test test_move_snake_backwards
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    Board* board = create_board(snake, NULL, 2, 2);
    move_snake(board, DOWN);
    fail_unless(board->snake->x == 2);
    fail_unless(board->snake->y == 2);

#test test_move_snake_collision
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    snake->next->next = create_cell(3, 3);
    snake->next->next->next = create_cell(3, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    fail_unless(move_snake(board, RIGHT) == FAILURE);

#test test_move_snake_down
    PointList* snake = create_cell(2, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    move_snake(board, DOWN);
    fail_unless(board->snake->x == 2);
    fail_unless(board->snake->y == 3);


#test test_move_snake_normally
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    Board* board = create_board(snake, NULL, 4, 4);
    move_snake(board, UP);
    fail_unless(board->snake->x == 2);
    fail_unless(board->snake->y == 1);
    fail_unless(board->snake->next->x == 2);
    fail_unless(board->snake->next->y == 2);
    fail_unless(board->snake->next->next == NULL);

#test test_next_move_corner
    PointList* snake = create_cell(0, 0);
    Board* board = create_board(snake, NULL, 2, 2);
    fail_unless(next_move(board, UP) == NULL);
    fail_unless(next_move(board, LEFT) == NULL);
    fail_unless(next_move(board, DOWN) != NULL);
    fail_unless(next_move(board, RIGHT) != NULL);

#test test_next_move_bottom
    PointList* snake = create_cell(0, 1);
    Board* board = create_board(snake, NULL, 2, 2);
    fail_unless(next_move(board, LEFT) == NULL);
    fail_unless(next_move(board, DOWN) == NULL);
    fail_unless(next_move(board, UP) != NULL);
    fail_unless(next_move(board, RIGHT) != NULL);

#test test_next_move_left
    PointList* snake = create_cell(1, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    PointList* moved = next_move(board, LEFT);
    fail_unless(moved->x == 0);
    fail_unless(moved->y == 2);

#test test_next_move_up
    PointList* snake = create_cell(2, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    PointList* moved = next_move(board, UP);
    fail_unless(moved->x == 2);
    fail_unless(moved->y == 1);

#test test_create_random_cell
    PointList* cell1 = create_random_cell(20, 10);
    PointList* cell2 = create_random_cell(20, 10);
    fail_unless(!(cell1->x == cell2->x && cell1->y == cell2->y));
    fail_unless(cell1->x < 20);
    fail_unless(cell2->x < 20);
    fail_unless(cell1->y < 10);
    fail_unless(cell2->y < 10);

#test test_list_contains_true
    PointList* cell = create_cell(1, 2);
    PointList* list = create_cell(2, 2);
    list->next = create_cell(1, 2);
    fail_unless(list_contains(cell, list));

#test test_list_contains_false
    PointList* cell = create_cell(4, 2);
    PointList* list = create_cell(2, 2);
    list->next = create_cell(1, 2);
    fail_unless(!list_contains(cell, list));

#test test_add_new_food_null
    PointList* snake = create_cell(4, 2);
    snake->next = create_cell(4,3);
    Board* board = create_board(snake, NULL, 20, 10);
    add_new_food(board);
    PointList* foods = board->foods;
    fail_unless(foods != NULL);
    fail_unless(foods->next == NULL);
    fail_unless(!list_contains(foods, snake));

#test test_add_new_food
    PointList* snake = create_cell(4, 2);
    snake->next = create_cell(4,3);
    PointList* foods = create_cell(3, 3);
    Board* board = create_board(snake, foods, 20, 10);
    add_new_food(board);
    fail_unless(board->foods->next != NULL);
    fail_unless(board->foods->next->next == NULL);

#test test_move_snake_with_food
    PointList* snake = create_cell(1, 2);
    PointList* foods = create_cell(2, 2);
    Board* board = create_board(snake, foods, 10, 10);
    move_snake(board, RIGHT);
    fail_unless(board->snake->x == 2);
    fail_unless(board->snake->y == 2);
    fail_unless(board->snake->next != NULL);
    fail_unless(board->snake->next->x == 1);
    fail_unless(board->snake->next->y == 2);

    fail_unless(board->foods->x != 2 || board->foods->y != 2);


#test test_remove_from_list_true
    PointList* cell = create_cell(1, 2);
    PointList* list = create_cell(2, 2);
    list->next = create_cell(1, 2);
    fail_unless(remove_from_list(cell, &list));


#test test_remove_from_list_false
    PointList* cell = create_cell(3, 2);
    PointList* list = create_cell(2, 2);
    list->next = create_cell(1, 2);
    fail_unless(!remove_from_list(cell, &list));

