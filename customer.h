#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

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

class Customer
{
public:
    vector<string> locom1;
    vector<string> armm1;
    vector<string> battr1;
    vector<string> torsoo1;
    vector<string> headd1;
    vector<string> nm1;
    vector<double> rbtprice;
    int cntt;
    string custnm1;
    string rbtbuynm, rbtbuynm1;
    int robotbuy1;
    double rrobotprice, rrobotprice1;
    vector<string> cust_ordrbnm;
    vector<double> cust_ordpri;
    vector<int> cust_ordquant;
    vector<int> cust_ordno;
    int indexorder1;

    void printRobot();
    void robotcompinfo();
    string retrbtnmcust(int robotbuy);
    string retrbtnmcust1();
    int retttlrbtno();
    double returnrobotfprice(int custquant);
    double returnrobotfprice1();
    void showcustdata();
};

#endif // CUSTOMER_H_INCLUDED
