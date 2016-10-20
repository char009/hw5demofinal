#include <string>
#include <iostream>
#include "productmanager.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "std_lib_facilities.h"
#include "component_info.h"
#include "robot_model.h"
#include "menu.h"
#include "vector"
#include "comptorob.h"
#include "customer.h"

void ProductManager::getcompinfo()
{
    Component_Info component_info("R-Arm-1", 1201, 250.5, 250.99, "Robot Arm for sale", 1);
    int cmptype;
            string cp1, cw1, cpr1, ptype1;
            component_info.set_type();
            cmptype = component_info.get_type();
            char fileNM[20];

            if (cmptype == 1) strcpy(fileNM,"locomotor.txt");
            else if (cmptype == 2) strcpy(fileNM,"arm.txt");
            else if (cmptype == 3) strcpy(fileNM,"battery.txt");
            else if (cmptype == 4) strcpy(fileNM,"torso.txt");
            else if (cmptype == 5) strcpy(fileNM,"head.txt");

            component_info.set_components();

            component_info.print_component_info();
            vec1.push_back(component_info);

            string info, info2, temp;
            ofstream myfile;
            ofstream myfile2;

            myfile.open ("catalog.txt",ios::app);
            myfile2.open (fileNM,ios::app);


            cp1 = to_string(component_info.get_part_number());
            cw1 = to_string(component_info.get_component_weight());
            cpr1 = to_string(component_info.get_component_cost());
            ptype1 = to_string(component_info.get_type());
            info = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + ptype1 + "," + component_info.get_part_description();

            if (cmptype == 1) info2 = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + component_info.get_part_description() + "," + to_string(component_info.locmaxspd) + "," + to_string(component_info.locpowcon);
            else if (cmptype == 2) info2 = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + component_info.get_part_description();
            else if (cmptype == 3) info2 = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + component_info.get_part_description();
            else if (cmptype == 4) info2 = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + component_info.get_part_description();
            else if (cmptype == 5) info2 = component_info.get_component_name() + "," + cp1 + "," + cw1 + "," + cpr1 + "," + component_info.get_part_description();

            myfile<<"\n"<<info;
            myfile2<<"\n"<<info2;
            myfile.close();
            myfile2.close();
}

void ProductManager::getrobotinfo()
{
    Robot_Model robot_model("Robot-1", 9901, 699.99, "The first ever model!", 749.99, 35, 150);
string mp1, mpr1, mprs1, nosld1, mw1;
            int rchoice = 1;
            int crchoice;
            char fileNM2[20];
            string mntofile, locm, armm, batm, torm, heam;
            int locmi, armmi, batmi, tormi, heami;
            string robcomp;

            do
            {
                if (rchoice == 1) strcpy(fileNM2,"locomotor.txt");
                else if (rchoice == 2) strcpy(fileNM2,"arm.txt");
                else if (rchoice == 3) strcpy(fileNM2,"battery.txt");
                else if (rchoice == 4) strcpy(fileNM2,"torso.txt");
                else if (rchoice == 5) strcpy(fileNM2,"head.txt");

                ifstream myfile3;

                myfile3.open (fileNM2,ios::app);

                const char separator = ' ';
                const int nameWidth = 20;
                const int partnoWidth = 20;
                const int compWeight = 20;
                const int partprice = 20;
                const int partdescrip = 20;

                cout << "No\t" << left << setw(nameWidth) << setfill(separator) << "Comp_Name"
                     << left << setw(partnoWidth) << setfill(separator) << "Part_No"
                     << left << setw(compWeight) << setfill(separator) << "Comp_Weight"
                     << left << setw(partprice) << setfill(separator) << "Comp_Cost"
                     << left << setw(partdescrip) << setfill(separator) << "Part_Desc" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;

                try
                {

                    if (myfile3.is_open())
                    {
                        int cnt=0;
                        while (getline(myfile3,line))
                        {
                            ofstream ofs;
                            ofs.open("test.txt");
                            ofs << line;
                            ofs.close();
                            ifstream breakFile("test.txt");

                            while(breakFile)
                            {

                                string parts="";
                                string name="";

                                getline (breakFile,name,',');
                                cnt++;
                                cout<< "\n" << cnt << "\t" << left << setw(nameWidth) << setfill(separator) << name;

                                getline (breakFile,parts,',');
                                int part_num=0;
                                stringstream convert(parts);
                                convert>>part_num;
                                cout << left << setw(partnoWidth-2) << setfill(separator) << part_num << "  ";
                                parts="";

                                getline (breakFile,parts,',');
                                double weight=0;
                                stringstream convert1(parts);
                                convert1>>weight;
                                cout << left << setw(compWeight-2) << setfill(separator) << weight << "  ";
                                parts="";

                                getline (breakFile,parts,',');
                                double price=0;
                                stringstream convert2(parts);
                                convert2>>price;
                                cout << left << setw(partprice-1) << setfill(separator) << price << " ";
                                parts="";

                                string description;
                                getline (breakFile,description,',');
                                cout<<description<<"  ";

                                break;
                            }
                        }
                        cout << "\n";


                        if (rchoice == 1)
                        {
                            do{
                            cout << "\nPlease Enter Locomotor: ";
                            cin >> crchoice;
                            cin.clear();
                            cin.ignore();
                            locmi = crchoice;
                            locm = to_string(crchoice);
                            }while((crchoice < 1) || (crchoice > cnt));

                        }
                        else if (rchoice == 2)
                        {
                            do{
                            cout << "\nNOTE: Arm will be used twice as two arms are needed.";
                            cout << "\nPlease Enter Arm: ";
                            cin >> crchoice;
                            cin.clear();
                            cin.ignore();
                            armmi = crchoice;
                            armm = to_string(crchoice);
                            }while((crchoice < 1) || (crchoice > cnt));

                        }
                        else if (rchoice == 3)
                        {
                            do{
                            cout << "\nPlease Enter Battery: ";
                            cin >> crchoice;
                            cin.clear();
                            cin.ignore();
                            batmi = crchoice;
                            batm = to_string(crchoice);
                            }while((crchoice < 1) || (crchoice > cnt));

                        }
                        else if (rchoice == 4)
                        {
                            do{
                            cout << "\nPlease Enter Torso: ";
                            cin >> crchoice;
                            cin.clear();
                            cin.ignore();
                            tormi = crchoice;
                            torm = to_string(crchoice);
                            }while((crchoice < 1) || (crchoice > cnt));

                        }
                        else if (rchoice == 5)
                        {
                            do{
                            cout << "\nPlease Enter Head: ";
                            cin >> crchoice;
                            cin.clear();
                            cin.ignore();
                            heami = crchoice;
                            heam = to_string(crchoice);
                            }while((crchoice < 1) || (crchoice > cnt));

                        }
                        cout << endl << endl;

                        myfile3.close();
                    }
                }
                catch(exception& e) { cout << "ERROR";}
                rchoice++;

            }while(rchoice < 6);

            robot_model.set_model_name();
            robot_model.set_model_number();
            robot_model.set_model_price();
            robot_model.set_model_sales_price();
            robot_model.set_number_sold();
            robot_model.set_total_weight();
            robot_model.set_model_description();
            robot_model.print_robot_model();
            vec2.push_back(robot_model);

            mntofile = to_string(robot_model.get_model_number());

            robcomp =  mntofile + "," + locm + "," +  armm + "," +  batm + "," +  torm + "," +  heam;

            ofstream myfile3;
            myfile3.open ("robotcomp.txt",ios::app);

            myfile3<<"\n"<<robcomp;
            myfile3.close();

            string info2, temp2;
            ofstream myfile2;

            myfile2.open ("robotcatalog.txt",ios::app);

            mp1 = to_string(robot_model.get_model_number());
            mpr1 = to_string(robot_model.get_model_price());
            mprs1 = to_string(robot_model.get_model_sales_price());
            nosld1 = to_string(robot_model.get_number_sold());
            mw1 = to_string(robot_model.get_total_weight());
            info2 = robot_model.get_model_name() + "," + mp1 + "," + mprs1 + "," + nosld1 + "," + mw1 + "," + robot_model.get_model_description();

            comptorob a;
            a.comtorob(locmi, armmi, batmi, tormi, heami, info2);

            myfile2.close();
}

void ProductManager::printrbt()
{
    const char separator1 = ' ';
    const int nameWidth1 = 13;
    const int rpartno1 = 16;
    const int rprice1 = 15;
    const int rquant1 = 12;
    const int rweight1 = 13;
    const int rdescrip1 = 14;
    int cntt;
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
                    nm.push_back(name1);
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


    do{
    cout << "\nEnter Index no of robot for more info: ";
    cin >> indexno;
    cin.clear();
    cin.ignore();
    }while((indexno < 1) || (indexno > cntt));

    int j = indexno;

    cout << "Robot Model Name: " << nm.at(j-1) << endl;
    cout << "Locomotor part name: " << locom1.at((j-1)) << endl;
    cout << "Arm part name: " << armm1.at((j-1)) << endl;
    cout << "Battery part name: " << battr1.at((j-1)) << endl;
    cout << "Torso part name: " << torsoo1.at((j-1)) << endl;
    cout << "Head part name: " << headd1.at((j-1)) << endl;
}


void ProductManager::printcmpt()
{
    const char separator = ' ';
    const int nameWidth = 17;
    const int partnoWidth = 10;
    const int compWeight = 10;
    const int partprice = 14;
    const int partdescrip = 14;

    string p1type;

    try
    {
        cout  <<"Comp_Name"
        << setw(15) << "Part_No"
        << setw(16) << "Comp_Weight"
        << setw(10) << "Comp_Cost"
        << setw(15) << "Part_Type"
        << setw(15) << "Part_Desc" << setw(20) << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        ifstream myfile ("catalog.txt");
        if (myfile.is_open())
        {
            while (getline(myfile,line))
            {
                ofstream ofs;
                ofs.open("test.txt");
                ofs << line;
                ofs.close();
                ifstream breakFile("test.txt");

                while(breakFile)
                {
                    string parts="";
                    string name="";

                    //Get and print name from file
                    getline (breakFile,name,',');
                    cout<< "\n" << left << setw(nameWidth) << setfill(separator) << name;

                    //Get and print part number
                    getline (breakFile,parts,',');
                    int part_num=0;
                    stringstream convert(parts);
                    convert>>part_num;
                    cout << left << setw(partnoWidth) << setfill(separator) << part_num << "  ";
                    parts="";

                    //Get and print part weight
                    getline (breakFile,parts,',');
                    double weight=0;
                    stringstream convert1(parts);
                    convert1>>weight;
                    cout << left << setw(compWeight) << setfill(separator) << weight << "  ";
                    parts="";

                    //Get and print part price
                    getline (breakFile,parts,',');
                    double price=0;
                    stringstream convert2(parts);
                    convert2>>price;
                    cout << left << setw(partprice) << setfill(separator) << price << " ";
                    parts="";

                    //Get type number and print type accordingly
                    getline (breakFile,parts,',');
                    int type=0;
                    stringstream convert3(parts);
                    convert3>>type;
                    if(type == 1) p1type = "Locomotor";
                    else if(type == 2) p1type = "Arm";
                    else if(type == 3) p1type = "Battery";
                    else if(type == 4) p1type = "Torso";
                    else if(type == 5) p1type = "Head";
                    cout << left << setw(partdescrip) << setfill(separator) << p1type << " ";
                    parts="";

                    //Get and print part description
                    string description;
                    getline (breakFile,description,',');
                    cout<<description<<"  ";

                    Component_Info ci(name,  part_num, weight,
                    price, description, type);
                    vec1_ci.push_back(ci);

                    break;
                }
            }
            cout << "\n";
            myfile.close();
        }
    }
    catch(exception& e)
    { }
}
