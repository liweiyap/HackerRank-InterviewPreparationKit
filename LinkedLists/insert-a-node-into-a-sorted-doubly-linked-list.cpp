class DoublyLinkedListNode;

// IN: head of doubly linked list, data to be inserted
// OUT: new head of doubly linked list
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data){
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);
    
    // edge case: empty list
    if (!head){
        head = new_node;
        return head;
    }
    
    // edge case: insert data at the front of the doubly linked list
    if (data < head->data){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }
    
    // normal case: insert data in the middle of the doubly linked list
    // start walking from head
    DoublyLinkedListNode* walk = head;
    DoublyLinkedListNode* old_prev;
    while (walk && data > walk->data){
        old_prev = walk;
        walk = walk->next;
    }
    // once correct position has been walked up to, insert
    if (walk){
        walk->prev = new_node;
        new_node->next = walk;
        new_node->prev = old_prev;
        old_prev->next = new_node;
    } else{
        old_prev->next = new_node;
        new_node->prev = old_prev;
    }
    return head;
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
