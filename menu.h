#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <strings.h>
#include "std_lib_facilities.h"
#include "component_info.h"
#include "robot_model.h"
#include "vector"
#include "comptorob.h"
#include "customer.h"
#include "salesassociate.h"

class Menu
{
public:
    int chorder;
    int choice1, custchoice1;
    vector<Component_Info> vec1;
    vector<Component_Info> vec1_ci;
    vector<Robot_Model> vec2;
    string line;
    int choice;
    char returnmenu_choice;

    int menum();
    void menu1();
    void custmenu();
    void samenu(string User);
};
#endif // MENU_H_INCLUDED
