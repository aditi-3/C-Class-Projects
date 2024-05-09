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
            int value;
            TreeNode *left;
            TreeNode* right;
        };

        TreeNode* root;

        //Private member functions
        void clearTree(TreeNode*); 
        void insert(TreeNode *&, TreeNode *&); 
        void display(TreeNode* &); 
        void leaf(TreeNode *&, int &); 
        int height(TreeNode *); 
        int width(TreeNode *, int);

    public:
        //Constructor
        BinaryTree();
        //Destructor
        ~BinaryTree();
        
        //Public member functions
        void insertNode(int); 
        void displayInOrder(); 
        int leafCount(); 
        int treeHeight(); 
        int treeWidth();
}; 
#endif;