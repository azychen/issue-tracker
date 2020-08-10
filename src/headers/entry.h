#pragma once

#include <iostream>
#include <string>

using namespace std;

class Entry {
    int creation_date;
    string title;
    string description;
    string repository;

   public:
    Entry(int cd, string t, string d, string r);
    void printInfo();
};
