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

/** Clear Tree [Private]
 * Erases all nodes in a given binary tree, used in deconstructor
 * @param  {TreeNode*} temp 
 */
void BinaryTree::clearTree(TreeNode *temp)
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

/** Insert [Private]
 * Inserts new node using recursion
 * @param  {TreeNode*} temp, {TreeNode*} newNode
 */
void BinaryTree::insert(TreeNode *&temp, TreeNode *&newNode)
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

/** Insert Node [Public]
 * Public implementation of insert() function in BinaryTree class
 * Function creates a new node using the parameter and calls insert function
 * @param  {int} num : 
 */
void BinaryTree::insertNode(int num)
{
    TreeNode* newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}

/** Display [Private]
 * Prints out all the nodes in order using recursion
 * @param  {TreeNode*} temp : 
 */
void BinaryTree::display(TreeNode *&temp)
{
    if(temp)
    {
        display(temp->left);
        cout<<temp->value<<" ";
        display(temp->right);
    }
}

/** Display In Order [Public]
 * Public implementation of display() function
 */
void BinaryTree::displayInOrder()
{
    display(root);
}

/** Leaf [Private]
 * Calculates the number of leafs in a tree using recursion
 * @param  {TreeNode*} temp, {int} count 
 */
void BinaryTree::leaf(TreeNode *&temp, int &count)
{
    if(temp == NULL)
    {
        return;
    }
    if(temp->left == NULL && temp->right == NULL)
    {
        count++;
    }
    leaf(temp->left, count);
    leaf(temp->right, count);
}

/** Leaf Count [Public]
 * public implementation of the private leaf() function
 * @return {int}  : 
 */
int BinaryTree::leafCount()
{
    int c = 0;
    leaf(root, c);
    return c;
}

/** Height [Private]
 * Calculates maximum height of a tree using recursion
 * @param  {TreeNode*} temp
 * @return {int}           
 */
int BinaryTree::height(TreeNode *temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    int left = height(temp->left);
    int right = height(temp->right);
    return max(left, right) + 1;
}

/** Tree Height [Public]
 * Calls the private height() function
 * @return {int}  
 */
int BinaryTree::treeHeight()
{
    return height(root);
}

/** Width [Private]
 * Calculates width of a given level
 * @param  {TreeNode*} temp, {int} w
 * @return {int}
 */
int BinaryTree::width(TreeNode *temp, int lvl)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(lvl == 1)
    {
        return 1;
    }
    else if(lvl > 1)
    {
        int left = width(temp->left, lvl - 1);
        int right =  width(temp->right, lvl - 1);
        return left + right;
    }
}

/** Tree Width [Public]
 * Returns the maximum tree width using private width() function in BinaryTree class
 * @return {int} 
 */
int BinaryTree::treeWidth()
{
    int maxWidth = 0;
    int currWidth; 
    int h = height(root);
    for (int i = 1; i <= h; i++) 
    {
        currWidth = width(root, i);
        if (currWidth > maxWidth)
        {
            maxWidth = currWidth;
        } 
    }
    return maxWidth;
}