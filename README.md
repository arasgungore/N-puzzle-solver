# N-puzzle-solver

A C++ project which efficiently solves any given N-puzzle (aka 15 puzzle) using a backtracking algorithm on a decision tree.



## Run on Terminal

```sh
g++ Header/*.cpp main.cpp -std=c++11 -o test
test
```



## Description

In this project, the main objective is developing a program that solves the puzzle
game, whose rules are as follows:

- Game table is an NxN table whose cells are filled with numbers from 1
  to (N^2 − 1), and the remaining one is blank.
- Only the blank box can be moved on the table and the moving direction
  can be either horizontal or vertical (diagonal moves are not possible).
- When the blank box is moved, the blank one and the box in the destination
  position of the blank box are swapped.



## Output

The program will write all steps without blank spaces or newline characters. Starting from the initial configuration:
- For LEFT move, the program will write letter L,
- For RIGHT move, the program will write letter R,
- For UP move, the program will write letter U,
- For DOWN move, the program will write letter D on the terminal.



## Further Notes

This project was assigned for the Introduction to Object-Oriented Programming (CMPE 160) course in the Spring 2019 semester. Upon completion of the project, as stated in the introduction of the project description, this project has challenged me to build a chess bot using decision trees from scratch (minus the alpha-beta pruning algorithm), which you can find it [here](https://github.com/arasgungore/chess-bot).



## Author

👤 **Aras Güngöre**

* LinkedIn: [@arasgungore](https://www.linkedin.com/in/arasgungore)
* GitHub: [@arasgungore](https://github.com/arasgungore)
