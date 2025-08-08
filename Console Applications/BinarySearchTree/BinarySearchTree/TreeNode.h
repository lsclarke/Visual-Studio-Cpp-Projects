#ifndef _TREENODE_HPP_
#define _TREENODE_HPP_
#include <iostream>
#include <string>

class TreeNode {

public:

	/// <summary>
	/// This is the structure for creating nodes
	/// </summary>
	int value;
	TreeNode* left;
	TreeNode* right;

	//returns node values
	int getValue(int newValue);
};

#endif

