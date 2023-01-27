#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class linked_list
{
    Node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

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

};



int main(int argc, char const *argv[])
{
    linked_list list1;
    linked_list list2;

    cout << "Enter elements for first list (maximum of 7 elements): \n" ;
    for (int i = 0; i < 7; i++) {
        int element;
        cin >> element;
        list1.insert(element);
    }

    list1.display();

    return 0;
}
