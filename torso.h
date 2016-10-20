#ifndef TORSO_H_INCLUDED
#define TORSO_H_INCLUDED
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

class Torso
{
private:
    int battery_compartments;
public:
    Torso(int batterycomp) : battery_compartments(batterycomp) { cout << "Torso Initialized\n";}
    void set_battery_compartments()
    {
        do
        {
            cout << "Enter maximum battery compartments (1-3 only): ";
            cin >> battery_compartments;
            cin.clear();
            cin.ignore();
        }while ((battery_compartments > 3) || (battery_compartments < 1));
    }
    int get_battery_compartments()
    {
        return battery_compartments;
    }
    void print_battery_compartments()
    {
        cout << "The maximum battery compartments for the torso is " << battery_compartments << endl;
    }
};

#endif // TORSO_H_INCLUDED
