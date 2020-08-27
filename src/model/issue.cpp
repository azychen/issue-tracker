/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/issue.h"

// Constructors

Issue::Issue(int pid, string t, string d, string r)
    : Entry(pid, t),
      description(d),
      repository(r) {}

Issue::Issue(int id, int pid, string cd, string t, string d, string r)
    : Entry(id, pid, cd, t),
      description(d),
      repository(r) {}

// Auxiliary methods

void Issue::print_info(const int level) const {
    cout << string(level, '\t') << "ISSUE: " << title << '\n'
         << string(level, '\t') << "ID: " << id << '\n'
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n'
         << string(level, '\t') << "REPOSITORY: " << repository << '\n'
         << string(level, '\t') << "DESCRIPTION: " << description << endl;
}

bool Issue::save_to_file(string file_path, bool overwrite) {
    ofstream save_file;

    save_file.open(file_path, ((overwrite) ? ios_base::trunc : ios_base::app));
    if (save_file.fail()) return false;

    save_file << id << ','
              << parent_id << ','
              << creation_date << ','
              << title << ','
              << is_active << ','
              << description << ','
              << repository << '\n';
    
    save_file.close();
    return true;
}

Entry* Issue::get_copy() const {
    Issue* res = new Issue(*this);
    return res;
}