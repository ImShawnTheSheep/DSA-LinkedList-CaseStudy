#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};


int main(int argc, char const *argv[])
{
    List list1;
    List list2;

    cout << "Enter elements for first list (maximum of 7 elements):" << endl;
    for (int i = 0; i < 7; i++) {
        int element;
        cin >> element;
        list1.addNode(element);
    }


    
    return 0;
}
