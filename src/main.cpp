/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "group.h"
#include "issue.h"

int main() {
    // // save file

    // Group g2("Issue Tracker");
    // g2.add_new_issue("Fix .csv parser", "", "https://github.com/azychen/issue-tracker");
    // g2.add_new_issue("Add wxWidgets GUI", "", "https://github.com/azychen/issue-tracker");

    // Group g3("Rubik's Cube Solver");
    // g3.add_new_issue("Add matplotlib GUI", "", "https://github.com/azychen/ai-rubiks-cube-solver");

    // Group g1("Anton's List");
    // g1.add_entry(&g2);
    // g1.add_entry(&g3);
    // g1.add_new_issue("Work out more", "At least 5 times a week", "");

    // g1.save_to_file("data/test.csv");

    // load file
    Group g;
    g.load_from_file("data/test.csv");
    g.print_info();

    return 0;
}