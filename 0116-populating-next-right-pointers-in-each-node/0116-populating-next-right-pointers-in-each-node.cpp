/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    void recFind(Node* node,Node* par){
        if(!node) return ;
        if(!par) node->next = NULL;
        else if(par->right!=node) node->next = par->right;
        else if(par->next) node->next = par->next->left;
        else node->next = NULL;
        recFind(node->left,node);
        recFind(node->right,node);
    }

    Node* connect(Node* root) {
        if(!root) return root;
        recFind(root,NULL);
        return root;
    }
};