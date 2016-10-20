#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <strings.h>
#include "std_lib_facilities.h"
#include "component_info.h"
#include "robot_model.h"
#include "vector"
#include "menu.h"

using namespace std;

int main()
{

    Menu menu;

    cout<<"\n\n\n\n\t\t\t\t\t\t\t\tWelcome!\n\t\t\t\t\t\t\t\t(Press Enter)\n\n\n\n\n";
    getch();
    system("cls");

    int choice=0;

    do
    {
        cout << "Which User are you?";
        cout << "\n\n1. Product Manager\n2. Customer\n3. Sales Associate\nEnter Choice: ";
        cin >> choice;
    }while( choice < 1 && choice > 3);

    string userName, password;
    if(choice != 2)
    {
        system("cls");
        cout << "\n\nUser Name: ";
        cin >> userName;
        char ch;
        cout << "Enter password: ";
        ch = _getch();
        while(ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }
    }

    switch( choice )
    {
        case 1:{
                    if(userName=="PMRRS" && password == "char009")
                    {
                        cout << "\nAccess granted :P\n";
                        // provide boss access here!
                        menu.menu1();
                    }
                    else
                        cout << "\nAccess aborted...\n";
                    break;
               }

        case 2:{
                    // give customer access to things here
                    menu.custmenu();
                    break;
               }

        case 3:{
                    if(userName=="SA1RRS" && password == "paperpro")
                    {
                        cout << "\nAccess granted :P\n";
                        // provide Sales Assistant access here!
                        menu.samenu(userName);
                    }
                    else if(userName=="SA2RRS" && password == "scotch3m")
                    {
                        cout << "\nAccess granted :P\n";
                        // provide Sales Assistant access here!
                        menu.samenu(userName);
                    }
                    else
                        cout << "\nAccess aborted...\n";
                    break;
               }

    }
    return 0;
}
