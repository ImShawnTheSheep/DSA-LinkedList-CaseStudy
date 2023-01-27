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

void create_list1()
{
    linked_list list1;
    int element, n;

    do
    {
        cout << "Enter number of nodes: ";
        cin >> n;

        if (n > 7)
        {
            cout << "LimitError: up to 7 nodes only \n";
        }

    } while (n > 7);
    
    

    cout << "Enter elements for first list (maximum of 7 elements) \n\n" ;
    for (int i = 0; i < 7; i++) 
    {
        do
        {
            cout << "Enter Element: ";
            cin >> element;

            if (element > 9)
            {
                cout << "Error: single digit only \n";
            }
            
        } while (element > 9);
        
        list1.insert(element);
    }

    list1.display();
}


int main(int argc, char const *argv[])
{
    create_list1();

    
    



    return 0;
}
