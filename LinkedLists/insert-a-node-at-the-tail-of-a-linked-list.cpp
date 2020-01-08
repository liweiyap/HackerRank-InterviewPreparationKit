class SinglyLinkedListNode;

// IN: pointer to head node of linked list, data of new node to be inserted at the tail
// OUT: pointer to head node of amended linked list
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if (!head)
    {
        head = new SinglyLinkedListNode(data);
        return head;
    }
    
    SinglyLinkedListNode* node = head;
    while (node->next)
    {
        node = node->next;
    }
    node->next = new SinglyLinkedListNode(data);
    return head;
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
