/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "entry.h"
#include "issue.h"

class Group : public Entry {
    std::vector<Entry*> subentries;

   public:
    // Constructors
    Group() {}
    Group(std::string t, int pid = -1);
    Group(int id, int pid, std::string cd, std::string t, bool active = true);
    Group(const Group& g);

    // Destructor
    ~Group();

    // Copy assignment
    Group& operator=(const Group& g);

    // Get fields
    const std::vector<Entry*>& get_subentries() { return subentries; }

    // Edit fields
    void set_repository(std::string r);
    bool add_entry(Entry* e) override;
    void add_new_issue(std::string t, std::string d, std::string r);
    void add_new_group(std::string t);
    bool delete_entry(int id) override;

    void activate();
    void deactivate();

    // Auxiliary methods
    void print_info(const int level = 0) const;

    bool save_to_file(std::string file_path, bool overwrite = true) override;
    void load_from_file(std::string file_path);

    Entry* get_copy() const override;
    void copy(const Group& g);
    void clear() override;

   private:
    std::vector<Entry*> get_entries_from_file(const std::string& file_path);
    Entry* parse_line(const std::string& line);
    std::vector<std::string> get_fields_from_line(const std::string& line);
    void assign_fields(Entry* e);
};