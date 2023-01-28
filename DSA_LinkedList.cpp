#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct Node *head, *tail;

void insert(int value)
{
    Node *temp = new Node;
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
    Node *temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void create_list()
{
}

int main(int argc, char const *argv[])
{
    system("cls");
    create_list();

    return 0;
}
