#include "customer.h"
#include <string>
#include <iostream>

void Customer::printRobot()
{
    const char separator1 = ' ';
    const int nameWidth1 = 13;
    const int rpartno1 = 16;
    const int rprice1 = 15;
    const int rquant1 = 12;
    const int rweight1 = 13;
    const int rdescrip1 = 14;

    try
    {
        string line1;
        ifstream myfile1 ("robotcatalog.txt");
        if (myfile1.is_open())
        {
            int cnt = 0;
            cout << "No\t" << setw(10) <<"Robot Name "
                << setw(17) << "Robot Part No."
                << setw(17) << "Robot Price($)"
                << setw(10) << "Quantity"
                << setw(15) << "Weight(Kg)"
                << setw(15) << "Description" <<endl
                <<"------------------------------------------------------------------------------------------"<<endl;
            while (getline(myfile1,line1))
            {
                ofstream ofs1;
                ofs1.open("test1.txt");
                ofs1 << line1;
                ofs1.close();
                ifstream breakFile1("test1.txt");
                while(breakFile1)
                {
                    string parts1="";
                    string name1="";

                    cnt++;
                    getline (breakFile1,name1,',');
                    nm1.push_back(name1);
                    cout << cnt << "\t" << left << setw(nameWidth1) << setfill(separator1) << name1<< " ";

                    getline (breakFile1,parts1,',');
                    int part_num1=0;
                    stringstream convert(parts1);
                    convert>>part_num1;
                    cout << left << setw(rpartno1) << setfill(separator1) << part_num1 << " ";
                    parts1="";

                    getline (breakFile1,parts1,',');
                    double price1=0;
                    stringstream convert2(parts1);
                    convert2>>price1;
                    cout << left << setw(rprice1) << setfill(separator1) << price1 << " ";
                    rbtprice.push_back(price1);
                    parts1="";

                    getline (breakFile1,parts1,',');
                    int Model_numbers_sold=0;
                    stringstream convert3(parts1);
                    convert3>>Model_numbers_sold;
                    cout << left << setw(rquant1) << setfill(separator1) << Model_numbers_sold << " ";
                    parts1="";

                    getline (breakFile1,parts1,',');
                    double weight1=0;
                    stringstream convert1(parts1);
                    convert1>>weight1;
                    cout << left << setw(rweight1) << setfill(separator1) << weight1 << " ";
                    parts1="";

                    string description1;
                    getline (breakFile1,description1,',');
                    cout << left << setw(rdescrip1) << setfill(separator1) << description1 << " ";
                    cout<<"\n";

                    string loco;
                    getline (breakFile1,loco,',');
                    locom1.push_back(loco);

                    string arm;
                    getline (breakFile1,arm,',');
                    armm1.push_back(arm);

                    string battery;
                    getline (breakFile1,battery,',');
                    battr1.push_back(battery);


                    string torso;
                    getline (breakFile1,torso,',');
                    torsoo1.push_back(torso);


                    string head;
                    getline (breakFile1,head,',');
                    headd1.push_back(head);

                    break;
                }
                cntt = cnt;
            }
            cout<<"------------------------------------------------------------------------------------------" <<endl;
            myfile1.close();
        }
    }
    catch(exception& e) { }
}

void Customer::robotcompinfo()
{
    int indexno1;

    do{
        cout << "\nEnter Index no of robot for more info: ";
        cin >> indexno1;
        cin.clear();
        cin.ignore();
        }while((indexno1 < 1) || (indexno1 > cntt));

    int j = indexno1;


    cout << "Robot Model Name: " << nm1.at(j-1) << endl;
    cout << "Locomotor part name: " << locom1.at((j-1)) << endl;
    cout << "Arm part name: " << armm1.at((j-1)) << endl;
    cout << "Battery part name: " << battr1.at((j-1)) << endl;
    cout << "Torso part name: " << torsoo1.at((j-1)) << endl;
    cout << "Head part name: " << headd1.at((j-1)) << endl;
}

string Customer::retrbtnmcust(int robotbuy)
{
    robotbuy1 = robotbuy;
    rbtbuynm = nm1.at(robotbuy-1);
    rbtbuynm1 = rbtbuynm;
    return rbtbuynm;
}

string Customer::retrbtnmcust1()
{
    return rbtbuynm1;
}

double Customer::returnrobotfprice(int custquant)
{
    rrobotprice = custquant*rbtprice.at(robotbuy1-1);
    rrobotprice1 = rrobotprice;
    return rrobotprice;
}

double Customer::returnrobotfprice1()
{
    return rrobotprice1;
}

int Customer::retttlrbtno()
{
    return cntt;
}

void Customer::showcustdata()
{
    cout << "Please enter customer name to find the order: ";
    getline(cin, custnm1);
    string line;
    if (custnm1 == "")
    {
        cout << "No name entered.";
    }
    else
    {
        const char separator = ' ';
        const int orderno1 = 20;
        const int mdlnm = 20;
        const int ttlnmsld = 20;
        const int totalprc = 20;
        string line;
        int orderlncnt;
        orderlncnt = 0;
        cout << "No\t" << left << setw(orderno1) << setfill(separator) << "Order number"
                       << left << setw(mdlnm) << setfill(separator) << "Model name"
                       << left << setw(ttlnmsld) << setfill(separator) << "Total number sold"
                       << left << setw(totalprc) << setfill(separator) << "Total Price" << endl;
        ifstream myfile5((custnm1 + ".txt").c_str());

        if (myfile5.is_open())
        {
            while (getline(myfile5 ,line))
            {
                ofstream ofs1;
                ofs1.open("test3.txt");
                ofs1 <<line;
                ofs1.close();

                ifstream breakFile1("test3.txt");

                while(breakFile1){
                        orderlncnt++;
                cout << orderlncnt << "\t";


                string Model_Name="",Number_of_models_sold="";
                string Order_num="",price="";

                getline (breakFile1,Order_num,',');
                cout << left << setw(orderno1) << setfill(separator) << Order_num;
                int orderno1;
                stringstream convert2(Order_num);
                convert2 >> orderno1;
                cust_ordno.push_back(orderno1);

                getline(breakFile1,Model_Name,',');
                cout << left << setw(mdlnm) << setfill(separator) << Model_Name;
                cust_ordrbnm.push_back(Model_Name);

                getline(breakFile1,Number_of_models_sold,',');
                cout << left << setw(ttlnmsld) << setfill(separator) << Number_of_models_sold;
                int quant1;
                stringstream convert5(Number_of_models_sold);
                convert5 >> quant1;
                cust_ordquant.push_back(quant1);

                getline(breakFile1,price,',');
                double price1;
                stringstream convert4(price);
                convert4 >> price1;
                cust_ordpri.push_back(price1);
                cout  << "$ " << left << setw(totalprc) << setfill(separator) << price << "\n";

                break;
            }
        }
        }
        myfile5.close();
    }
}
