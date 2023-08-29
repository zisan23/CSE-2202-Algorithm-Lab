#include <bits/stdc++.h>
using namespace std;

class stacknode{
public:
    int data;
    stacknode *next;

    stacknode(int value){
        data = value;
        next = NULL;
    }
};

class Stack{
private:
    int size = 0;
public:
    stacknode *top = NULL;
    void push(int value){
        stacknode *new_node = new stacknode(value);
        new_node->next = top;
        top = new_node;
        size++;
    }

    void pop(){
        if(top == NULL){
            printf("Empty Stack!!!");
            return;
        }

        stacknode *temp = top;
        top = top->next;
        free(temp);
        size--;
    }

    int peek(){
        return top->data;
    }

    bool empty(){
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int Size(){
        return size;
    }

    void clear(){
        stacknode *temp = top;
        top = NULL;

        while(temp != NULL){
            //pop();
            stacknode *temp2 = temp;
            temp = temp2->next;
            free(temp2);
        }
        size = 0;
    }

    bool search(int value){
        stacknode *temp = top;

        while(temp != NULL){
            if(temp->data == value){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int Search(int value){
        stacknode *temp = top;
        int count = 0;
        int flag = 0;

        while(temp != NULL){
            count++;
            if(temp->data == value){
                flag = 1;
                return count;
            }
            temp = temp->next;
        }
        if(flag == 0){
            return -1;
        }
    }

    void display(){
        stacknode *temp = top;

        if(temp == NULL){
            cout << "Empty Stack" << endl;
            return;
        }

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};