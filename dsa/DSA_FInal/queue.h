#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue_ll{
    node* root = NULL;
    node* last = NULL;
    int size = 0;

public:

    void enque(int data){

        node *new_node = new node(data);

        if(root == NULL){
            root = new_node;
            root->next = NULL;
            last = root;
            size++;
            return;
        }

        last->next = new_node;
        new_node->next = NULL;
        last = new_node;
        size++;
        return;
    }   

    void deque(){
        if(root == NULL){
            return;
        }

        node *temp = root;
        root = root->next;

        if(root == NULL){
            last->next = NULL;
            last = NULL;
            root = NULL;
        }

        free(temp);
        size--;
    }

    int peek_front(){
        if(last == NULL){
            return -1;
        }

        return root->data;
    }

    int peek_last(){
        if(last == NULL){
            return -1;
        }

        return last->data;
    }

    bool isEmpty(){
        return !root;
    }

    int Size(){
        if(root == NULL){
            return 0;
        }
        node* cur = root;
        int s = 0;

        while(cur != NULL){
            s++;
            cur = cur->next;
        }

        return s;

    }

    int size_2(){
        return size;

    }

    void display(){
        if(root == NULL){
            return;
        }

        node* temp = root;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};