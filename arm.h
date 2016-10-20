#ifndef ARM_H_INCLUDED
#define ARM_H_INCLUDED
#include <string>

class Arm
{
private:
    double maxSpeed;
    double powerConsumed;
public:
    Arm(double speed, double power) : maxSpeed(speed) , powerConsumed(power) { cout << "Arm Initialized\n";}
    void set_power_consumed_arm()
    {
        cout << "Enter power consumed by arm(watts): ";
        cin >> powerConsumed;
        cin.clear();
        cin.ignore();
    }
    void set_maxSpeed_arm()
    {
        cout << "Enter max speed of arm(MPH): ";
        cin >> maxSpeed;
        cin.clear();
        cin.ignore();
    }
    double get_power_consumed_arm()
    {
        return powerConsumed;
    }
    double get_maxSpeed_arm()
    {
        return maxSpeed;
    }
    void print_power_consumed_arm()
    {
        cout << "Power Consumed by arm: " << powerConsumed << " Watts" << endl;
    }
    void print_maxSpeed_arm()
    {
        cout << "Max speed of arm: " << maxSpeed << " MPH" << endl;
    }

};

#endif // ARM_H_INCLUDED
