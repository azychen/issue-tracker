#include "../headers/entry.h"

#include <iostream>
#include <string>

using namespace std;

Entry::Entry(int id, int cd, string t, string d, string r)
    : id(id),
      creation_date(cd),
      title(t),
      description(d),
      repository(r),
      is_active(true) {}
