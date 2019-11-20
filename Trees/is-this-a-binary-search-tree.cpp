class Node;

// IN: pointer to any node
// OUT: check if sub-tree rooted at that node is valid
bool checkBST(Node* root){
    return checkHelper(root, INT_MIN, INT_MAX);
}

// IN: pointer to any node, range (indicated by min and max) in which value of node must lie
// OUT: helper function to check if value of all nodes in sub-tree rooted at node lie in the correct range
bool checkHelper(Node* node, int min, int max){
    if(!node){
        return true;
    }
    
    if(node->data <= min || node->data >= max){
        return false;
    }
        
    return checkHelper(node->left, min, node->data) && checkHelper(node->right, node->data, max);
}

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
