#include <iostream>
#include <string>

#include "headers/entry.h"
#include "headers/issue.h"
#include "headers/group.h"

using namespace std;

int main() {
    cout << "Creating new entry:\n" << endl;
    Group* e = new Group(1, 20, "Rubik's Cube Issues");
    
    Issue* a1 = new Issue(2, 20, "Fix model", "Not working!", "azychen/rubiks-cube-solver");
    Group* a2 = new Group(4, 20, "Cube Model Issues");
    Issue* a3 = new Issue(3, 20, "Fix data generator", "Not fast enough!", "azychen/rubiks-cube-solver");
    
    
    e->add_subentry(a1);
    e->add_subentry(a2);
    e->add_subentry(a3);
    e->add_subentry(a3);

    a2->add_subentry(a3);

    e->print_info();
    return 0;
}