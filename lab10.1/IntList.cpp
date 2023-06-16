#include "IntList.h"

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } 
   else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

void IntList::swapHeadAndTail() {
   // TODO: Implement me
   if(head == nullptr || head->next == nullptr)
   {
      return;
   }
   IntNode *currNode = head;
   IntNode* previousNode = nullptr;
   while(currNode->next != nullptr)
   {
      previousNode = currNode;
      currNode = currNode->next;
   }
   IntNode* tail = currNode;
   tail->next = head->next;
   head->next = nullptr;
   previousNode->next = head;
   swap(head, tail);
}
