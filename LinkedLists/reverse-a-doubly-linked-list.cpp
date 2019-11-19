class DoublyLinkedListNode;

// IN: head of doubly linked list
// OUT: head of reversed doubly linked list
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (!head) return head;
    if (!head->next) return head;
    
    DoublyLinkedListNode* node = head;
    DoublyLinkedListNode* old_prev;
    while (node){
        old_prev = node->prev;
        node->prev = node->next;
        node->next = old_prev;
        node = node->prev;
    }
    return old_prev->prev;
}

class DoublyLinkedListNode{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
    
    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
