#include <iostream>
#include <string>

#include "headers/entry.h"
#include "headers/issue.h"
#include "headers/group.h"

using namespace std;

int main() {
    cout << "Creating new entry: " << endl;
    Entry* e = new Group(1, 20, "Rubik's Cube Issues", "Issues related to the rubik's cube solver. ", "azychen/rubiks-cube-solver");
    e->print_info();
    return 0;
}