#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "entry.h"

using namespace std;

class Group : public Entry {
    vector<Entry&> subentries;

   public:

    // Constructors

    Group(int id, int cd, string t, string d, string r);
    Group(int id, int cd, string t, string d, string r, vector<Entry&> es);

    // Edit fields
    void add_subentry(Entry& e);
    void set_repository(string r);
    void deactivate();

    // Auxiliary methods

    void printInfo();

};