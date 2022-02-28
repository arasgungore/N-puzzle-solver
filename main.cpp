#include "Header/PathNode.h"
#include "Header/NPuzzleSolver.h"

int main() {
	NPuzzleSolver TwoToTwo("1-2-0-3");
	TwoToTwo.printPuzzle();
	TwoToTwo.solve();
	
	NPuzzleSolver ThreeToThree_ez("0-1-2-4-6-3-7-5-8");
	ThreeToThree_ez.printPuzzle();
	ThreeToThree_ez.solve();
	
	NPuzzleSolver ThreeToThree_avg("5-1-2-4-6-3-0-7-8");
	ThreeToThree_avg.printPuzzle();
	ThreeToThree_avg.solve();
	
	NPuzzleSolver ThreeToThree_hard("1-2-0-3-6-4-5-7-8");
	ThreeToThree_hard.printPuzzle();
	ThreeToThree_hard.solve();
	
	NPuzzleSolver ThreeToThree_very_hard("4-6-7-3-2-1-5-0-8");
	ThreeToThree_very_hard.printPuzzle();
	ThreeToThree_very_hard.solve();
	
	NPuzzleSolver ThreeToThree_impossible("1-2-3-4-5-6-8-7-0");
	ThreeToThree_impossible.printPuzzle();
	ThreeToThree_impossible.solve();
	
	NPuzzleSolver FourToFour("2-10-4-0-1-6-3-7-5-14-12-8-9-13-11-15");
	FourToFour.printPuzzle();
	FourToFour.solve();
	
	NPuzzleSolver FiveToFive("1-2-4-5-10-6-7-3-14-9-0-11-12-8-15-16-17-13-18-20-21-22-23-19-24");
	FiveToFive.printPuzzle();
	FiveToFive.solve();
	
	return 0;
}
