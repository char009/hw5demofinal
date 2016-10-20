#ifdef _MSC_VER
#include "stdafx.h"
#endif
#include "std_lib_facilities.h"
#include "component_info.h"
#include <string>
#include <iostream>
#include <iomanip>


void Component_Info::set_component_name()
{
    cout << "Please enter component name: ";
    getline(cin, component_name);
}

void Component_Info::set_part_number()
{
    cout << "Please enter part number: ";
    cin >> part_number;
    cin.clear();
    cin.ignore();
}

void Component_Info::set_component_weight()
{
    cout << "Please enter component weight(grams): ";
    cin >> component_weight;
    cin.clear();
    cin.ignore();
}

void Component_Info::set_component_cost()
{
    cout << "Please enter component cost($): ";
    cin >> component_cost;
    cin.clear();
    cin.ignore();
}

void Component_Info::set_part_description()
{
    cout << "Please enter part description: ";
    getline(cin, part_description);
}

void Component_Info::set_type()
{
    do
    {
        cout << "1) Locomotor\n";
        cout << "2) Arm\n";
        cout << "3) Battery\n";
        cout << "4) Torso\n";
        cout << "5) Head\n";
        cout << "Please enter type (1-5): ";
        cin >> type;
        cin.clear();
        cin.ignore();
    }while ((type > 5) || (type < 1));

    if (type == 1)
    {
        Locomotor locomotor(3.3, 150);
        locomotor.set_power_consumed_loc();
        locomotor.set_maxSpeed_loc();
        locmaxspd = locomotor.get_maxSpeed_loc();
        locpowcon = locomotor.get_power_consumed_loc();
        locomotor.print_maxSpeed_loc();
        locomotor.print_power_consumed_loc();
    }
    else if (type == 2)
    {
        Arm arm(3.3, 150);
        arm.set_power_consumed_arm();
        arm.set_maxSpeed_arm();
        arm.print_maxSpeed_arm();
        arm.print_power_consumed_arm();
    }
    else if (type == 3)
    {
        Battery battery(300, 1000);
        battery.set_maxPower_battery();
        battery.set_maxEnergy_battery();
        battery.print_maxPower_battery();
        battery.print_maxEnergy_battery();
    }
    else if (type == 4)
    {
        Torso torso(2);
        torso.set_battery_compartments();
        torso.print_battery_compartments();
    }
    else if (type == 5)
    {
        Head head;
    }
    else
    {
        cout << "IMPPOSSIBLE";
    }
}

void Component_Info::set_components()
{

    set_component_name();
    set_part_number();
    set_component_weight();
    set_component_cost();
    set_part_description();
}

string Component_Info::get_component_name()
{
    return component_name;
}

int Component_Info::get_part_number()
{
    return part_number;
}

double Component_Info::get_component_weight()
{
    return component_weight;
}

double Component_Info::get_component_cost()
{
    return component_cost;
}

string Component_Info::get_part_description()
{
    return part_description;
}

int Component_Info::get_type()
{
    return type;
}

void Component_Info::print_component_info()
{
    cout << "Name: " << component_name << endl;
    cout << "Part Number: " << part_number << endl;
    cout << "Component Weight: " << component_weight << " grams" << endl;
    cout << "Component Cost: $" << component_cost << endl;
    cout << "Part Description: " << part_description << endl;
    cout << "Part type: " << type << endl;
}
