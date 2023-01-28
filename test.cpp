linked_list list1;
    linked_list list2;
    int element, n;

    cout << "Creating first list\n\n";
    do
    {
        cout << "Enter number of nodes: ";
        cin >> n;

        if (n > 7)
        {
            cout << "LimitError: up to 7 nodes only \n";
        }

    } while (n > 7);
    
    cout << "Enter elements for first list\n\n" ;
    for (int i = 0; i < n; i++) 
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

    system("cls");

    cout << "Creating second list\n\n";
    do
    {
        cout << "Enter number of nodes: ";
        cin >> n;

        if (n > 7)
        {
            cout << "LimitError: up to 7 nodes only\n";
        }

    } while (n > 7);
    
    cout << "Enter elements for first list\n\n" ;
    for (int i = 0; i < n; i++) 
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
        
        list2.insert(element);
    }

    system("cls");

    cout << "\n First List: ";
    list1.display();
    cout << "\n Second List: ";
    list2.display();