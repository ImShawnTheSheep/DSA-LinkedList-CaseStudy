#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class linkedList
{
public:
    Node *head, *tail;

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

int create_list();

int main(int argc, char const *argv[])
{
    linkedList list1;
    list1.head = NULL;
    list1.tail = NULL;

    linkedList list2;
    list2.head = NULL;
    list2.tail = NULL;

    for (int i = 0; i < 7; i++)
    {
        list1.insert(create_list());
    }

    for (int i = 0; i < 7; i++)
    {
        list2.insert(create_list());
    }

    cout << "\n\n";
    list1.display();
    cout << "\n\n";
    list2.display();

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