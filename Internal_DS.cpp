#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;


void insert()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node* newnode = new Node();
    newnode->data = value;


    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        Node* temp = head;

        
        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    cout << "Node Inserted\n";
}


void display()
{
    Node* temp = head;

    if(head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        cout << "Circular Linked List: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while(temp != head);

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 3);

    return 0;
}
