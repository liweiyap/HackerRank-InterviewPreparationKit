#include <iostream>

class SinglyLinkedListNode;

// IN: pointer to head node of linked list
// OUT: print all values stored in linked list backwards (from tail to head)
void reversePrint(SinglyLinkedListNode* head) {
    if (!head) return;
    reversePrint(head->next);
    std::cout << head->data << "\n";
}

class SinglyLinkedListNode{
public:
    int data;
    SinglyLinkedListNode* next;
    
    SinglyLinkedListNode(int node_data){
        this->data = node_data;
        this->next = nullptr;
    }
};
