#include <iostream>
#include <string>

#include "headers/issue.h"
#include "headers/group.h"

using namespace std;

int main() {
    cout << "Creating new entry:\n" << endl;
    Group* e = new Group(-1, 20, "Rubik's Cube Issues");
    
    // Issue* a1 = new Issue(e->get_parent_id(), 20, "Fix model", "Not working!", "azychen/rubiks-cube-solver");
    // Group* a2 = new Group(e->get_parent_id(), 20, "Cube Model Issues");
    // Issue* a3 = new Issue(e->get_parent_id(), 20, "Fix data generator", "Not fast enough!", "azychen/rubiks-cube-solver");
    
    
    e->add_new_issue(20, "Fix Model", "Not Working", "azychen/rubiks-cube-solver");
    e->add_new_group(20, "Cube Model Issues");
    e->add_new_issue(20, "Fix Data Generator", "Not fast enough!", "azychen/rubiks-cube-solver");

    e->print_info();
    return 0;
}