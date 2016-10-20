#ifndef COMPONENT_INFO_H_INCLUDED
#define COMPONENT_INFO_H_INCLUDED

#include <iostream>
#include <string>

#include "locomotor.h"
#include "arm.h"
#include "battery.h"
#include "torso.h"
#include "head.h"


class Component_Info
{
private:
    string component_name;
    int part_number;
    double component_weight;
    double component_cost;
    string part_description;
    int type;
public:
    double locmaxspd, locpowcon;
    Component_Info (string cname,
                    int pnumber,
                    double cweight,
                    double ccost,
                    string pdescription,
                    int ptype) :

                    component_name(cname),
                    part_number(pnumber),
                    component_weight(cweight),
                    component_cost(ccost),
                    part_description(pdescription),
                    type(ptype) {}

    void set_component_name();
    void set_part_number();
    void set_component_weight();
    void set_component_cost();
    void set_part_description();
    void set_type();

    void set_components();

    string get_component_name();
    int get_part_number();
    double get_component_weight();
    double get_component_cost();
    string get_part_description();
    int get_type();

    void print_component_info();

};

#endif // COMPONENT_INFO_H_INCLUDED
