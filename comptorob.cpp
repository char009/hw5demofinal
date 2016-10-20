#include "comptorob.h"
#include <string>
#include <iostream>

void comptorob::comtorob(int loc3, int arm3, int bat3, int tor3, int hea3, string finall)
{
    string line1;
    string name1="",extra="";
    int i=1;
    ofstream myfile1,myfile2;
    cin.clear();
    cin.ignore();

    //cout << finall;
    myfile1.open ("robotcatalog.txt",ios::app);

    ifstream myfile3("locomotor.txt");

            if (myfile3.is_open())
              {
                line1="";
                while (getline (myfile3,line1) )
                {

                  ofstream ofs1;
                  ofs1.open("test2.txt");
                  ofs1 <<line1;
                  ofs1.close();

                  ifstream breakFile1("test2.txt");

                while(breakFile1 && i<=loc3)
                    {
                      name1="";
                      extra="";
                      getline (breakFile1,name1,',');
                      getline (breakFile1,extra);
                      i++;
                    break;
                    }
                }
              }
            finall+=","+name1;
            myfile3.close();

            name1="";
            extra="";
            line1="";
            // ,Loco,arm,battery,torso,head :

            // display Arm here
            i=1;
            ifstream myfile4("arm.txt");

            if (myfile4.is_open())
              {
                line1="";
                while (getline (myfile4,line1) )
                {

                  ofstream ofs1;
                  ofs1.open("test2.txt");
                  ofs1 <<line1;
                  ofs1.close();

                  ifstream breakFile1("test2.txt");

                while(breakFile1 && i<=arm3)
                    {
                      name1="";
                      extra="";
                      getline (breakFile1,name1,',');
                      getline (breakFile1,extra);
                      i++;
                    break;
                    }
                }
              }
             finall+=","+name1;
             myfile4.close();

             name1="";
             extra="";
             line1="";

            // battery,torso,head :

            // display battery here
            i=1;
            ifstream myfile5("battery.txt");

            if (myfile5.is_open())
              {
                line1="";
                while (getline (myfile5,line1) )
                {
                  ofstream ofs1;
                  ofs1.open("test2.txt");
                  ofs1 <<line1;
                  ofs1.close();

                  ifstream breakFile1("test2.txt");

                while(breakFile1 && i<=bat3)
                    {
                      name1="";
                      extra="";
                      getline (breakFile1,name1,',');
                      getline (breakFile1,extra);
                      i++;
                    break;
                    }
                }
              }
             finall+=","+name1;
             myfile5.close();

             name1="";
             extra="";
             line1="";

            // torso,head :

            // display battery here
            i=1;
            ifstream myfile6("torso.txt");

            if (myfile6.is_open())
              {
                line1="";
                while (getline (myfile6,line1) )
                {
                  ofstream ofs1;
                  ofs1.open("test2.txt");
                  ofs1 <<line1;
                  ofs1.close();
                  ifstream breakFile1("test2.txt");

                while(breakFile1 && i<=tor3)
                    {
                      name1="";
                      extra="";
                      getline (breakFile1,name1,',');
                      getline (breakFile1,extra);
                      i++;
                    break;
                    }
                }
              }
             finall+=","+name1;
             myfile6.close();

             name1="";
             extra="";
             line1="";
             // head :

            // display head here
            i=1;
            ifstream myfile7("head.txt");

            if (myfile7.is_open())
              {
                line1="";
                while (getline (myfile7,line1) )
                {
                  ofstream ofs1;
                  ofs1.open("test2.txt");
                  ofs1 <<line1;
                  ofs1.close();

                  ifstream breakFile1("test2.txt");

                while(breakFile1 && i<=hea3)
                    {
                      name1="";
                      extra="";
                      getline (breakFile1,name1,',');
                      getline (breakFile1,extra);
                      i++;
                    break;
                    }
                }
              }
             finall+=","+name1;
             myfile7.close();

            myfile1<<"\n"<<finall;

            myfile1.close();

}
