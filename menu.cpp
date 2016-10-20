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
#include "comptorob.h"
#include "customer.h"
#include "productmanager.h"
#include "salesassociate.h"

int Menu::menum()
{
    do
    {
        cout << "1) Make Robot Components.\n";
        cout << "2) Make Robot Models.\n";
        cout << "3) Print Component Catalog.\n";
        cout << "4) Print Robot Catalog.\n";
        cout << "Enter Choice: ";
        cin >> choice1;
        cin.clear();
        cin.ignore();
    }while ((choice1 < 1) || (choice1 > 4));
    return choice1;
}


void Menu::menu1()
{
    ProductManager pm;

    do
    {
        choice = menum();

        if (choice == 1)
        {
            pm.getcompinfo();
        }
        else if (choice == 2)
        {
            pm.getrobotinfo();
        }
        else if (choice == 3)
        {
            pm.printcmpt();
        }
        else if (choice == 4)
        {
            pm.printrbt();
        }
        else
        {
            cout << "IMPOSSIBLE!";
        }
        cout << "\n\tDo you want to exit? (Y to exit, N to the Menu)\n\t->Your input: ";
        cin >> returnmenu_choice;
        cin.clear();
        cin.ignore();
    }while (((returnmenu_choice != 'y') && (returnmenu_choice != 'Y')));
}

void Menu::custmenu()
{
    Customer a;
    char returnmenu_choice;
    do
    {
        do
        {
            cout << endl;
            cout << "1) Print Robot Catalog.\n";
            cout << "2) See specific order.\n";
            cout << "Enter Choice: ";
            cin >> custchoice1;
            cin.clear();
            cin.ignore();
        }while ((custchoice1 < 1) || (custchoice1 > 2));


        if (custchoice1 == 1)
        {
            a.printRobot();
            a.robotcompinfo();
        }
        else if(custchoice1 == 2)
        {
            a.showcustdata();
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
        cout << "\n\tDo you want to exit? (Y to exit, N to the Menu)\n\t->Your input: ";
        cin >> returnmenu_choice;
        cin.clear();
        cin.ignore();
    }while (((returnmenu_choice != 'y') && (returnmenu_choice != 'Y')));
}

void Menu::samenu(string User)
{
    Customer b;
    Sales_Associate c;
    char returnmenu_choice;
    do
    {
        do
        {
            cout << endl;
            cout << "1) Print Robot Catalog.\n";
            cout << "2) Buy Robot and Quantity.\n";
            cout << "3) Show all orders.\n";
            cout << "Enter Choice: ";
            cin >> custchoice1;
            cin.clear();
            cin.ignore();
        }while ((custchoice1 < 1) || (custchoice1 > 3));
        if (custchoice1 == 1)
        {
            b.printRobot();
            b.robotcompinfo();
        }
        else if (custchoice1 == 2)
        {
            c.set_custname();
            c.set_orderno();
            do{
            int cust_quant;
            int robotbuy;
            int rbtcheck;



            cout << endl;
            b.printRobot();
            rbtcheck = b.retttlrbtno();

            do
            {
                cout << endl << "Please select Robot to buy: ";
                cin >> robotbuy;
            }while (robotbuy < 1 || robotbuy > rbtcheck);
            cin.clear();
            cin.ignore();

            do
            {
                c.set_custquant();
                cout << endl;
                cust_quant = c.get_custquant();
            }while (cust_quant < 1);

            cout << "Your Name Dear Customer: " << c.get_custname() << endl;
            cout << "Total Quantity: " << cust_quant << endl;
            cout << "Robot Name: " << b.retrbtnmcust(robotbuy) << endl;
            cout << "Total Robot Price: " << b.returnrobotfprice(cust_quant) << endl;
            c.custdatafile(b.retrbtnmcust(robotbuy), b.returnrobotfprice(cust_quant), User);

            cout << "Do you want to add 1 more? (press 1 to add more, press 0 to exit): " << endl;
            cin >> chorder;
            cin.clear();
            cin.ignore();

            }while(chorder==1);

        }
        else if (custchoice1 == 3)
        {
            c.show_orders();
        }

        cout << "\n\tDo you want to exit? (Y to exit, N to the Menu)\n\t->Your input: ";
        cin >> returnmenu_choice;
        cin.clear();
        cin.ignore();
    }while (((returnmenu_choice != 'y') && (returnmenu_choice != 'Y')));
}
