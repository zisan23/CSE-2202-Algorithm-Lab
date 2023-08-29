#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        height = -1;
    }

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL_Tree
{
public:
    Node *root;

    AVL_Tree()
    {
        root = NULL;
    }

private:

    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return node->height;
    }
    
    int BalanceFactor(Node *node) //balance factor is required to check the differece between height in left child and right child
    {
        if (node == NULL)
        {
            return 0;
        }

        return (getHeight(node->left) - getHeight(node->right));
    }



    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *t = x->right;

        x->right = y;
        y->left = t;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;  // re-assigning the height of the node I have rotated
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *t = y->left;

        y->left = x;
        x->right = t;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return y;
    }

    Node *insert(Node *parent, int val)
    {
        if (parent == NULL)
        {
            parent = new Node(val);
            return parent;
        }

        if (val < parent->data)
        {
            parent->left = insert(parent->left, val);
        }
        else if (val > parent->data)
        {
            parent->right = insert(parent->right, val);
        }
        else{
            return parent;
        }

        parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;

        int bf = BalanceFactor(parent);

        // left-left case
        if (bf > 1 && val < (parent->left->data))
        {
            return parent = rightRotate(parent);
        }

        // left-right case
        if (bf > 1 && val > (parent->left->data))
        {
            parent->left = leftRotate(parent->left);
            return parent = rightRotate(parent);
        }

        // right-right case
        if (bf < -1 && val > (parent->right->data))
        {
            return parent = leftRotate(parent);
        }

        // right-left case
        if (bf < -1 && val < (parent->right->data))
        {
            parent->right = rightRotate(parent->right);
            return parent = leftRotate(parent);
        }

        return parent;
    }

    Node *remove(Node *node, int x)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (x < node->data)
        {
            node->left = remove(node->left, x);
        }
        else if (x > node->data)
        {
            node->right = remove(node->right, x);
        }
        else
        {

            if (node->left == NULL && node->right == NULL)
            {
                free(node);
                return NULL;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                Node *temp = node->left;
                free(node);
                return temp;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                Node *temp = node->right;
                free(node);
                return temp;
            }

            Node *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int bf = BalanceFactor(node);

        // left-left case
        if (bf > 1 && BalanceFactor(node->left) > 0)
        {
            return node = rightRotate(node);
        }

        // left-right case
        if (bf > 1 && BalanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return node = rightRotate(node);
        }

        // right-right case
        if (bf < -1 and BalanceFactor(node->right) < 0)
        {
            return node = leftRotate(node);
        }

        // right-left case
        if (bf < -1 and BalanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return node = leftRotate(node);
        }

        return node;
    }

    void PreOrder(Node* curr_node){
        if(curr_node==NULL){
            return;
        }
        cout<<curr_node->data<<" ";
        PreOrder(curr_node->left);
        PreOrder(curr_node->right);
    }


    void InOrder(Node* curr_node){

        if(curr_node==NULL){
            return;
        }
        InOrder(curr_node->left);

        cout<<curr_node->data<<" ";
        InOrder(curr_node->right);
    }


    void PostOrder(Node* curr_node){
        if(curr_node==NULL){
            return;
        }
        PostOrder(curr_node->left);
        PostOrder(curr_node->right);

        cout<<curr_node->data<<" ";
    }

    int p_height(Node* node){

        if(node == NULL){
            return 0;
        }

        int left_subtree_depth = p_height(node->left);
        int right_subtree_depth = p_height(node->right);

        if(left_subtree_depth >= right_subtree_depth){
            return left_subtree_depth + 1;
        }
        else{
            return right_subtree_depth + 1;
        }
    }
    void printGivenLevel(Node* node, int level){
        if(node==NULL){
            return;
        }
        if(level==1){
            cout<<node->data<<" ";
            return;
        }
        else if(level > 1){
            printGivenLevel(node->left,level-1);
            printGivenLevel(node->right,level-1);
        }
    }

public:
    
    

    void insert(int val)
    {
        root=insert(root,val);
    }

    
    void deleteNode(int val)
    {
        root=remove(root,val);
    }
    

    Node *findMinNode(Node *parent)
    {
        Node *curr = parent;

        while (curr->left != NULL)
        {
            curr = curr->left;
        }

        return curr;
    }



    void printPreOrder(){//prints in order of the input provided - hence used to copy the tree
        PreOrder(root);
    }

    void printInOrder(){//prints nodes in non-decreasing order
        InOrder(root);
    }

    void printPostOrder(){//prints in reverse order of the input provided - hence used to delete the tree
        PostOrder(root);
    }

    int height_of_the_tree(){
        return p_height(root);
    }

    void printTheLevel(int level){
        printGivenLevel(root,level);
    }

};

int main(){
    AVL_Tree at = AVL_Tree();

    at.insert(9);
    at.insert(5);
    at.insert(10);
    at.insert(0);
    at.insert(6);
    at.insert(11);
    at.insert(-1);
    at.insert(1);
    at.insert(2);

    for(int i=0; i<at.height_of_the_tree(); i++){
        at.printTheLevel(i);
        cout << endl;
    }

    return 0;
}
