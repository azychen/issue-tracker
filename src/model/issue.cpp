#include "../headers/issue.h"

// Constructors
Issue::Issue(int id, int cd, string t, string d, string r)
    : Entry(id, cd, t),
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
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n'
         << string(level, '\t') << "REPOSITORY: " << repository << '\n'
         << string(level, '\t') << "DESCRIPTION: " << description << endl;
}