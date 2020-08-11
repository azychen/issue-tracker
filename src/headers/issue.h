#pragma once

#include <iostream>
#include <string>

#include "entry.h"

class Issue : public Entry {
    string description;
    string repository;

   public:
    // Constructors
    Issue(int id, int cd, string t, string d, string r);

    // Get fields
    string get_description() const { return description; }
    string get_repository() const { return repository; }

    // Edit fields
    void set_description(string d) { description = d; }
    void set_repository(string r);
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;
};