/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/group.h"

// Constructors
Group::Group(int pid, string t)
    : Entry(pid, t) {}

Group::Group(int id, int pid, time_t cd, string t)
    : Entry(id, pid, cd, t) {}

Group::Group(int id, int pid, time_t cd, string t, vector<Entry*> es)
    : Entry(id, pid, cd, t),
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

// Add new issue to group
void Group::add_new_issue(string t, string d, string r) {
    Entry* e = new Issue(id, t, d, r);
    add_subentry(e);
}

// Add new subgroup to group
void Group::add_new_group(string t) {
    Entry* g = new Group(id, t);
    add_subentry(g);
}

// Add existing entry to group
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
    char buff[20];
    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&creation_date));

    cout << string(level, '\t') << "GROUP: " << title << '\n'
         << string(level, '\t') << "ID: " << id << '\n'
         << string(level, '\t') << "DATE CREATED: " << buff << '\n';
    cout << string(level, '\t') << "SUB-ISSUES: " << endl;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        cout << "\n";
        (*it)->print_info(level + 1);
    }
}