/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include <iostream>
#include <string>

#include "headers/issue.h"
#include "headers/group.h"

using namespace std;

static int create_db(const char* dir);
static int create_table(const char* dir);

int main() {
    cout << "Creating new entry:\n" << endl;
    Group e(-1, "Rubik's Cube Issues");

    e.add_new_issue("Fix Model", "Not Working", "azychen/rubiks-cube-solver");
    e.add_new_group("Cube Model Issues");
    e.add_new_issue("Fix Data Generator", "Not fast enough!", "azychen/rubiks-cube-solver");

    e.set_repository("Changed repository");

    e.print_info();


    return 0;
}

