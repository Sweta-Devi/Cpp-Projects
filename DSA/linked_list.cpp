//Linked List
#include<iostream>
using namespace std;

class Linked{

    struct Node{    //Node Structure
        int data;
        Node *next;
    };
    Node *head;
    int count, val;

    public:
        Linked(){       //Empty list
            head = NULL;
            count = 0;
        }

        void beg_ins(){     //Insertion at beginning
            Node *temp = new Node();

            if(temp == NULL){
                cout<<"Overflow!!!!";
                return;
            }
            val = getdata();
            temp->data = val;
            temp->next = head;
            head = temp;
            count++;
        }

        void end_ins(){     //Insertion at the End
            Node *temp = new Node();
            Node *q = head;
            val = getdata();

            while(q->next != NULL)
                q = q->next;
            
            temp->data = val;
            q->next = temp;
            count++;
            
        }

        void loc_ins(){     //Insertion at particular location
            Node *temp = new Node();
            Node *q = head;

            if(temp == NULL){
                cout<<"Overflow!!!!";
                return;
            }

            int pos, i;
            cout<<"Enter the position : ";
            cin>>pos;
            

            if(pos == 1){
                beg_ins();
                return;
            }
            else if(pos > size()){
                cout<<"Error!!! Position is bigger than the size of element.\n";
                return;
            }
            else{
                val = getdata();
                for(i = 1; i < pos-1 && q != NULL; i++)     //pos = 3, q = 1
                    q = q->next;
                temp->data = val;       //q = 2
                temp->next = q->next;
                q->next = temp;
                count++;
                
            }
        }

        int getdata(){
            cout<<"Enter data : ";
            cin>>val;
            return val;
        }

        void beg_del(){     //Deletion at Beginning
            Node *q = head;

            if(head == NULL){
                cout<<"Empty list!!!!";
                return;
            }
            cout<<"Element being removed is "<<head->data<<endl;
            head = head->next;
            delete q;
        }

        void end_del(){     //Deletion at End
            Node *q = head;

            if(head == NULL){
                cout<<"Emptyy list!!!";
                return;
            }
            else{
                if(head->next == NULL){
                    cout<<"Only one node is there.\n";
                    delete head;
                    return;
                }
                while(q->next->next != NULL)
                    q = q->next;

                cout<<"Element being removed is "<<q->next->data<<endl;
                delete q->next->next;
                q->next = NULL;
            }

        }

        void loc_del(){
            Node *q = head, *n;

            if(head == NULL){
                cout<<"Emptyy list!!!";
                return;
            }
            else{
                int pos;
                cout<<"Enter the position : ";
                cin>>pos;

                for(int i = 1; i<pos-1; i++){
                    n = q;
                    q = q->next;
                }

                if(pos == 1)
                    beg_del();
                else if(pos > size()){
                    cout<<"Errorrr!!! Position is greater than number of nodes.\n";
                    return;
                }
                else{
                    cout<<"\nElement to be removed is : "<<q->data;
                    n = n->next;
                    delete q;
                }
            }
        }

        void display(){
            Node *q = head->next;
           cout<<"\nHead ->\t"<<head->data<<"\t";
            while(q != NULL){
                cout<<q->data<<"\t";
                q = q->next;
            }
            cout<<endl<<endl;
        }

        int size(){ return count; }

};

int main(){
    int val, ch;
    Linked l;

    do{
        cout<<"\n\tMENU\n\n";
        cout<<"1. Insertion at beginning\n2. Insertion at End\n3. Insertion at a partiular location\n4.  Deletion at beginning\n";
        cout<<"5. Deletion at the End\n6. Deletion at a particular location\n7. Reverse of the linked list\n";
        cout<<"8. Size of the linked list\n9. Display the linked list\n10. Exit\n\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1: cout<<"\nInserting at Beginning:-\n";
                    l.beg_ins();
                    break;

            case 2: cout<<"\nInserting at the End:-\n";
                    l.end_ins();
                    break;

            case 3: cout<<"Inserting at a particular location:- \n";
                    l.loc_ins();
                    break;

            case 4: cout<<"Deleting at Beginning:-\n";
                    l.beg_del();
                    break;

            case 5: cout<<"Deleting at End:-\n";
                    l.end_del();
                    break;

            case 8: cout<<"Total number of Nodes in Linked List is : "<<l.size()<<endl;
                    break;
        
            case 9: cout<<"\nDisplaying Linked Lits:- \n\n";
                    l.display();
                    break;
            case 10: exit(1);

        }

    }while(1);
}