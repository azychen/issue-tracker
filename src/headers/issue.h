/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <iostream>
#include <string>

#include "entry.h"

class Issue : public Entry {
    string description;
    string repository;

   public:
    // Constructors
    Issue(int pid, string t, string d, string r);
    Issue(int id, int pid, string cd, string t, string d, string r);

    // Get fields
    const string& get_description() const { return description; }
    const string& get_repository() const { return repository; }

    // Edit fields
    void set_description(string d) { description = d; }
    void set_repository(string r);
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;
    Entry* get_copy() const override;
};