// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BinarySearchTree.h"
#include <iostream>


BinarySearchTree::BinarySearchTree() 
{ 
	_id++;

	std::cout << "Binary Search Tree [ID#"<< _id << "] Active" << std::endl;
}


BinarySearchTree::~BinarySearchTree()
{
	std::cout << "Binary Search Tree [ID#" << _id << "] Deactive" << std::endl;
	_id--;
}

TreeNode* BinarySearchTree::createNode(int value) {
    TreeNode* newTreeNode = new TreeNode;
    newTreeNode->value = value;
    newTreeNode->left = newTreeNode->right = nullptr;
    return newTreeNode;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* newTreeNode, int value) {

    if (newTreeNode == nullptr) {
        newTreeNode = createNode(value);
        std::cout << value << " Inserted into root!" << std::endl;
    }
    else {
        if (newTreeNode->value == value) {
            std::cout << value << " Value already inserted!" << std::endl;
        }

        if (value > newTreeNode->value) {
            newTreeNode->right = insertNode(newTreeNode->right, value);
        }
        else if (value < newTreeNode->value) {
            newTreeNode->left = insertNode(newTreeNode->left, value);
        }
    }
    return newTreeNode;
}

TreeNode* BinarySearchTree::findNodeInTree(TreeNode* newTreeNode, int key) {

    if ((key == newTreeNode->value) || (newTreeNode == nullptr)) {
        return newTreeNode;
    }

    if (newTreeNode->value < key) {
        return findNodeInTree(newTreeNode->right, key);
    }

    return findNodeInTree(newTreeNode->left, key);
}

TreeNode* BinarySearchTree::minValueNode(TreeNode* node)
{
    TreeNode* currentNode = node;
    while (currentNode && currentNode->left != nullptr) {
        currentNode = currentNode->left;
    }
    return currentNode;
}

void BinarySearchTree::searchNode(TreeNode* r, int val) {
    system("cls");
    std::cout << "Enter a VALUE to search for in the Node Tree\n";
    std::cin >> val;
    //PRINT
    if (val > 0) {
        TreeNode* foundNode = findNodeInTree(r, val);

        if (foundNode == nullptr) {
            std::cout << val << "found in the Node Tree\n";
        }
        else {
            std::cout << val << "not found in the Node Tree\n";
        }
    }
    else {
        return;
    }
}

TreeNode* BinarySearchTree::deleteNode(TreeNode* r, int value)
{
    if (r == nullptr)
        return r;

    if (value < r->value) {
        return r = deleteNode(r->left, value);
    }

    if (value > r->value) {
        return r = deleteNode(r->right, value);
    }
    else {

        if (r->left == nullptr) {
            TreeNode* temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == nullptr) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
        }

        TreeNode* temp = minValueNode(r->right);

        r->value = temp->value;

        r->right = deleteNode(r->right, temp->value);
    }
}

void BinarySearchTree::preorderTraversal(TreeNode* r) {

    if (r != nullptr)
    {
        std::cout << r->value << " ";
        preorderTraversal(r->left);
        preorderTraversal(r->right);
    }
}

void BinarySearchTree::inorderTraversal(TreeNode* r) {

    if (r != nullptr)
    {
        inorderTraversal(r->left);
        std::cout << r->value << " ";
        inorderTraversal(r->right);
    }
}

void BinarySearchTree::postorderTraversal(TreeNode* r) {

    if (r != nullptr)
    {
        postorderTraversal(r->left);
        postorderTraversal(r->right);
        std::cout << r->value << " ";
    }
}

void BinarySearchTree::printNode(TreeNode* r, int val) {
    std::cout << "Enter a VALUE to choose the order print method\n";
    std::cout << "1.PreOrder Print\n";
    std::cout << "2.InOrder Print\n";
    std::cout << "3.PostOrder Print\n";
    std::cin >> val;
    //PRINT
    switch (val) {
    case 1:
        preorderTraversal(r);
        break;
    case 2:
        inorderTraversal(r);
        break;
    case 3:
        postorderTraversal(r);
        break;

    }
}
