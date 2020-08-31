#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "entry.h"
#include "group.h"

class App {
   private:
    Group* list;
    Entry* selected_entry; 

   public:
    App();
    App(const std::string& t);
    App(Group* g);

    ~App();

    bool load_list_from_save(const std::string& file_path);
    void add_new_issue();
    void add_new_group();
};
