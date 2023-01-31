#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

//* create a Node structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//* create LinkedList class for mutiple lists
class LinkedList
{
public:
    Node *head, *tail, *curr;

    //* methods for inserting and displaying the lists
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

//* declared three (3) LinkedList objects
LinkedList list1;   // for List #1
LinkedList list2;   // for List #2
LinkedList sumlist; // for the total of the lists

/*
 * prototype functions for:
 *  set number of nodes by user input
 *  creating the lists by user input
 *  compute the lists
 *  resetting lists
 *  delaying output
 *  prompt going back to main menu
 */
int setnum_node();
int create_list();
void reset_list(int n);
void delay_out();
void to_main();
void compute_list();

// main function
int main(int argc, char const *argv[])
{
    system("cls");

    bool no_exit = true;
    int choice, n;
    char y_n;

    while (no_exit)
    {
        system("cls");

        //* MAIN MENU UI
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
            //* LIST MENU UI for creating and overwriting lists

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
                //* CREATE/OVERWRITE LIST 1 module
            LIST_1:
                system("cls");
                if (list1.head != NULL)
                {
                    //! Warns user that List #1 will be overwritten
                    cout << "OverwriteAlert!\n";
                    cout << "List #1 will be overwritten!\n";
                    system("pause");
                    cout << "\nResetting List #1 .";
                    delay_out();
                    cout << "\n--Overwrite Success--\n\n";
                    system("pause");
                    goto LIST_1;
                }

                reset_list(1);
                n = setnum_node();
                for (int i = 0; i < n; i++)
                    list1.insert(create_list());

                cout << "\nList #1: ";
                list1.display();

                cout << "\n\n";
                system("pause");

                goto LISTS_MENU;
            case 2:
                //* CREATE/OVERWRITE LIST 2 module
            LIST_2:
                system("cls");
                if (list2.head != NULL)
                {
                    //! Warns user that List #2 will be overwritten
                    cout << "OverwriteAlert!\n";
                    cout << "List #2 will be overwritten!\n";
                    system("pause");
                    cout << "\nResetting List #2 .";
                    delay_out();
                    cout << "\n--Overwrite Success--\n\n";
                    system("pause");
                    goto LIST_2;
                }

                reset_list(2);
                n = setnum_node();
                for (int i = 0; i < n; i++)
                    list2.insert(create_list());

                cout << "\nList #2: ";
                list2.display();

                cout << "\n\n";
                system("pause");

                goto LISTS_MENU;
            case 3:
                //* OVERWRITE ALL LISTS module
                //! Warns user that all lists will be overwritten
                system("cls");
                cout << "OverwriteAlert!\n";
                cout << "All Lists Made Will Be OVERWRITTEN!\n";
                system("pause");

                reset_list(3);
                cout << "\nResetting List #1 .";
                delay_out();
                cout << "\nResetting List #2 .";
                delay_out();
                cout << "\n--Overwrite Success--\n\n";
                system("pause");
                goto LISTS_MENU;
            case 4:
                to_main();
                break;
            default:
                system("cls");
                //! Outputs error message to tell the user their input is incorrect
                cout << "InputError: make sure input is correct.\n\n";
                system("pause");
                goto LISTS_MENU;
            }
            break;
        case 2:
            //* DISPLAY LISTS module

            system("cls");
            cout << "\nDisplaying Lists .";
            delay_out();

            // displays lists if not empty
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
            // display List #1 only if List #2 is empty
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
            // display List #2 only if List #1 is empty
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
            // "NO DATA TO DISPLAY" if lists are empty
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

            to_main();
            break;
        case 3:
            //* COMPUTE LISTS module

            system("cls");

            // display error if lists are empty
            if (list1.head == NULL && list2.head == NULL)
            {
                //! Outputs error message that no lists have been made
                cout << "ComputeError: No data in the lists!\n";
                cout << "Would you like to create the lists? [Y/n]\n";
                y_n = getch();

                if (y_n == 'Y' || y_n == 'y')
                    goto LISTS_MENU;
            }
            // compute and dislpay LIST #2 if LIST #1 is empty
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
                delay_out();
                cout << "\n--Compute Success--\n";

                cout << "\n------------------------------------\n";
                cout << "List #2: ";
                list2.display();
                cout << "\n------------------------------------\n";
                cout << "Total:   ";
                sumlist.rev_display();
                cout << "\n------------------------------------\n";
            }
            // compute and display LIST #1 if LIST #2 is empty
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
            // display and compute all lists if lists are not empty
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

            to_main();
            break;
        case 4:
            no_exit = false;
            system("cls");
            cout << "Exiting Program\n";
            cout << "Please wait .";
            delay_out();
            delay_out();
            break;
        default:
            system("cls");
            //! Outputs error message to tell the user their input is incorrect
            cout << "InputError: Make sure input is correct.\n\n";
            system("pause");
            break;
        }
    }

    return 0;
}

//* function for setting number of nodes
int setnum_node()
{
    int nodes;

    do
    {
        cout << "\nEnter number of nodes: ";
        cin >> nodes;

        if (nodes > 7)
            //! Outputs error message if nodes is greater than 7
            cout << "\nLimitError: up to 7 nodes only\n";

    } while (nodes > 7);

    return nodes;
}
//* function for creating lists from user inputs
int create_list()
{
    int input;

    do
    {
        cout << "Enter a digit: ";
        cin >> input;

        if (input > 9)
            //! Outputs error message if not single digit
            cout << "\nLimitError: accepts single digit only \n\n";

    } while (input > 9);

    return input;
}
//* function for resetting lists
void reset_list(int n)
{
    switch (n)
    {
    case 1:
        list1.head = NULL;
        list1.tail = NULL;
        break;
    case 2:
        list2.head = NULL;
        list2.tail = NULL;
        break;
    case 3:
        list1.head = NULL;
        list1.tail = NULL;
        list2.head = NULL;
        list2.tail = NULL;
        break;
    case 4:
        sumlist.head = NULL;
        sumlist.tail = NULL;
        break;
    }
}
//* function for delaying output
void delay_out()
{
    sleep(1);
    cout << "..";
    sleep(1);
    cout << "..\n";
}
//* function for prompt going back to main menu
void to_main()
{
    cout << "\n\n";
    system("pause");
    cout << "Going back to main menu\n";
    cout << "Please wait .";
    delay_out();
}
//* function for computing the lists
void compute_list()
{

    list2.curr = list2.tail;
    list1.curr = list1.tail;
    reset_list(4);

    int sum;
    int carry = 0;

    //* computes until one of the lists are NULL
    if (list1.curr != NULL && list2.curr != NULL)
    {
        do
        {
            sum = list1.curr->data + list2.curr->data + carry;

            //* SUM PROCESSING MODULE
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
    //* computes until LIST #1 is NULL
    if (list1.curr != NULL && list2.curr == NULL)
    {
        do
        {
            sum = list1.curr->data + carry;

            //* SUM PROCESSING MODULE
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
    //* computes until LIST #2 is NULL
    else if (list2.curr != NULL && list1.curr == NULL)
    {
        do
        {
            sum = list2.curr->data + carry;

            //* SUM PROCESSING MODULE
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

    //* inserts carry to the sum
    if (carry >= 1)
        sumlist.insert(carry);
}