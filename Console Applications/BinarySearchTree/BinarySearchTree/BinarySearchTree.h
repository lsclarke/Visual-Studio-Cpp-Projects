#ifndef _BINARYSEARCHTREE_HPP_
#define _BINARYSEARCHTREE_HPP_
#include "TreeNode.h"
#include <iostream>
#include <string>


class BinarySearchTree {

public:
    BinarySearchTree();
    ~BinarySearchTree();

    int _id {0};

    // Responsible for creating new Nodes within the binary tree
    TreeNode* createNode(int value);

    // Responsible for creating new Nodes within the binary tree
    TreeNode* insertNode(TreeNode* newTreeNode, int value);

    // Responsible for finding specific Node within the binary tree
    TreeNode* findNodeInTree(TreeNode* newTreeNode, int key);

    TreeNode* minValueNode(TreeNode* node);

    // Calls on findNodeInTree function to search for node in tree
    void searchNode(TreeNode* r, int val);

    // Calls on findNodeInTree function to search for node in tree
    TreeNode* deleteNode(TreeNode* r, int value);

    // Function to preorder traversal of BST
    void preorderTraversal(TreeNode* r);

    // Function to do inorder traversal of BST
    void inorderTraversal(TreeNode* r);

    // Function to do inorder traversal of BST
    void postorderTraversal(TreeNode* r);

    // Calls on print nodes to choose from in selection menu
    void printNode(TreeNode* r, int val);

};

#endif

