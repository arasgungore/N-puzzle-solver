# n-puzzle-solver

A C++ project which efficiently solves any given N-puzzle (aka 15 puzzle) using a backtracking algorithm on a decision tree.

The program will write all steps without blank spaces or newline characters. Starting from the initial configuration:
• For LEFT move, the program will write letter L,
• For RIGHT move, the program will write letter R,
• For UP move, the program will write letter U,
• For DOWN move, the program will write letter D on the terminal.

This project was assigned for the Introduction to Object-Oriented Programming (CMPE 160) course on Spring 2019 semester.
Moreover, as stated in the introduction of the project description, this project has challenged me to build a chess bot
using decision trees from scratch (minus the alpha-beta pruning algorithm), which you can find it [here](https://github.com/arasgungore/chess-bot).



## Run on Terminal

```sh
g++ Header/*.cpp main.cpp -std=c++11 -o test
test
```



## Author

👤 **Aras Güngöre**

* LinkedIn: [@arasgungore](https://www.linkedin.com/in/arasgungore)
* GitHub: [@arasgungore](https://github.com/arasgungore)
