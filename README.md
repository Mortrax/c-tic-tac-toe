# c-tic-tac-toe
Tic Tac Toe game with a simple console interface to demonstrate a Minimax powered AI player
# Building
- Simply invoke make tictactoe to build the tictactoe app and run via ./tictactoe
- Compiled and tested on Mac OS X 10.11.16 with gcc-7
- Assumes a version of gcc that supports the c11 standard
- You may need to change the alias for CC = gcc-7 to whichever C compiler your system has as default
in the Makefile to get the build to work
# Summary
- This is a simple tic-tac-toe game that allows you to challenge an AI player
- The AI's decision making is backed by the minimax algorithm
- The AI should be unbeatable, and always makes optimal moves for each board position
