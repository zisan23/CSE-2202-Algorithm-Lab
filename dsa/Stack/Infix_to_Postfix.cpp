#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = NULL;
    }
};

class Stack{
private:
    int size = 0;
public:
    node *top = NULL;
    void push(int value){
        node *new_node = new node(value);
        new_node->next = top;
        top = new_node;
        size++;
    }

    void pop(){
        if(top == NULL){
            printf("Empty Stack!!!");
            return;
        }

        node *temp = top;
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
        node *temp = top;
        top = NULL;

        while(temp != NULL){
            //pop();
            node *temp2 = temp;
            temp = temp2->next;
            free(temp2);
        }
        size = 0;
    }

    bool search(int value){
        node *temp = top;

        while(temp != NULL){
            if(temp->data == value){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    int Search(int value){
        node *temp = top;
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
        node *temp = top;

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

int precedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else return -1;
}

string infix_to_postfix(string s){
    stack<char> st;
    string result;

    for(int i=0; i<s.length(); i++){
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        }
        else if(c == '('){
            st.push('(');
        }
        else if(c == ')'){
            while(st.top() != '(' ){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){
    string s;
    cin >> s;

    string result = infix_to_postfix(s);

    cout << result << endl;

    return 0;
}
