#include <iostream>
#include <string>

#include "../headers/entry.h"

using namespace std;

Entry::Entry(int cd, string t, string d, string r) : creation_date(cd), title(t), description(d), repository(r) {}

void Entry::printInfo() {
    cout << "Entry: " << title << '\n'
         << "Date created: " << creation_date << '\n'
         << "From repository: " << repository << '\n'
         << "Description: " << description << endl;
}