#ifndef PATH_NODE_H
#define PATH_NODE_H

#include <map>
#include <string>
#include <vector>


// PathNode class declaration.
class PathNode {
private:
	std::map<char, PathNode> childNodeList;
	void createSubtree();
	static bool checkSolution(const std::string &path, const std::vector<unsigned short> &puzzleBoard);
public:
	void addLevel();
	void clearLastLevel();
	void clearTree();
	bool checkAllPaths(std::string &path, std::vector<unsigned short> &puzzleBoard, const unsigned short &boardSize, unsigned short &emptySlotIndex);
};

#endif		// PATH_NODE_H
