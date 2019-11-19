class SinglyLinkedListNode;

// IN: head of linked list, data to be stored in new node, position at which to insert data
// OUT: new head of linked list
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position){
    // create new node storing data to be inserted
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    
    // edge case: if we want to insert node in front of current head and make it the new head
    if (position == 0){
        new_node->next = head;
        head = new_node;
        
    // main case: if we want to insert node in the middle of the linked list
    } else{
        // start at head and get node at position
        SinglyLinkedListNode* node = head;
        int idx = 0;
        while (idx < position - 1){
            node = node->next;
            ++idx;
        }
        
        // insert
        SinglyLinkedListNode* old_next = node->next;
        node->next = new_node;
        new_node->next = old_next;
    }
    
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
