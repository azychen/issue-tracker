
#include "../headers/issue.h"

// Constructors
Issue::Issue(int id, int cd, string t, string d, string r)
    : Entry(id, cd, t, d, r) {}


// Edit fields

void Issue::set_repository(string r) {
    repository = r;
}

void Issue::deactivate() {
    is_active = false;
}


// Auxiliaray methods

void Issue::printInfo() {
    cout << "ENTRY: " << title << '\n'
         << "DATE CREATED: " << creation_date << '\n'
         << "REPOSITORY: " << repository << '\n'
         << "DESCRIPTION: " << description << endl;
}