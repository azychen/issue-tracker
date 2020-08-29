/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/issue.h"

// Constructors

Issue::Issue(std::string t, std::string d, std::string r, int pid)
    : Entry(t, pid),
      description(d),
      repository(r) {}

Issue::Issue(int id, int pid, std::string cd, std::string t, std::string d, std::string r, bool active)
    : Entry(id, pid, cd, t, active),
      description(d),
      repository(r) {}

// Auxiliary methods

void Issue::print_info(const int level) const {
    std::cout << std::string(level, '\t') << "ISSUE: " << title << '\n'
              << std::string(level, '\t') << "ID: " << id << '\n'
              << std::string(level, '\t') << "DATE CREATED: " << creation_date << '\n'
              << std::string(level, '\t') << "REPOSITORY: " << repository << '\n'
              << std::string(level, '\t') << "DESCRIPTION: " << description << std::endl;
}

bool Issue::save_to_file(std::string file_path, bool overwrite) {
    std::ofstream save_file;

    if (overwrite) {
        save_file.open(file_path, std::ios_base::trunc);
    } else {
        save_file.open(file_path, std::ios_base::app);
    }

    if (save_file.fail()) return false;

    save_file << id << ','
              << parent_id << ','
              << creation_date << ','
              << '\"' << title << '\"' << ','
              << is_active << ','
              << '\"' << description << '\"' << ','
              << '\"' << repository << '\"' << '\n';

    save_file.close();
    return true;
}

Entry* Issue::get_copy() const {
    Issue* res = new Issue(*this);
    return res;
}