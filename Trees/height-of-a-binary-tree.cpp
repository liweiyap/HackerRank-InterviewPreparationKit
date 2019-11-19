class Node;

// IN: pointer to root node of BST
// OUT: height of BST
int height(Node* root) {
    if (root == NULL) return 0;
    int hL = -1; int hR = -1;
    if (root->left) hL = height(root->left);
    if (root->right) hR = height(root->right);
    return std::max(hL, hR) + 1;
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
