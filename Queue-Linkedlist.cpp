#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front=NULL;
node *rear=NULL;

int main()
{
    int ch,x;
    node *temp;

    do{
        cout<<"\n1.Enqueue 2.Dequeue 3.Front 4.isEmpty 5.Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                temp=new node;
                cout<<"Enter value: ";
                cin>>x;

                temp->data=x;
                temp->next=NULL;

                if(front==NULL)
                {
                    front=rear=temp;
                }
                else
                {
                    rear->next=temp;
                    rear=temp;
                }
                break;

            case 2:
                if(front==NULL)
                    cout<<"Queue is Empty";
                else{
                    temp=front;
                    cout<<"Deleted: "<<front->data;
                    front=front->next;
                    delete temp;
                }
                break;

            case 3:
                if(front==NULL)
                    cout<<"Queue Empty";
                else
                    cout<<"Front element: "<<front->data;
                break;

            case 4:
                if(front==NULL)
                    cout<<"Queue is Empty";
                else
                    cout<<"Queue not Empty";
                break;
        }

    }while(ch!=5);

    return 0;
}
