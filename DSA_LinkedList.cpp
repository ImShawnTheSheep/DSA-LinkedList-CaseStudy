#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
public:
    Node *head, *tail, *curr;

    void insert(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void rev_insert(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;

        if (tail == NULL)
        {
            tail = temp;
            head = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            head = temp;
        }
    }

    void display()
    {
        Node *temp = head;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

LinkedList list1;
LinkedList list2;
LinkedList sumlist;

int create_list();
void display_list();
void compute_list();

int main(int argc, char const *argv[])
{
    bool no_exit = true;
    int choice, nodes;

    while (no_exit)
    {
        cout << "    Main Menu    \n";
        cout << "1. Create List #1\n";
        cout << "2. Create List #2\n";
        cout << "3. Display Lists\n";
        cout << "4. Compute Lists\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list1.head = NULL;
            list1.tail = NULL;
            cout << "Creating first list\n\n";
            do
            {
                cout << "Enter number of nodes: ";
                cin >> nodes;

                if (nodes > 7)
                {
                    cout << "LimitError: up to 7 nodes only \n";
                }

            } while (nodes > 7);

            for (int i = 0; i < nodes; i++)
            {
                list1.insert(create_list());
            }
            break;
        case 2:
            list2.head = NULL;
            list2.tail = NULL;
            cout << "Creating second list\n\n";
            do
            {
                cout << "Enter number of nodes: ";
                cin >> nodes;

                if (nodes > 7)
                {
                    cout << "LimitError: up to 7 nodes only \n";
                }

            } while (nodes > 7);

            for (int i = 0; i < nodes; i++)
            {
                list2.insert(create_list());
            }
            break;
        case 3:
            display_list();
            cout << "\n";
            break;
        case 4:
            compute_list();
            break;
        case 5:
            no_exit = false;
            break;
        default:
            break;
        }
    }

    return 0;
}

int create_list()
{
    int input;

    do
    {
        cout << "Enter Element: ";
        cin >> input;

        if (input > 9)
        {
            cout << "Error: single digit only \n";
        }

    } while (input > 9);

    return input;
}

void display_list()
{
    cout << "\n First List: ";
    list1.display();
    cout << "\n Second List: ";
    list2.display();
    cout << "\n Sum: ";
    sumlist.display();
}

void compute_list()
{
}