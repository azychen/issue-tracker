#include "../headers/group.h"

// Constructors

Group::Group(int id, int cd, string t, string d, string r)
    : Entry(id, cd, t, d, r) {}

Group::Group(int id, int cd, string t, string d, string r, vector<Entry&> es)
    : Entry(id, cd, t, d, r),
      subentries(es) {}

// Edit fields

void add_subentry(Entry& e) {

}

void Group::set_repository(string r) {
    repository = r;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        it->set_repository(r);
    }
}

void Group::deactivate() {
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        it->deactivate();
    }
    is_active = false;
}

void Group::printInfo() {
    cout << "ENTRY: " << title << '\n'
         << "DATE CREATED: " << creation_date << '\n'
         << "REPOSITORY: " << repository << '\n'
         << "DESCRIPTION: " << description << endl;
    cout << "SUB-ISSUES: " << endl;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        it->printInfo();
    }
}