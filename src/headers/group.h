/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "entry.h"
#include "issue.h"

using namespace std;

class Group : public Entry {
    vector<Entry*> subentries;

   public:

    // Constructors
    Group(int pid, int cd, string t);
    Group(int id, int pid, int cd, string t);
    Group(int id, int pid, int cd, string t, vector<Entry*> es);

    // Destructor
    ~Group();

    // Edit fields
    void set_repository(string r);
    void add_new_issue(int cd, string t, string d, string r);
    void add_new_group(int cd, string t);
    void add_subentry(Entry* e);
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;
};