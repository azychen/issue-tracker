#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "entry.h"

using namespace std;

class Group : public Entry {
    vector<Entry*> subentries;

   public:

    // Constructors
    Group(int id, int cd, string t);
    Group(int id, int cd, string t, vector<Entry*> es);

    // Destructor
    ~Group();

    // Edit fields
    void set_repository(string r);
    void add_subentry(Entry* e);
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;
};