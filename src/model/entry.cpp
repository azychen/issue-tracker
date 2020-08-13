#include "../headers/entry.h"

#include <iostream>
#include <string>

using namespace std;

// Fields
int Entry::prev_id = 0;


// Constructors

Entry::Entry(int id, int pid, int cd, string t)
    : id(id),
      parent_id(pid),
      creation_date(cd),
      title(t),
      is_active(true) {}

Entry::Entry(int pid, int cd, string t)
    : id(++prev_id),
      parent_id(pid),
      creation_date(cd),
      title(t),
      is_active(true) {}
