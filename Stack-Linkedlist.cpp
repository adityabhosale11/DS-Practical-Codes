#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

int main()
{
    int ch, x;
    node *temp;

    do{
        cout<<"\n1.Push 2.Pop 3.Peek 4.isEmpty 5.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1: // Push
                temp = new node;
                cout<<"Enter value: ";
                cin>>x;

                temp->data = x;
                temp->next = top;
                top = temp;
                break;

            case 2: // Pop
                if(top == NULL)
                    cout<<"Stack is Empty";
                else{
                    temp = top;
                    cout<<"Deleted: "<<top->data;
                    top = top->next;
                    delete temp;
                }
                break;

            case 3: // Peek
                if(top == NULL)
                    cout<<"Stack is Empty";
                else
                    cout<<"Top element: "<<top->data;
                break;

            case 4: // isEmpty
                if(top == NULL)
                    cout<<"Stack is Empty";
                else
                    cout<<"Stack is not Empty";
                break;
        }

    }while(ch != 5);

    return 0;
}
