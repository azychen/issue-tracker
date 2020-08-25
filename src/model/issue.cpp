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

// Edit fields

void Issue::set_repository(string r) {
    repository = r;
}

void Issue::deactivate() {
    is_active = false;
}

// Auxiliary methods

void Issue::print_info(const int level) const {
    cout << string(level, '\t') << "ISSUE: " << title << '\n'
         << string(level, '\t') << "ID: " << id << '\n'
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n'
         << string(level, '\t') << "REPOSITORY: " << repository << '\n'
         << string(level, '\t') << "DESCRIPTION: " << description << endl;
}

Entry* Issue::copy() {
    Issue* res = new Issue(*this);
    return res; 
}