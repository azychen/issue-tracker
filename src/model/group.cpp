#include "../headers/group.h"

// Constructors

Group::Group(int id, int cd, string t)
    : Entry(id, cd, t) {}

Group::Group(int id, int cd, string t, vector<Entry*> es)
    : Entry(id, cd, t),
      subentries(es) {}


// Destructor

Group::~Group() {
    cout << "Deleting group " << title;
    for (auto sub : subentries) {
        delete sub;
    }
}

// Edit fields

void Group::set_repository(string r) {
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        (*it)->set_repository(r);
    }
}

void Group::add_subentry(Entry* e) {
    // Check if entry exists
    if (find(subentries.begin(), subentries.end(), e) == subentries.end()) {
        subentries.push_back(e);
    }
}

void Group::deactivate() {
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        (*it)->deactivate();
    }
    is_active = false;
}

void Group::print_info(const int level) const {
    cout << string(level, '\t') << "GROUP: " << title << '\n'
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n';
    cout << string(level, '\t') << "SUB-ISSUES: " << endl;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        cout << "\n";
        (*it)->print_info(level + 1);
    }
}