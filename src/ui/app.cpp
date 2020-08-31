#include "app.h"

#include <filesystem>

const std::string App::SAVE_PATH = "data/";

void App::run() {
    print_header();
    std::map<int, std::string> saves = get_saves(SAVE_PATH);
    if (saves.empty()) {
        create_new_list();
    } else {
        load_list_from_save();
    }
}

void App::create_new_list() {
    std::cout << "What do you want to call your list?\n"
              << "Please enter name:" << std::endl;
    std::string name = get_string_input();
    list = new Group(name);
    selected_entry = list;
}

void App::load_list_from_save() {
    std::map<int, std::string> save_paths = get_saves(SAVE_PATH);

    std::cout << "What list would you like to load? Enter num: " << std::endl;
    print_options(save_paths);
    int input = get_int_input(save_paths.begin()->first, save_paths.rbegin()->first);

    std::string save_path = SAVE_PATH + save_paths[input];

    clear_terminal();

    if (!list) {
        list = new Group();
    }
    list->load_from_file(save_path);
    selected_entry = list;
}

void App::add_new_issue() {
    if (selected_entry && selected_entry->can_add_entry()) {
        std::string t, d, r;

        std::cout << "Enter issue title: " << std::endl;
        t = get_string_input();

        std::cout << "Enter issue description: " << std::endl;
        d = get_string_input();

        std::cout << "Enter issue repository link: " << std::endl;
        r = get_string_input();

        Entry* new_entry = new Issue(t, d, r, selected_entry->get_id());
        std::cout << "New entry created: "
                  << new_entry->get_title() 
                  << std::endl;

        selected_entry->add_entry(new_entry);
    }
}

void App::add_new_group() {
    if (selected_entry && selected_entry->can_add_entry()) {
        std::string t;

        std::cout << "Enter issue title: " << std::endl;
        t = get_string_input();

        Entry* new_entry = new Group(t, selected_entry->get_id());
        std::cout << "New gorup created: "
                  << new_entry->get_title()
                  << std::endl;

        selected_entry->add_entry(new_entry);
    }
}

// returns a list of saves in file_path as map
std::map<int, std::string> App::get_saves(std::string file_path) {
    std::map<int, std::string> res;
    struct dirent* entry;
    DIR* dp;

    dp = opendir(file_path.c_str());
    if (dp == NULL) {
        std::cerr << "Error: save does not exist or could not be read." << std::endl;
    }

    int i = -1;
    while (entry = readdir(dp)) {
        // skip . and ..
        if (i > 0) {
            res[i] = entry->d_name;
        }
        i++;
    }

    closedir(dp);
    return res;
}

void App::print_options(const std::map<int, std::string>& options) {
    for (std::pair<int, std::string> p : options) {
        std::cout << '\t' << p.second << " (" << p.first << ")" << std::endl;
    }
}

void App::print_header() {
    std::cout << "Issue Tracker\n"
              << "Anton Chen (2020)\n"
              << std::endl;
}

std::string App::get_string_input() {
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input! Please enter again: " << std::endl;
        std::getline(std::cin, input);
    }
    return input;
}

int App::get_int_input(int min, int max) {
    int input;
    std::cin >> input;
    while (std::cin.fail() || input < min || input > max) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input! Please enter again: " << std::endl;
        std::cin >> input;
    }
    return input;
}

void App::clear_terminal() {
    system("CLS");
}