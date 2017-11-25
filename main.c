#include <stdio.h>
#include "board.h"
#include "ai.h"

#define PLAYER_1 'X'
#define PLAYER_2 'O'

int main(int argc, char *argv[]) {
    Board board = create_board();
    AI ai_player = create_ai(PLAYER_2);

    char current_player = PLAYER_1;
    char player = PLAYER_1;

    int index;
    int playing = 1;

    while (playing) {
      show_board(board);
      printf("\nWelcome to TIC TAC TOE!!!\n");
      printf("Player %c's turn\n", current_player);
      if (current_player == player) {
          printf("Enter the index of the square you wish to fill: ");
          scanf("%d", &index);

          if(!set_square(board, player, index)) {
              printf("Invalid move, please try again\n");
              continue;
          }

      }
      else {
          printf("Computer's Turn!!!\n");
          make_move(ai_player, &board);
      }

      if (check_draw(board)) {
        show_board(board);
        printf("It's a DRAW!!! GAME OVER\n");
        playing = 0;
      }
      else if (check_win(board)) {
          show_board(board);
          printf("Game Over!!! Player %c wins!!!\n", current_player);
          playing = 0;
      }

      current_player = current_player == PLAYER_1 ? PLAYER_2 : PLAYER_1;

      if (!playing) {
          printf("Would you like to play again?: ");
          char input;
          getchar();
          scanf("%c", &input);
          if (input == 'Y' || input == 'y') {
              playing = 1;
              destroy_board(board);
              board = create_board();
              current_player = PLAYER_1;
              if (player == PLAYER_1) {
                  player = PLAYER_2;
                  destroy_ai(ai_player);
                  ai_player = create_ai(PLAYER_1);
              }
              else {
                  player = PLAYER_1;
                  destroy_ai(ai_player);
                  ai_player = create_ai(PLAYER_2);
              }
          }
      }

    }

    destroy_board(board);
    destroy_ai(ai_player);

    return 0;
}
