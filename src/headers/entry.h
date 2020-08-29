/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

// Abstract class, represents a generic entry,
// is inherited by Group and Issue classes.

class Entry {
   protected:
    static int prev_id;
    const static int creation_date_length = 20;

    // Fields
    int id;
    int parent_id;
    std::string creation_date;
    std::string title;
    bool is_active;

   public:
    // Constructors
    Entry() {}
    Entry(std::string t, int pid = -1);
    Entry(int pid, std::string cd, std::string t);
    Entry(int id, int pid, std::string cd, std::string t, bool active = true);

    // Get fields
    int get_id() const { return id; }
    int get_parent_id() const { return parent_id; }
    virtual bool add_entry(Entry* e) { return false; }
    const std::string& get_creation_date() const { return creation_date; }
    const std::string& get_title() const { return title; }

    // Edit fields
    void set_title(std::string t) { title = t; }
    virtual bool delete_entry(int id);
    virtual void set_repository(std::string r) = 0;
    virtual void deactivate() = 0;
    virtual void activate() = 0;

    // Auxiliary methods
    virtual void print_info(const int level = 0) const = 0;

    virtual bool save_to_file(std::string file_path, bool overwrite = true) = 0;

    virtual Entry* get_copy() const = 0;
    virtual void clear() {}
};
