/**
 * @name Aditi Verma
 *       ASSIGNMENT 7 - Chapter 21
 * @date 5/8/24
 */

#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

BinaryTree::BinaryTree()
{
    root = nullptr;
}

/** Destructor
 *  Deletes all sub tree
 */
BinaryTree::~BinaryTree()
{
    clearTree(root);
}

void BinaryTree::clearTree(TreeNode* temp)
{
    if(temp)
    {
        if(temp->left)
        {
            clearTree(temp->left);
        }
        if(temp->right)
        {
            clearTree(temp->right);
        }
        delete temp;
    }
}
void BinaryTree::insertNode(int num)
{
    TreeNode* newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}

void BinaryTree::insert(TreeNode* &temp, TreeNode* &newNode)
{
    if(temp == nullptr)
    {
        temp = newNode;
    }
    else if(newNode->value < temp->value)
    {
        insert(temp->left, newNode);
    }
    else
    {
        insert(temp->right, newNode);
    }
}

void BinaryTree::display(TreeNode* temp)
{
    if(temp)
    {
        display(temp->left);
        cout<<temp->value<<endl;
        display(temp->right);
    }
}

void BinaryTree::displayInOrder()
{
    display(root);
}