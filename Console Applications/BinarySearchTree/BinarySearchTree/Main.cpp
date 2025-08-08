// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BinarySearchTree.h"
#include <iostream>
void runProgram() {

    TreeNode* root = new TreeNode();
	BinarySearchTree* object = new BinarySearchTree();

    int option, val;

    do {
        std::cout << "\nBinary Search Tree Data System\n";
        std::cout << "1.Insert Node\n";
        std::cout << "2.Search Node\n";
        std::cout << "3.Delete Node\n";
        std::cout << "4.Print Node\n";
        std::cout << "5.Clear Screen\n";
        std::cout << "0.Exit Program\n";

        std::cin >> option;

        switch (option) {

        case 1:
            std::cout << "INSERT" << std::endl;
            std::cout << "Enter VALUE of TREE NODE to INSERT in BST:";
            //Insertion 
            std::cin >> val;
            object->insertNode(root, val);
            break;
        case 2:
            std::cout << "SEARCH" << std::endl;
            //Search for node
            object->searchNode(root, val);
            break;
        case 3:
            std::cout << "DELETE" << std::endl;
            std::cout << "Enter VALUE of TREE NODE to delete from BST:";
            //Delete node from tree
            std::cin >> val;
            root = object->deleteNode(root,val);
            break;
        case 4:
            val = 0;
            system("cls");
            std::cout << "PRINT" << std::endl;
            //PRINT
            object->printNode(root,val);
            break;
        case 5:
            std::cout << "CLR SCR" << std::endl;
            system("cls");
            //clear screen
            break;
        case 0:
            delete object;
            std::cout << "System Shutdown Complete" << std::endl;
            std::cin.get();
            break;
        }

    } while (option != 0);
}

int main() {
	
	runProgram();
	return 0;
}