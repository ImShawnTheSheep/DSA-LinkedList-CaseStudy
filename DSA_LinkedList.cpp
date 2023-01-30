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

    void rev_display()
    {
        Node *temp = tail;
        temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
};

LinkedList list1;
LinkedList list2;
LinkedList sumlist;

int create_list();
void display_list();
void compute_list();
//* int carry_function();

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
    cout << "\n First List:  ";
    list1.display();
    cout << "\n Second List: ";
    list2.display();
    cout << "\n Total:       ";
    sumlist.rev_display();
}

void compute_list()
{
    list1.curr = list1.tail;
    list2.curr = list2.tail;
    sumlist.head = NULL;
    sumlist.tail = NULL;

    int sum;
    int carry = 0;

    if ((list1.curr != NULL) && (list2.curr != NULL))
    {
        do
        {
            sum = list1.curr->data + list2.curr->data + carry;

            if (sum >= 10 && sum < 20)
            {
                sum = sum - 10;
                carry = 1;
            }
            else if (sum >= 20)
            {
                sum = sum - 20;
                carry = 2;
            }
            else
            {
                carry = 0;
            }

            sumlist.insert(sum);

            list1.curr = list1.curr->prev;
            list2.curr = list2.curr->prev;

        } while ((list1.curr != NULL) && (list2.curr != NULL));
    }
    else if ((list1.curr != NULL) && (list2.curr == NULL))
    {
        do
        {
            sum = list1.curr->data + carry;

            sumlist.insert(sum);

            list1.curr = list1.curr->prev;

        } while (list1.curr != NULL);
    }
    else if ((list2.curr != NULL) && (list1.curr == NULL))
    {
        do
        {
            sum = list2.curr->data + carry;

            sumlist.insert(sum);

            list2.curr = list2.curr->prev;

        } while (list2.curr != NULL);
    }
}

int carry_function(int sum)
{
    int carry;
}