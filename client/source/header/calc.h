#ifndef ENGINE_CPP
#define ENGINE_CPP

#include <vector>
#include "unit.h"

class calc{
private:
    F_X, F_Y;
    vector<int> fields, AT;
    double time, time_prev;
    unit def_2, def_3, def_4, at_5, at_6, at_7;

public:
    calc(vector<int> AT,vector<int> fields, double time, double time_prev):time(time),AT(AT),fields(fields), time_prev(time_prev){};
    void road();
    int ff(int, int);
};

#endif