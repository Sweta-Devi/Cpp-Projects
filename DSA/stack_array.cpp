//Stack using array
#include <iostream>
#define MAX 20
using namespace std;

class Stack {
    int *arr, top = -1, size;
    public:
        Stack(int n){
            arr = new int[n];
            size = n;    //Allocate a memory of size 'n'element
        }

        ~Stack() { delete[] arr; }  // Destructor to deallocate memory

        void push(int val){
            if(isFull()){
                cout<<"Overflow!!!\n";
                return;
            } 
            cout<<"\nPushing "<<val<<endl;
            arr[++top] = val; //first increment then assigning
        }

        int pop(){
            if(isEmpty()){
                cout<<"Underflow!!!!\n";
                return -1;
            }
            return arr[top--];   //removes and return the value
        }

        int peek(){
            if(!isEmpty())
                return arr[top];
            else
                return -1;
            
        }

        void display(){
            int i;

            if(!isEmpty() || !isFull()){
                cout<<"Stack is :-\n\n";

                cout<<arr[top]<<"\t<-\n";
                for(i=top-1; i>=0; i--){
                    cout<<arr[i]<<"\n";
                }
            cout<<endl;
        }
        else
            cout<<"Errorrr!!!!!\n";
    } 

        bool isFull(){ return top == MAX-1; }
        bool isEmpty(){ return top == -1; }
    
};

int main(){

    int n, val, ch;
    
    cout<<"Enter the size of array : ";
    cin>>n;
    Stack s(n);

    for(int i=0; i<n; i++){
        cout<<"\nEnter element : ";
        cin>>val;
        s.push(val);  
    } 
    
    s.display();

    while(!s.isEmpty()){
        cout<<"\n1. Pop element\n2. Display the top elemen\n3. Exit\n\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1: cout<<"\nPopping the top element "<<s.pop()<<endl;
                    cout<<"Stack after popping:-\n";
                    s.display();
                    break;

            case 2: cout<<"Displaying only the top element : "<<s.peek()<<endl;
                    break;
            
            case 3: exit(1);
        }   
    }
   
    return 0;
}