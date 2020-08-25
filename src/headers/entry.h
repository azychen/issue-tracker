/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Abstract class, represents a generic entry,
// is inherited by Group and Issue classes.

class Entry {
   protected:
    static int prev_id;
    const static int creation_date_length = 20;

    // Fields
    int id;
    int parent_id;
    string creation_date;
    string title;
    bool is_active;

   public:
    // Constructors
    Entry(int pid, string t);
    Entry(int pid, string cd, string t);
    Entry(int id, int pid, string cd, string t);

    // Get fields
    int get_id() const { return id; }
    int get_parent_id() const { return parent_id; }
    const string& get_creation_date() const { return creation_date; }
    const string& get_title() const { return title; }

    // Edit fields
    void set_title(string t) { title = t; }
    virtual void set_repository(string r) = 0;
    virtual void deactivate() = 0;

    // Auxiliary methods
    virtual void print_info(const int level = 0) const = 0;
    virtual Entry* copy();
};
