/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include <iostream>
#include <string>

#include "headers/group.h"
#include "headers/issue.h"

int main() {
    Group g;
    g.load_from_file("data/Issues.csv");
    g.print_info();

    // g2.add_new_issue("Change constructor",
    //                 "Fix order of arguments in constructor",
    //                 "https://github.com/azychen/issue-tracker");

    // g2.add_new_issue("Add string sanitizer",
    //                 "",
    //                 "https://github.com/azychen/issue-tracker");

    // Group g("Issues");
    // g.add_entry(&g2);
    // g.add_new_issue("Work out", "Push day baby", "");

    // g.save_to_file("data/" + g.get_title() + ".csv");

    return 0;
} 
