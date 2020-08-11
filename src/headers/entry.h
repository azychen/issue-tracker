#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Abstract class, represents a generic entry,
// is inherited by Group and Issue classes.

class Entry {

   protected:

    // Fields
    int id;
    int creation_date;

    string title;
    string description;
    string repository;

    bool is_active;

    unordered_set<string> tags;

   public:

    // Constructors
    Entry(int id, int cd, string t, string d, string r);

    // Edit fields
    void set_title(string t) { title = t; }
    void set_description(string d) { description = d; }
    virtual void set_repository(string r) = 0;
    virtual void deactivate() = 0;

    // Auxiliary functions
    virtual void print_info() const = 0;
};
