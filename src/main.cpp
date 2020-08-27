/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include <iostream>
#include <string>

#include "headers/group.h"
#include "headers/issue.h"

using namespace std;

static int create_db(const char* dir);
static int create_table(const char* dir);

int main() {
    Group g(-1, "test_issues");

    g.add_new_issue("Change constructor",
                    "Fix order of arguments in constructor",
                    "https://github.com/azychen/issue-tracker");

    string str = "data/" + g.get_title() + ".csv";
    g.save_to_file(str);

    return 0;
}
