#include "../headers/entry.h"

#include <iostream>
#include <string>

using namespace std;

Entry::Entry(int id, int cd, string t)
    : id(id),
      creation_date(cd),
      title(t),
      is_active(true) {}
