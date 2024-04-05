/**
 * @name Aditi Verma
 *       ASSIGNMENT 4 - Chapter 18
 * @date 4/4/24
 */

#include <iostream>
#ifndef BEADLIST_H
#define BEADLIST_H
using namespace std;

class BeadList 
{
    private:
        struct ListNode
        {
            string value;
            struct ListNode *next;
        };

        ListNode *head;

    public:
        BeadList()
        {
            head = nullptr;
        }

        ~BeadList(); //DELETE EVERY NODE

        //linked list operations
        void appendNode(string);
        int insertNode(string, int);
        int deleteNode(string, int);
        void displayList() const;
        int searchNode(string);
        void checkNode(string);
}; 
#endif