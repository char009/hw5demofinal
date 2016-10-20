#ifdef _MSC_VER
#include "stdafx.h"
#endif
#include "component_info.h"
#include <string>
#include <iostream>
#include "robot_model.h"

void Robot_Model::set_model_name()
{
    cout << "Please enter model name: ";
    getline(cin, model_name);
}

void Robot_Model::set_model_number()
{
    cout << "Please enter model number: ";
    cin >> model_number;
    cin.clear();
    cin.ignore();
}

void Robot_Model::set_model_price( )
{
    cout << "Please enter model price($): ";
    cin >> model_price;
    cin.clear();
    cin.ignore();
}


void Robot_Model::set_model_description()
{
    cout << "Please enter model description: ";
    getline(cin, model_description);
}

void Robot_Model::set_model_sales_price()
{
    double tax, profit, shipping;
    tax = 0.85 * model_price;
    profit = 0.20 * model_price;
    shipping = 15;
    model_sales_price = model_price + tax + shipping + profit;
}

void Robot_Model::set_number_sold()
{
    cout << "Please enter number of models sold: ";
    cin >> number_sold;
    cin.clear();
    cin.ignore();
}

void Robot_Model::set_total_weight()
{
    cout << "Please enter Model weight(kg): ";
    cin >> total_weight;
    cin.clear();
    cin.ignore();
}


string Robot_Model::get_model_name()
{
    return model_name;
}

int Robot_Model::get_model_number()
{
    return model_number;
}

double Robot_Model::get_model_price()
{
    return model_price;
}

string Robot_Model::get_model_description()
{
    return model_description;
}

double Robot_Model::get_model_sales_price()
{
    return model_sales_price;
}

int Robot_Model::get_number_sold()
{
    return number_sold;
}

double Robot_Model::get_total_weight()
{
    return total_weight;
}

void Robot_Model::print_robot_model()
{
    cout << "Model Name: " << model_name << endl;
    cout << "Model Number: " << model_number << endl;
    cout << "Model Price " << model_price << " $" << endl;
    cout << "Model Description: " << model_description << endl;
    cout << "Model Sales Price " << model_sales_price << " $" << endl;
    cout << "Total Model Sold: " << number_sold << endl;
    cout << "Model Total Weight: " << total_weight << " kg" << endl;
}
