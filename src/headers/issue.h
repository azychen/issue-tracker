#pragma once

#include <iostream>
#include <string>

#include "entry.h"

class Issue : public Entry {

   public:

    // Constructors
    Issue(int id, int cd, string t, string d, string r);

    // Edit fields
    void set_repository(string r);
    void deactivate();

    // Auxiliary methods
    void printInfo();
};