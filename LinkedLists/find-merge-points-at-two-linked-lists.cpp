class SinglyLinkedListNode;

// IN: pointer to the respective head node of two linked lists that are guaranteed to merge at some point
// OUT: value stored at node
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2){
    // initialise two walker nodes to traverse either linked list
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
    
    // at each iteration, move both walker nodes by one
    // when walker node reaches the end of linked list and the merge node has not been found,
    // bring it to the head of the **other** linked list
    while (node1 != node2){
        if (node1->next){
            node1 = node1->next;
        } else{
            node1 = head2;
        }

        if (node2->next){
            node2 = node2->next;
        } else{
            node2 = head1;
        }
    }
    
    return node1->data;
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
