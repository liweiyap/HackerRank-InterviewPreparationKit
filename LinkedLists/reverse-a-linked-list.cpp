class SinglyLinkedListNode;

// IN: head of singly linked list
// OUT: head of reversed singly linked list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)
{
    if (!head) return head;
    if (!head->next) return head;

    SinglyLinkedListNode* old_head = head;
    SinglyLinkedListNode* next;
    while (old_head->next){
        next = old_head->next;
        old_head->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};
