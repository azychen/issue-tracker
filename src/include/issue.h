/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "entry.h"

class Issue : public Entry {
    std::string description;
    std::string repository;

   public:
    // Constructors
    Issue() {}
    Issue(std::string t, std::string d, std::string r, int pid = -1);
    Issue(int id, int pid, std::string cd, std::string t, std::string d, std::string r, bool active = true);

    // Get fields
    const std::string& get_description() const { return description; }
    const std::string& get_repository() const { return repository; }

    // Edit fields
    void set_description(std::string d) { description = d; }
    void set_repository(std::string r) { repository = r; }
    void activate() { is_active = true; };
    void deactivate() { is_active = false; };

    // Auxiliary methods
    void print_info(const int level = 0) const;

    bool can_add_entry() override { return false; }

    bool save_to_file(std::string file_path, bool overwrite = true) override;

    Entry* get_copy() const override;
};