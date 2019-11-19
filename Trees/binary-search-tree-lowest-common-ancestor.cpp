class Node;

// IN: pointer to root node of BST, values of nodes for which to find LCA
// OUT: LCA of both nodes indicated by values
Node* lca(Node* root, const int v1, const int v2){
    Node* node = root;
    
    // value of LCA must be between v1 and v2
    while (node){
        if (v1 < node->data && v2 < node->data && node->left){
            node = node->left;
        } else if (v1 > node->data && v2 > node->data && node->right){
            node = node->right;
        } else{
            return node;
        }
    }
    
    return node;
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
