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
    Group(int pid, string t);
    Group(int id, int pid, char* cd, string t);
    Group(int id, int pid, char* cd, string t, vector<Entry*> es);

    // Destructor
    ~Group();

    // Auxiliary methods
    void print_info(const int level = 0) const;

    // Edit fields
    void set_repository(string r);
    void add_new_issue(string t, string d, string r);
    void add_new_group(string t);
    void add_subentry(Entry* e);
    void deactivate();
};