#include "PathNode.h"
#include <iostream>
#include <set>


typedef enum {
	LEFT = 'L',
	RIGHT = 'R',
	UP = 'U',
	DOWN = 'D'
} Directions;


void PathNode::createSubtree() {
	static std::set<char> moves = {LEFT, RIGHT, UP, DOWN};
	for(auto i = moves.begin(); i != moves.end(); i++)
		childNodeList.emplace(*i, PathNode());
}


void PathNode::addLevel() {
	if(childNodeList.empty()) {
		createSubtree();
		return;
	}
	for(auto i = childNodeList.begin(); i != childNodeList.end(); i++)
		i->second.addLevel();
}


void PathNode::clearLastLevel() {
	if(childNodeList.begin()->second.childNodeList.empty()) {
		childNodeList.clear();
		return;
	}
	for(auto i = childNodeList.begin(); i != childNodeList.end(); i++)
		i->second.clearLastLevel();
}


void PathNode::clearTree() {
	childNodeList.clear();
}


bool PathNode::checkSolution(const std::string &path, const std::vector<unsigned short> &puzzleBoard) {
	for(size_t i = 0; i < puzzleBoard.size() - 1; i++)
		if(puzzleBoard[i] != i + 1)
			return false;
	std::cout << std::endl << "Solution:  " << path << std::endl << std::endl << std::endl;
	return true;
}


bool PathNode::checkAllPaths(std::string &path, std::vector<unsigned short> &puzzleBoard, const unsigned short &boardSize, unsigned short &emptySlotIndex) {
	for(auto i = childNodeList.begin(); i != childNodeList.end(); i++) {
		unsigned short changedElementIndex;
		switch(i->first) {
			case LEFT:
				if(!(emptySlotIndex % boardSize) || path.back() == RIGHT) {
					childNodeList.erase(i--);
					continue;
				}
				changedElementIndex = emptySlotIndex - 1;
				break;
			case RIGHT:
				if((emptySlotIndex % boardSize == boardSize - 1) || path.back() == LEFT) {
					childNodeList.erase(i--);
					continue;
				}
				changedElementIndex = emptySlotIndex + 1;
				break;
			case UP:
				if((emptySlotIndex < boardSize) || path.back() == DOWN) {
					childNodeList.erase(i--);
					continue;
				}
				changedElementIndex = emptySlotIndex - boardSize;
				break;
			case DOWN:
				if((emptySlotIndex >= puzzleBoard.size() - boardSize) || path.back() == UP) {
					childNodeList.erase(i--);
					continue;
				}
				changedElementIndex = emptySlotIndex + boardSize;
		}
		path.push_back(i->first);
		std::swap(puzzleBoard[emptySlotIndex], puzzleBoard[changedElementIndex]);
		std::swap(emptySlotIndex, changedElementIndex);
		if(checkSolution(path, puzzleBoard))
			return true;
		if(i->second.checkAllPaths(path, puzzleBoard, boardSize, emptySlotIndex))
			return true;
		std::swap(puzzleBoard[emptySlotIndex], puzzleBoard[changedElementIndex]);
		std::swap(emptySlotIndex, changedElementIndex);
		path.pop_back();
	}
	return false;
}
