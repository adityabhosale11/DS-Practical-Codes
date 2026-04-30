#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void insert_begin(int x)
{
    node *temp = new node;

    temp->data = x;
    temp->next = head;

    head = temp;
}

void insert_end(int x)
{
    node *temp = new node;

    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    node *ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void insert_pos(int x,int pos)
{
    node *temp = new node;
    temp->data = x;

    node *ptr = head;

    for(int i=1;i<pos-1;i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_begin()
{
    if(head == NULL)
    {
        cout<<"List is Empty";
        return;
    }

    node *temp = head;

    head = head->next;

    cout<<"Deleted: "<<temp->data;

    delete temp;
}

void delete_end()
{
    if(head == NULL)
    {
        cout<<"List Empty";
        return;
    }

    node *ptr = head;
    node *prev;

    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;

    cout<<"Deleted: "<<ptr->data;

    delete ptr;
}

void delete_pos(int pos)
{
    node *ptr = head;
    node *temp;

    for(int i=1;i<pos-1;i++)
    {
        ptr = ptr->next;
    }

    temp = ptr->next;

    ptr->next = temp->next;

    cout<<"Deleted: "<<temp->data;

    delete temp;
}

void search(int key)
{
    node *ptr = head;
    int pos = 1;

    while(ptr != NULL)
    {
        if(ptr->data == key)
        {
            cout<<"Element found at position "<<pos;
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    cout<<"Element not found";
}

void display()
{
    node *ptr = head;

    if(ptr == NULL)
    {
        cout<<"List Empty";
        return;
    }

    while(ptr != NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }

    cout<<"NULL";
}

int main()
{
    int ch,x,pos;

    do
    {
        cout<<"\n1.Insert Beginning";
        cout<<"\n2.Insert End";
        cout<<"\n3.Insert Position";
        cout<<"\n4.Delete Beginning";
        cout<<"\n5.Delete End";
        cout<<"\n6.Delete Position";
        cout<<"\n7.Search";
        cout<<"\n8.Display";
        cout<<"\n9.Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>x;
                insert_begin(x);
                break;

            case 2:
                cout<<"Enter element: ";
                cin>>x;
                insert_end(x);
                break;

            case 3:
                cout<<"Enter element and position: ";
                cin>>x>>pos;
                insert_pos(x,pos);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                delete_pos(pos);
                break;

            case 7:
                cout<<"Enter element to search: ";
                cin>>x;
                search(x);
                break;

            case 8:
                display();
                break;

        }

    }while(ch!=9);

    return 0;
}
