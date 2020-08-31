#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "entry.h"
#include "group.h"

class App {
   private:
    const static std::string SAVE_PATH;
    Group* list;
    Entry* selected_entry;

   public:
    App() {}
    ~App() { delete list; }

    void create_new_list();
    void load_list_from_save();
    void add_new_issue();
    void add_new_group();

   private:
    std::string get_string_input();
    int get_int_input();
    void print_options(const std::unordered_map<int, std::string>& options);
};
