#include <iostream>

class SinglyLinkedListNode;

// IN: pointer to head node of linked list
// OUT: all values stored in linked list in order
void printLinkedList(SinglyLinkedListNode* head) {
    if (!head) return;

    SinglyLinkedListNode* node = head;
    while (node)
    {
        std::cout << node->data << "\n";
        node = node->next;
    }
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
