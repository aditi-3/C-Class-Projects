/**
 * @name Aditi Verma
 *       ASSIGNMENT 7 - Chapter 21
 * @date 5/8/24
 */

#include <iostream>
#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

class BinaryTree
{
    private:
        struct TreeNode
        {
            string value;
            TreeNode *left;
            TreeNode* right;
        };

        TreeNode* root;

        //Private member functions
        void insert(TreeNode* &, TreeNode* &); //
        void clearTree(TreeNode*); //
        void display(TreeNode*); //

    public:
        //Constructor
        BinaryTree();
        //Destructor
        ~BinaryTree();

        void insertNode(int); //
        void displayInOrder(); //
        void leafCount();
        void treeHeight();
        void treeWidth();
}; 
#endif