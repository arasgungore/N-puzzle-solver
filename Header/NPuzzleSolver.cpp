#include "NPuzzleSolver.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>


#define MAX_NO_OF_LEVELS 25


// Constructor for NPuzzleSolver.
NPuzzleSolver::NPuzzleSolver(const std::string &puzzle) {
	std::stringstream ss(puzzle);
	unsigned short n;
	char ch;
	while(ss >> n) {
		ss >> ch;
		puzzleBoard.push_back(n);
	}
	puzzleBoard.shrink_to_fit();
}


// Prints a line separator to split the rows of the N-puzzle on the terminal.
void NPuzzleSolver::printSeparator(const char &ch, const unsigned short &boxWidth, const unsigned short &boardSize) {
	for(unsigned short i = 1; i < boardSize; i++)
		std::cout << std::string(boxWidth, ch) << "|";
	std::cout << std::string(boxWidth, ch) << std::endl;
}


// Prints the N-puzzle on the terminal.
void NPuzzleSolver::printPuzzle() const {
	const unsigned short boxWidth = std::to_string(puzzleBoard.size()).length() + 2, boardSize = std::sqrt(puzzleBoard.size());
	std::cout << "Board size: " << boardSize << std::endl;
	std::cout << "Initial grid position:" << std::endl << std::endl;
	for(unsigned short i = 0; i < boardSize; i++) {
		printSeparator(' ', boxWidth, boardSize);
		for(unsigned short j = 0; j < boardSize; j++) {
			const unsigned short currentElement = puzzleBoard[i*boardSize + j],
			currentNumberLength = std::to_string(currentElement ? currentElement : puzzleBoard.size() - 1).length(), diff = boxWidth - currentNumberLength;
			const std::string separator = std::string(diff/2, ' ');
			std::cout << separator << (currentElement ? std::to_string(currentElement) : std::string(currentNumberLength, ' ')) << separator;
			if(diff % 2)
				std::cout << " ";
			if(j < boardSize - 1)
				std::cout << "|";
		}
		if(i < boardSize - 1) {
			std::cout << std::endl;
			printSeparator('_', boxWidth, boardSize);
		}
	}
	std::cout << std::endl;
	printSeparator(' ', boxWidth, boardSize);
	std::cout << std::endl << std::endl;
}


// Main method to solve the N-puzzle by adding a layer to the decision tree until either the solution is found or the MAX_NO_OF_LEVELS threshold is reached.
void NPuzzleSolver::solve() {
	std::string solution = "";
	const unsigned short emptySlotIndex = distance(puzzleBoard.begin(), std::find(puzzleBoard.begin(), puzzleBoard.end(), 0)), boardSize = std::sqrt(puzzleBoard.size());
	unsigned short copyEmptySlotIndex, levelCount = 0;
	std::vector<unsigned short> copyPuzzleBoard;
	do {
		if(++levelCount > MAX_NO_OF_LEVELS) {
			std::cout << std::endl << "Solution:  N/A" << std::endl << std::endl << std::endl;
			break;
		}
		root.addLevel();
		root.checkAllPaths(solution, copyPuzzleBoard = puzzleBoard, boardSize, copyEmptySlotIndex = emptySlotIndex);
	} while(solution.empty());
//	while(--levelCount)
//		root.clearLastLevel();
	root.clearTree();
}
