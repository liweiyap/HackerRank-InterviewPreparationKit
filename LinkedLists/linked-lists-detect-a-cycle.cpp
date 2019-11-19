struct Node;

// IN: head of linked list
// OUT: boolean for whether linked list has cycle
bool has_cycle(Node* head) {
    // Floyd's cycle-finding algorithm: move slow walker by one and fast walker by two
    // Cycle exists if both walkers ever meet
    Node* slow_walker = head;
    Node* fast_walker = head;
    while (slow_walker && fast_walker && fast_walker->next){
        slow_walker = slow_walker->next;
        fast_walker = fast_walker->next->next;
        if (slow_walker == fast_walker){
            return true;
        }
    }
    return false;
}

struct Node{
    int data;
    struct Node* next;
}
