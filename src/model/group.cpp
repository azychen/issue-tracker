/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/group.h"

// Constructors

Group::Group(int pid, string t)
    : Entry(pid, t) {}

Group::Group(int id, int pid, string cd, string t)
    : Entry(id, pid, cd, t) {}

Group::Group(int id, int pid, string cd, string t, vector<Entry*> es)
    : Entry(id, pid, cd, t),
      subentries(es) {}

Group::Group(const Group& g) : Entry(g) {
    for (Entry* e : g.subentries) {
        subentries.push_back(e->get_copy());
    }
}

// Destructor
Group::~Group() {
    for (Entry* e : subentries) {
        delete e;
    }
}

// Copy assignment
Group& Group::operator=(const Group& g) {
    if (this != &g) {
        clear();
        parent_id = g.parent_id;
        id = g.id;
        creation_date = g.creation_date;
        title = g.title;
        for (Entry* e : g.subentries) {
            subentries.push_back(e->get_copy());
        }
    }
    return *this;
}

// Edit fields

void Group::set_repository(string r) {
    for (Entry* e : subentries) {
        e->set_repository(r);
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
    for (Entry* e : subentries) {
        e->deactivate();
    }
    is_active = false;
}

// Auxiliary methods

void Group::print_info(const int level) const {
    cout << string(level, '\t') << "GROUP: " << title << '\n'
         << string(level, '\t') << "ID: " << id << '\n'
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n';
    cout << string(level, '\t') << "SUB-ISSUES: " << endl;
    for (const Entry* const e : subentries) {
        cout << "\n";
        e->print_info(level + 1);
    }
}

Entry* Group::get_copy() const {
    Group* res = new Group(id, parent_id, creation_date, title);
    for (Entry* e : subentries) {
        res->subentries.push_back(e->get_copy());
    }
    return res;
}

void Group::clear() {
    for (Entry* e : subentries) {
        delete e;
    }
}