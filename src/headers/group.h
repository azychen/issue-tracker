/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "entry.h"
#include "issue.h"

using namespace std;

class Group : public Entry {
    vector<Entry*> subentries;

   public:
    // Constructors
    Group(int pid, string t);
    Group(int id, int pid, string cd, string t);
    Group(int id, int pid, string cd, string t, vector<Entry*> es);

    Group(const Group& g);

    // Destructor
    ~Group();

    // Copy assignment
    Group& operator=(const Group& g);

    // Edit fields
    void set_repository(string r);
    void add_new_issue(string t, string d, string r);
    void add_new_group(string t);
    void add_subentry(Entry* e);
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;
    Entry* get_copy() const override;
    void copy(const Group& g);
    void clear();
};