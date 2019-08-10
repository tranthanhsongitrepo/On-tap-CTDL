#include <iostream>
using namespace std ;
struct Node{
    int key ;
    Node* left,* right ;
    Node(int  key){
        this->key = key;
    }
};
class BST{
    Node* root ;
    void postOrderUtil(Node *cur){
        if (cur->left != NULL)
            postOrderUtil(cur->left) ;
        cout << cur->key << " " ;
        if (cur->right != NULL)
            postOrderUtil(cur->right) ;
    }

    void preOrderUtil(Node *cur){
        cout << cur->key << " " ;
        if (cur->left != NULL)
            preOrderUtil(cur->left) ;
        if (cur->right != NULL)
            preOrderUtil(cur->right) ;

    }

    void InOrderUtil(Node *cur){
        if (cur->left != NULL)
            preOrderUtil(cur->left) ;
        if (cur->right != NULL)
            preOrderUtil(cur->right) ;
        cout << cur->key << " " ;
    }
public:
    BST(){
        root = NULL ;
    }
    void addNode(int key){
        if (root == NULL){
            root = new Node(key) ;
        }
        else {
            Node* it = root ;
            while (it->left != NULL && it->right != NULL) {
                if (it->key < key){
                    it = it->right;
                }
                else{
                    it = it->left ;
                }
            }
            if (key > it->key)
                it->right = new Node(key) ;
            else
                it->left = new Node(key) ;
        }
    }
    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }
    Node* removeNodeUtil(Node *n, int key) {
        if (n == NULL)
            return NULL ;
        if (key < n->key)
            n->left = removeNodeUtil(n->left, key) ;
        else if (key > n->key)
            n->right = removeNodeUtil(n->right, key);
        else {
            if (n->left == NULL)
            {
                Node* temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == NULL)
            {
                Node* temp = n->left;
                delete n;
                return temp;
            }
            Node* temp = minValueNode(n->right);
            n->key = temp->key;
            n->right = removeNodeUtil(n->right, temp->key);
        }
        return n;
    }
    void removeNode(int x){
        removeNodeUtil(root, x) ;
    }
    void preOrder(){
        preOrderUtil(root) ;
        cout << endl ;
    }

    void postOrder(){
        postOrderUtil(root) ;
        cout << endl ;
    }

    void inOrder(){
        InOrderUtil(root) ;
        cout << endl ;
    }
};
int main() {
    BST t ;
    int q ;
    while (cin >> q){
        switch (q) {
            case 1 :
                int x;
                cin >> x;
                t.addNode(x);
                break;
            case 2 :
                cin >> x;
                t.removeNode(x);
                break;
            case 3 :
                t.preOrder() ;
                break ;
            case 4 :
                t.inOrder() ;
                break ;
            case 5 :
                t.postOrder() ;
                break ;
        }


    }
    return 0;
}