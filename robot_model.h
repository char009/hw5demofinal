#ifndef ROBOT_MODEL_H_INCLUDED
#define ROBOT_MODEL_H_INCLUDED

#include<iostream>
#include<string>

#include "component_info.h"

class Robot_Model
{
private:
    string model_name;
    int  model_number;
    double model_price;
    string model_description;
    double model_sales_price;
    int number_sold;
    double total_weight;
public:
    Robot_Model (string mname,
                    int mnumber,
                    double mprice,
                    string mdescription,
                    double msprice,
                    int mnumbersold,
                    double mtweight) :

                    model_name(mname),
                    model_number(mnumber),
                    model_price(mprice),
                    model_description(mdescription),
                    model_sales_price(msprice),
                    number_sold(mnumbersold),
                    total_weight(mtweight) {}

    void set_model_name();
    void set_model_number();
    void set_model_price();
    void set_model_description();
    void set_model_sales_price();
    void set_number_sold();
    void set_total_weight();

    string get_model_name();
    int get_model_number();
    double get_model_price();
    string get_model_description();
    double get_model_sales_price();
    int get_number_sold();
    double get_total_weight();

    void print_robot_model();
};

#endif // ROBOT_MODEL_H_INCLUDED
