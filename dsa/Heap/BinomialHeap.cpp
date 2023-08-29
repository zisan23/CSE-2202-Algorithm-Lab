#include "Stack.h"

class node{
public:
    
    int data;
    int degree;
    node* parent;
    node* rightchild;
    node* leftchild;

    node(int value){
        this->data = value;
        this->degree = 0;
        this->parent = nullptr;
        this->leftchild = nullptr;
        this->rightchild = nullptr;
    }
};

class BinomialHeap{
public:
    node* root;

    BinomialHeap(){
        root = nullptr;
    }

    node* minNode(){
        node* minimum = root;
        node* temp = root;

        while(temp != nullptr){
            if(temp->data < minimum->data){
                minimum = temp;
            }
            temp = temp->rightchild;
        }

        return minimum;
    }
    // int mindata(){
    //     return minNode()->data;
    // }

    node* merge(node* root1, node* root2){
        node* mergedroot = new node(0);
        node* temproot = mergedroot;

        while(root1 != nullptr and root2 != nullptr){
            if(root1->degree <= root2->degree){
                temproot->rightchild = root1;
                root1 = root1->rightchild;
            }
            else{
                temproot->rightchild = root2;
                root2 = root2->rightchild;
            }
            temproot = temproot->rightchild;
        }

        while(root1 != nullptr){
            temproot->rightchild = root1;
            root1 = root1->rightchild;
            temproot = temproot->rightchild;
        }
        while(root2 != nullptr){
            temproot->rightchild = root2;
            root2 = root2->rightchild;
            temproot = temproot->rightchild;
        }

        return mergedroot->rightchild;
    }

    void Union(BinomialHeap* heap2){
        node* root1 = this->root;
        node* root2 = heap2->root;

        node* mergedroot = merge(root1, root2);

        this->root = mergedroot;

        if(mergedroot == nullptr){
            printf("Empty Heap");
            return;
        }

        node* prev = nullptr;
        node* current = this->root;
        node* next = current->rightchild;

        while(next != nullptr){
            if(current->degree != next->degree){
                prev = current;
                current = next;
            }
            else if(next->rightchild != nullptr and next->rightchild->degree == current->degree){
                prev = current;
                current= next;
            }
            else if(current->data <= next->data){
                current->rightchild = next->rightchild;
                next->parent = current;
                next->rightchild = current->leftchild;
                current->leftchild = next;
                current->degree++;
            }
            else{
                if(prev == nullptr){
                    mergedroot = next;
                }
                else{
                    prev->rightchild = next;
                }

                current->parent = next;
                current->rightchild = next->leftchild;
                next->leftchild = current;
                current = next;
            }

            next = current->rightchild;
        }

        this->root = mergedroot;
    }

    void insert(int value){
        BinomialHeap* New = new BinomialHeap();
        New->root = new node(value);

        Union(New);
    }

    node *reverse(node *root1)
    {
        stack<node *> st;
        while (root1 != NULL)
        {
            st.push(root1);
            root1 = root1->rightchild;
        }
        if (st.empty())
        {
            return NULL;
        }
        node *newRoot = st.top();
        node *prev = newRoot;
        st.pop();
        while (!st.empty())
        {
            prev->rightchild = st.top();
            st.pop();
            prev = prev->rightchild;
        }
        prev->rightchild = NULL;
        return newRoot;
    }

    int ExtractMin(){
        node* current = root;
        node* prevMin = nullptr;
        node* min = nullptr;
        node* prev = nullptr;

        int Minimum = INT_MAX;

        if(current == nullptr){
            return INT_MIN;
        }

        while(current != nullptr){
            if(current->data <= Minimum){
                Minimum = current->data;
                prevMin = prev;
                min = current;
            }
            prev = current;
            current = current->rightchild;
        }

        if(prevMin != nullptr and min->rightchild != nullptr){
            prevMin->rightchild = min->rightchild;
        }
        else if(prevMin != nullptr and min->rightchild == nullptr){
            prevMin->rightchild = nullptr;
        }
        else if(prevMin == nullptr and min->rightchild != nullptr){
            root = min->rightchild;
        }
        else if(prevMin == nullptr and min->rightchild == nullptr){
            root = nullptr;
        }

        node* newptr = min->leftchild;

        while(newptr != nullptr){
            newptr->parent = nullptr;
            newptr = newptr->rightchild;
        }

        newptr = min->leftchild;
        node* newroot = reverse(newptr);

        BinomialHeap* newHeap = new BinomialHeap();

        newHeap->root = newroot;
        Union(newHeap);

        free(min);

        return Minimum;
    }

    void decreaseKey(node* n, int data){
        n->data = data;

        while(n->parent != nullptr and n->parent->data > n->data){
            swap(n->parent->data, n->data);
            n = n->parent;
        }
    }

    void deleteNode(node* n){
        decreaseKey(n, INT_MIN);
        ExtractMin();
    }

    //print the root list
    void print(){
        node* temp = root;

        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->rightchild;
        }
        cout << endl;
    }

    //print the whole heap
    void printTree(node* root){
        if(root == nullptr){
            return;
        }

        cout << root->data << " ";
        printTree(root->leftchild);
        printTree(root->rightchild);
    }
    void Print(){
        node* temp = root;
        printTree(temp);
        cout << endl;
    }
};

int main(){
    BinomialHeap bh = BinomialHeap();

    bh.insert(10);
    bh.insert(20);
    bh.insert(30);

    bh.Print();

    

    cout << bh.minNode()->data << endl;

    bh.Print();

    bh.ExtractMin();

    bh.Print();

    return 0;
}