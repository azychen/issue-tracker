#pragma once

#include <iostream>
#include <map>
#include <string>
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

    void run();

    void create_new_list();
    void load_list_from_save();
    void add_new_issue();
    void add_new_group();

    void set_title(const std::string& t);
    void set_description(const std::string& d);
    void set_repository(const std::string& r);

   private:
    std::map<int, std::string> get_saves(std::string file_path);

    void print_selected_entry();
    void print_menu();
    void print_options(const std::map<int, std::string>& options);
    void print_header();
    
    std::string get_string_input();
    int get_int_input(int min, int max);

    





    void clear_terminal();

};
