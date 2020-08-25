/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <chrono>
#include <ctime>

using namespace std;

// Abstract class, represents a generic entry,
// is inherited by Group and Issue classes.

class Entry {

   protected:
    static int prev_id;

    // Fields
    int id;
    int parent_id;
    char* creation_date;

    string title;


    bool is_active;

    unordered_set<string> tags;

   public:

    // Constructors
    Entry(int pid, string t);
    Entry(int pid, char* cd, string t);
    Entry(int id, int pid, char* cd, string t);

    // Get fields
    int get_id() const { return id; }
    int get_parent_id() const { return parent_id; }
    char* get_creation_date() const { return creation_date; }
    string get_title() const { return title; }

    // Edit fields
    void set_title(string t) { title = t; }
    virtual void set_repository(string r) = 0;
    virtual void deactivate() = 0;

    // Auxiliary functions
    virtual void print_info(const int level = 0) const = 0;
};
