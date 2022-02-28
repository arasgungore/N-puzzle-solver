#ifndef N_PUZZLE_SOLVER_H
#define N_PUZZLE_SOLVER_H

#include "PathNode.h"
#include <string>
#include <vector>


// NPuzzleSolver class declaration.
class NPuzzleSolver {
private:
	std::vector<unsigned short> puzzleBoard;
	PathNode root;
	static void printSeparator(const char &ch, const unsigned short &boxWidth, const unsigned short &boardSize);
public:
	NPuzzleSolver(const std::string &puzzle);
	void printPuzzle() const;
	void solve();
};

#endif		// N_PUZZLE_SOLVER_H
