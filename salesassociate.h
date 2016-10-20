#ifndef SALESASSOCIATE_H_INCLUDED
#define SALESASSOCIATE_H_INCLUDED

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
#include "customer.h"

class Sales_Associate
{
public:

    int quantity, quantity1;
    string custname;
    long int order_num;
    string order_num_str;
    string final_line;
    vector<string> orderrobotnm;
    vector<double> orderprice;
    vector<int> orderquant;
    vector<int> orderno;
    int indexorder;

    void custdatafile(string abcd, double abd, string User);
    void set_custquant();
    void set_custname();
    int get_custquant();
    string get_custname();
    void set_orderno();
    void show_orders();
};

#endif // SALESASSOCIATE_H_INCLUDED
