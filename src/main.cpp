/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include <iostream>
#include <string>

#include "headers/group.h"
#include "headers/issue.h"

int main() {
    // save file

    // Group g("Issue List");
    // g.add_new_issue("Work out", "Push day baby", "");

    // g.save_to_file("data/" + g.get_title() + ".csv");

    // load file
    Group g2;
    g2.load_from_file("data/Issue List.csv");
    g2.print_info();

    return 0;
}
