/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/entry.h"

#include <iostream>
#include <string>

using namespace std;

// Fields
int Entry::prev_id = 0;

// Constructors

Entry::Entry(int pid, string t)
    : id(++prev_id),
      parent_id(pid),
      title(t),
      creation_date(chrono::system_clock::to_time_t(chrono::system_clock::now())),
      is_active(true) {}

Entry::Entry(int pid, time_t cd, string t)
    : id(++prev_id),
      parent_id(pid),
      creation_date(cd),
      title(t),
      is_active(true) {}

Entry::Entry(int id, int pid, time_t cd, string t)
    : id(id),
      parent_id(pid),
      title(t),
      creation_date(cd),
      is_active(true) {}