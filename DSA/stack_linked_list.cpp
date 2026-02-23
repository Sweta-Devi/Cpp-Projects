//Stack implemented using linked list
#include<iostream>
using namespace std;

class Stack {
    private:
        struct Node{    //Node Structure
            int data;
            Node *next = NULL;
        };
        Node *top = NULL;
        int count, val; 

    public:
        Stack(){
            top = NULL;
            count = 0;
        }

        void push(int val){
            Node *temp = new Node();    /*allocate memory while top is actually used 
                                        to store the size of stack */
            if(temp == NULL){   
                cout<<"Stack Overflowww!!!!!\n";
                return;
            }

            temp->data = val;
            temp->next = top;
            top = temp;
            count++;
        }

        int pop(){
            Node *q = top;

            if(top == NULL){
                cout<<"Empty List!!!\n";
                return -1;
            }
              
            top = top->next;      //say stack have 4 element, so now top holds 3
            int val = q->data;
            count--;        //decrement count to make it 3 from 4
            delete q;
            return val;

        }

        int peek(){
            if(top == NULL){
                cout<<"Empty List!!!\n";
                return -1;
            }
        return top->data;
    }

    void display(){
        Node *q = top;
        cout<<top->data<<"\t<-\tTOP"<<endl;
        q = q->next;
        while(q != NULL){
            cout<<q->data<<"\n";
            q = q->next;
        }
    }

    bool isEmpty(){ return top == NULL; }
    int size() {          //Size of the stack
        return count;
    }
};

int main(){
    Stack s;
    int ch, data;

    do{
        cout<<"\tMENU\n\n";
        cout<<"1. Push\n2. Pop\n3. Size of stack\n4. Exit\n\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
        case 1: cout<<"\nEnter the Element : ";
                cin>>data;
                s.push(data);
                break;

        case 2: cout<<"\nPopping element:- \n\n";
                s.pop();
                s.display();
                break;

        case 3: cout<<"\nDisplaying the Stack:-\n";
                s.display();
                break;

        case 4: cout<<"\nSize of the stack is : "<<s.size()<<endl;
                break;

        case 5: exit(1);
        default: cout<<"Errorr!!!"; break;
        }
    }while(1);

     return 0;
}

    