#include "salesassociate.h"
#include "customer.h"
#include <string>
#include <iostream>

void Sales_Associate::set_custquant()
{
    cout << "\nPlease enter number of quantity: ";
    cin >> quantity;
    cin.clear();
    cin.ignore();
    quantity1 = quantity;
}

int Sales_Associate::get_custquant()
{
    return quantity;
}

void Sales_Associate::set_custname()
{
    cout << "\nPlease enter your name dear customer: ";
    getline(cin, custname);
}

string Sales_Associate::get_custname()
{
    return custname;
}

void Sales_Associate::set_orderno()
{
    ofstream myfile4;
    ifstream myfile3("Order Number.txt");
    if (myfile3.is_open())
    {
        while ( getline(myfile3 ,order_num_str) )
        {
            stringstream convert(order_num_str);
            convert >> order_num;
            //cout<<"Order Number: "<<order_num;
        }
    }
    order_num++;
    myfile3.close();

    myfile4.open("Order Number.txt");
    stringstream ss;
    ss << order_num;
    myfile4 << ss.str();
    myfile4.close();
}

void Sales_Associate::custdatafile(string abcd, double abd, string User)
{

    //cout << "File name: " << custname << ".txt";
    ofstream myfile1,myfile2,myfile6;
    myfile1.open((custname+".txt").c_str(),ios::app);
    myfile2.open("All Customer Records.txt",ios::app);
    myfile6.open((User+".txt").c_str(),ios::app);
    stringstream ssd;
    ssd << custname;
    myfile6 << ssd.str() << "\n";
    myfile6.close();

    stringstream ss2, ss3;

    ss2 << quantity1;
    ss3 << abd;

    final_line = "";
    final_line += order_num_str + "," + abcd + "," + ss2.str() + "," + ss3.str();

    myfile1 << final_line << "\n";
    myfile2 << final_line << "\n";
    myfile1.close();
    myfile2.close();

    cout << "\n";
    cout << "Your Order: " << endl;
    cout << "Order Number: " << order_num-1 << endl;
    cout << "Dear Customer Name: " << custname << endl;
    cout << "Robot Model Name: " << abcd << endl;
    cout << "Total Price: " << abd << endl;


    /* */

    /* */

}

void Sales_Associate::show_orders()
{
    const char separator = ' ';
    const int orderno1 = 20;
    const int totalprc = 20;
    string line;
    int orderlncnt;
    orderlncnt = 0;
    ifstream myfile5("All Customer Records.txt");
    cout << "No\t" << left << setw(orderno1) << setfill(separator) << "Order number"
                     << left << setw(totalprc) << setfill(separator) << "Total Price" << endl;

    if (myfile5.is_open())
    {
        while (getline (myfile5,line))
        {
            ofstream ofs1;
            ofs1.open("test1.txt");
            ofs1 << line;
            ofs1.close();

            ifstream breakFile1("test1.txt");

            while(breakFile1)
            {
                orderlncnt++;
                cout << orderlncnt << "\t";

                string robmname="",quant="";
                string Order_num="",price="";

                getline (breakFile1,Order_num,',');
                cout << left << setw(orderno1) << setfill(separator) << Order_num;
                int orderno1;
                stringstream convert2(Order_num);
                convert2 >> orderno1;
                orderno.push_back(orderno1);

                getline(breakFile1,robmname,',');
                orderrobotnm.push_back(robmname);

                getline(breakFile1,quant,',');
                int quant1;
                stringstream convert5(quant);
                convert5 >> quant1;
                orderquant.push_back(quant1);

                getline(breakFile1,price,',');
                double price1;
                stringstream convert4(price);
                convert4 >> price1;
                orderprice.push_back(price1);
                cout  << "$ " << left << setw(totalprc) << setfill(separator) << price << "\n";

                break;
            }
        }
    }
    myfile5.close();

    do{
        cout << "\nPlease enter the index of the order no for more details: " << endl;
        cin >> indexorder;
        cin.clear();
        cin.ignore();
    }while (indexorder < 1 || indexorder > orderlncnt);

    cout << "Order No: " << orderno.at(indexorder-1) << endl;
    cout << "Robot ordered(Name): " << orderrobotnm.at(indexorder-1) << endl;
    cout << "Total Robots ordered: " << orderquant.at(indexorder-1) << endl;
    cout << "Total order price: $ " << orderprice.at(indexorder-1) << endl;

    cout<<"\n\n";
}
