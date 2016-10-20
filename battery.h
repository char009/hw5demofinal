#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED
#include <string>


class Battery
{
private:
    double maxPower;
    double maxEnergy;
public:
    Battery(double mpower, double menergy) : maxPower(mpower), maxEnergy(menergy) { cout << "Battery Initialized\n";}
    void set_maxPower_battery()
    {
        cout << "Enter maximum power of battery(watts): ";
        cin >> maxPower;
        cin.clear();
        cin.ignore();
    }
    void set_maxEnergy_battery()
    {
        cout << "Enter energy of battery(Kilowatts hours): ";
        cin >> maxEnergy;
        cin.clear();
        cin.ignore();
    }
    double get_maxPower_battery()
    {
        return maxPower;
    }
    double get_maxEnergy_battery()
    {
        return maxEnergy;
    }
    void print_maxPower_battery()
    {
        cout << "Max power of battery is: " << maxPower << " Watts" << endl;
    }
    void print_maxEnergy_battery()
    {
        cout << "Energy of battery is: " << maxEnergy << " Kilowatt-Hour" << endl;
    }
};

#endif // BATTERY_H_INCLUDED
