#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

void insert_begin(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;

    if(head != NULL)
        head->prev = temp;

    head = temp;
}

void insert_end(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
}

void insert_pos(int x,int pos)
{
    node *temp = new node;
    temp->data = x;

    node *ptr = head;

    for(int i=1;i<pos-1;i++)
        ptr = ptr->next;

    temp->next = ptr->next;
    temp->prev = ptr;

    if(ptr->next != NULL)
        ptr->next->prev = temp;

    ptr->next = temp;
}

void delete_begin()
{
    if(head == NULL)
    {
        cout<<"List Empty";
        return;
    }

    node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

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
    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = NULL;
    else
        head = NULL;

    cout<<"Deleted: "<<ptr->data;
    delete ptr;
}

void delete_pos(int pos)
{
    node *ptr = head;

    for(int i=1;i<pos;i++)
        ptr = ptr->next;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    cout<<"Deleted: "<<ptr->data;
    delete ptr;
}

void search(int key)
{
    node *ptr = head;
    int pos = 1;

    while(ptr != NULL)
    {
        if(ptr->data == key)
        {
            cout<<"Found at position "<<pos;
            return;
        }
        ptr = ptr->next;
        pos++;
    }

    cout<<"Not found";
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
        cout<<ptr->data<<" <-> ";
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
            case 1: cin>>x; insert_begin(x); break;
            case 2: cin>>x; insert_end(x); break;
            case 3: cin>>x>>pos; insert_pos(x,pos); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: cin>>pos; delete_pos(pos); break;
            case 7: cin>>x; search(x); break;
            case 8: display(); break;
        }

    }while(ch!=9);

    return 0;
}
