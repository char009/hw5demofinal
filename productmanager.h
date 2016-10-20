#ifndef PRODUCTMANAGER_H_INCLUDED
#define PRODUCTMANAGER_H_INCLUDED

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

class ProductManager
{
public:
    bool obsolete = false;
    vector<string> locom1;
    vector<string> armm1;
    vector<string> battr1;
    vector<string> torsoo1;
    vector<string> headd1;
    vector<string> nm;
    vector<Component_Info> vec1;
    vector<Component_Info> vec1_ci;
    vector<Robot_Model> vec2;
    string line;
    int indexno;

    void getcompinfo();
    void getrobotinfo();
    void printrbt();
    void printcmpt();


};

#endif // PRODUCTMANAGER_H_INCLUDED
