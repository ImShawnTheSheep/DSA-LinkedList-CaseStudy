#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

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

int create_list()
{
    int input;

    do
    {
        cout << "Enter a digit: ";
        cin >> input;

        if (input > 9)
        {
            cout << "\nLimitError: accepts single digit only \n";
        }

    } while (input > 9);

    return input;
}
void compute_list();
//* int carry_function();

int main(int argc, char const *argv[])
{
    system("cls");

    bool no_exit = true;
    int choice, nodes;
    char y_n;

    while (no_exit)
    {
        system("cls");

        cout << "------------------------------------\n";
        cout << "              Main Menu             \n";
        cout << "1. Create Lists\n";
        cout << "2. Display Lists\n";
        cout << "3. Compute Lists\n";
        cout << "4. Exit Program\n";
        cout << "------------------------------------\n";

        cout << "INPUT: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        LISTS_MENU:
            system("cls");
            cout << "------------------------------------\n";
            cout << "       Create/Overwrite Lists       \n";
            if (list1.head == NULL)
                cout << "1. Create List #1\n";
            else
                cout << "1. Overwrite List #1\n";

            if (list2.head == NULL)
                cout << "2. Create List #2\n";
            else
                cout << "2. Overwrite List #2\n";
            cout << "3. Reset All Lists\n";
            cout << "4. Back to Main Menu\n";
            cout << "------------------------------------\n";

            cout << "INPUT: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            LIST_1:
                system("cls");
                if (list1.head != NULL)
                {
                    cout << "OverwriteAlert!\n";
                    cout << "List #1 will be overwritten!\n";
                    system("pause");
                    cout << "\nResetting List #1 .";
                    sleep(1);
                    cout << "..";
                    sleep(1);
                    cout << "..\n";
                    cout << "\n--Overwrite Success--\n\n";
                    system("pause");
                }

                list1.head = NULL;
                list1.tail = NULL;

                do
                {
                    cout << "\nEnter number of nodes: ";
                    cin >> nodes;

                    if (nodes > 7)
                        cout << "\nLimitError: up to 7 nodes only\n";

                } while (nodes > 7);

                for (int i = 0; i < nodes; i++)
                    list1.insert(create_list());

                cout << "\nList #1: ";
                list1.display();

                cout << "\n\n";
                system("pause");

                goto LISTS_MENU;
            case 2:
            LIST_2:
                system("cls");
                if (list2.head != NULL)
                {
                    cout << "OverwriteAlert!\n";
                    cout << "List #2 will be overwritten!\n";
                    system("pause");
                    cout << "\nResetting List #2 .";
                    sleep(1);
                    cout << "..";
                    sleep(1);
                    cout << "..\n";
                    cout << "\n--Overwrite Success--\n\n";
                    system("pause");
                }

                list2.head = NULL;
                list2.tail = NULL;

                do
                {
                    cout << "\nEnter number of nodes: ";
                    cin >> nodes;

                    if (nodes > 7)
                        cout << "\nLimitError: up to 7 nodes only\n";

                } while (nodes > 7);

                for (int i = 0; i < nodes; i++)
                    list2.insert(create_list());

                cout << "\nList #2: ";
                list2.display();

                cout << "\n\n";
                system("pause");

                goto LISTS_MENU;
            case 3:
                system("cls");
                cout << "OverwriteAlert!\n";
                cout << "All Lists Made Will Be OVERWRITTEN!\n";
                system("pause");

                list2.head = NULL;
                list2.tail = NULL;
                list1.head = NULL;
                list1.tail = NULL;

                cout << "\nResetting List #1 .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..\n";
                cout << "\nResetting List #2 .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..\n";
                cout << "\n--Overwrite Success--\n\n";
                system("pause");
                goto LISTS_MENU;
            case 4:
                system("cls");
                cout << "Going back to main menu\n";
                cout << "Please wait .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..";
                break;
            default:
                system("cls");
                cout << "InputError: make sure input is correct.\n\n";
                system("pause");

                goto LISTS_MENU;
            }
            break;
        case 2:
            system("cls");
            cout << "\nDisplaying Lists .";
            sleep(1);
            cout << "..";
            sleep(1);
            cout << "..\n";
            if (list1.head != NULL && list2.head != NULL)
            {
                cout << "------------------------------------\n";
                cout << "List #1: ";
                list1.display();
                cout << "\n------------------------------------\n";
                cout << "List #2: ";
                list2.display();
                cout << "\n------------------------------------\n";
            }
            else if (list1.head != NULL && list2.head == NULL)
            {
                cout << "------------------------------------\n";
                cout << "List #1: ";
                list1.display();
                cout << "\n------------------------------------\n";
                cout << "List #2: ";
                cout << "NO DATA TO DISPLAY!\n";
                cout << "------------------------------------\n";

                cout << "No data entered in List #2!\n";
                cout << "Would you like to create List #2? [Y/n]";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LIST_2;
            }
            else if (list1.head == NULL && list2.head != NULL)
            {
                cout << "------------------------------------\n";
                cout << "List #1: NO DATA TO DISPLAY!\n";
                cout << "------------------------------------\n";
                cout << "List #2: ";
                list2.display();
                cout << "\n------------------------------------\n";

                cout << "\nNo data entered in List #1!\n";
                cout << "Would you like to create List #1? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LIST_1;
            }
            else
            {
                cout << "------------------------------------\n";
                cout << "List #1: NO DATA TO DISPLAY!\n";
                cout << "------------------------------------\n";
                cout << "List #1: NO DATA TO DISPLAY!\n";
                cout << "------------------------------------\n";

                cout << "\nNo data entered in the lists!\n";
                cout << "Would you like to create the lists? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LISTS_MENU;
            }
            cout << "\n\n";
            system("pause");
            cout << "Going back to main menu\n";
            cout << "Please wait .";
            sleep(1);
            cout << "..";
            sleep(1);
            cout << "..";
            break;
        case 3:
            system("cls");
            if (list1.head == NULL && list2.head == NULL)
            {
                cout << "ComputeError: No data in the lists!\n";
                cout << "Would you like to create the lists? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LISTS_MENU;
            }
            else if (list1.head == NULL && list2.head != NULL)
            {
                cout << "ListWarn: No data in List #1!\n";
                cout << "Would you like to create List #1 before computing? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LIST_1;
                else
                    system("cls");

                compute_list();
                cout << "\nComputing Lists .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..\n";
                cout << "\n--Compute Success--\n";

                cout << "\n------------------------------------\n";
                cout << "List #2: ";
                list2.display();
                cout << "\n------------------------------------\n";
                cout << "Total:   ";
                sumlist.rev_display();
                cout << "\n------------------------------------\n";
            }
            else if (list1.head != NULL && list2.head == NULL)
            {
                cout << "ListWarn: No data in List #2!\n";
                cout << "Would you like to create List #2 before computing? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LIST_2;
                else
                    system("cls");

                compute_list();
                cout << "\nComputing Lists .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..\n";
                cout << "\n--Compute Success--\n";

                cout << "\n------------------------------------\n";
                cout << "List #1: ";
                list1.display();
                cout << "\n------------------------------------\n";
                cout << "Total:   ";
                sumlist.rev_display();
                cout << "\n------------------------------------\n";
            }
            else
            {
                compute_list();
                cout << "\nComputing Lists .";
                sleep(1);
                cout << "..";
                sleep(1);
                cout << "..\n";
                cout << "\n--Compute Success--\n";

                cout << "\n------------------------------------\n";
                cout << "List #1: ";
                list1.display();
                cout << "\n------------------------------------\n";
                cout << "List #2: ";
                list2.display();
                cout << "\n------------------------------------\n";
                cout << "Total:   ";
                sumlist.rev_display();
                cout << "\n------------------------------------\n";
            }

            cout << "\n\n";
            system("pause");
            cout << "Going back to main menu\n";
            cout << "Please wait .";
            sleep(1);
            cout << "..";
            sleep(1);
            cout << "..";
            break;
        case 4:
            no_exit = false;
            system("cls");
            cout << "Exiting Program\n";
            cout << "Please wait .";
            sleep(1);
            cout << "..";
            sleep(1);
            cout << "..";
            break;
        default:
            system("cls");
            cout << "InputError: Make sure input is correct.\n\n";
            system("pause");
            break;
        }
    }

    return 0;
}

void compute_list()
{

    list2.curr = list2.tail;
    list1.curr = list1.tail;
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
            else if (sum == 10 || sum == 20)
            {
                if (sum == 10)
                {
                    carry = 1;
                    sum = 0;
                }
                else if (sum == 20)
                {
                    carry = 2;
                    sum = 0;
                }
            }
            else if (sum > 20)
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

    if ((list1.curr != NULL) && (list2.curr == NULL))
    {
        do
        {
            sum = list1.curr->data + carry;

            if (sum > 10 && sum < 20)
            {
                sum = sum - 10;
                carry = 1;
            }
            else if (sum == 10 || sum == 20)
            {
                if (sum == 10)
                {
                    carry = 1;
                    sum = 0;
                }
                else if (sum == 20)
                {
                    carry = 2;
                    sum = 0;
                }
            }
            else if (sum > 20)
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

        } while (list1.curr != NULL);
    }
    else if ((list2.curr != NULL) && (list1.curr == NULL))
    {
        do
        {
            sum = list2.curr->data + carry;

            if (sum > 10 && sum < 20)
            {
                sum = sum - 10;
                carry = 1;
            }
            else if (sum == 10 || sum == 20)
            {
                if (sum == 10)
                {
                    carry = 1;
                    sum = 0;
                }
                else if (sum == 20)
                {
                    carry = 2;
                    sum = 0;
                }
            }
            else if (sum > 20)
            {
                sum = sum - 20;
                carry = 2;
            }
            else
            {
                carry = 0;
            }

            sumlist.insert(sum);

            list2.curr = list2.curr->prev;

        } while (list2.curr != NULL);
    }

    if (carry >= 1)
    {
        sumlist.insert(carry);
    }
}