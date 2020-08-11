#include "../headers/group.h"

// Constructors

Group::Group(int id, int cd, string t, string d, string r)
    : Entry(id, cd, t, d, r) {}

Group::Group(int id, int cd, string t, string d, string r, vector<Entry*> es)
    : Entry(id, cd, t, d, r),
      subentries(es) {}

// Edit fields

void Group::add_subentry(Entry* e) {
    // Check if entry exists with same id
    if (find(subentries.begin(), subentries.end(), e) == subentries.end()) {
        subentries.push_back(e);
    }
}

void Group::set_repository(string r) {
    repository = r;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        (*it)->set_repository(r);
    }
}

void Group::deactivate() {
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        (*it)->deactivate();
    }
    is_active = false;
}

void Group::print_info() const {
    cout << "ENTRY: " << title << '\n'
         << "DATE CREATED: " << creation_date << '\n'
         << "REPOSITORY: " << repository << '\n'
         << "DESCRIPTION: " << description << endl;
    cout << "SUB-ISSUES: " << endl;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        (*it)->print_info();
    }
}