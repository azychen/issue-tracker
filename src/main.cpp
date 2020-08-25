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
    Group* e = new Group(-1, "Rubik's Cube Issues");
    
    e->add_new_issue("Fix Model", "Not Working", "azychen/rubiks-cube-solver");
    e->add_new_group("Cube Model Issues");
    e->add_new_issue("Fix Data Generator", "Not fast enough!", "azychen/rubiks-cube-solver");

    e->print_info();

    // const char* dir = ".\\data\\entries.db";
    // sqlite3* db;

    // create_db(dir);
    // create_table(dir);

    return 0;
}

// static int create_db(const char* dir) {
//     sqlite3* db;
//     int exit = 0;

//     exit = sqlite3_open(dir, &db);
//     sqlite3_close(db);

//     return 0;
// }

// static int create_table(const char* dir) {
//     sqlite3* db;

//     string sql = "CREATE TABLE IF NOT EXISTS Entries ("
//         "ID INTEGER PRIMARY KEY, "
//         "ParentID INTEGER, "
//         "CreationDate TEXT NOT NULL,"
//         "Title TEXT NOT NULL, "
//         "Description TEXT, "
//         "Repository TEXT );";

//     try {
//         int exit = 0;
//         exit = sqlite3_open(dir, &db);

//         char* messageError;
//         exit = sqlite3_exec(db, sql.c_str(), nullptr, 0, &messageError);

//         if (exit != SQLITE_OK) {
//             cerr << "Error Creating Table.\n";
//             sqlite3_free(messageError);
//         } else {
//             cout << "Table Created Successfully.\n";
//         };

//         sqlite3_close(db);

//     } catch (const exception& e) {
//         cerr << e.what();
//     }

//     return 0;
// }