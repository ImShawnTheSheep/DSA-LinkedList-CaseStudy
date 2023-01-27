#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

class linked_list
{
    private:
        node *head, *tail;
    public:
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }

        void add_node(int n)
        {
            node *tmp = new node;
            tmp -> data = n;
            tmp -> next = NULL;

            if (head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail -> next = tmp;
                tail = tail -> next;
            }
            
        }
};


int main(int argc, char const *argv[])
{
    int arry1[7];
    int arry2[7];



    
    return 0;
}
