#include "app.h"

#include <filesystem>

const std::string App::SAVE_PATH = "data";

void App::create_new_list() {
    std::cout << "What do you want to call your list?\n"
              << "Please enter name:" << std::endl;
    std::string name = get_string_input();
    list = new Group(name);
}

void App::load_list_from_save() {
    std::map<int, std::string> save_paths = get_saves(SAVE_PATH);
    print_options(save_paths);
}

void App::add_new_issue() {
}

std::string App::get_string_input() {
    std::string input;
    std::cin >> input;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cout << "Invalid input! Please enter again: " << std::endl;
        std::cin >> input;
    }
    return input;
}

int get_int_input() {
    int input;
    std::cin >> input;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin >> input;
        std::cout << "Invalid input! Please enter again: " << std::endl;
    }
    return input;
}

void App::print_options(const std::map<int, std::string>& options) {
    for (std::pair<int, std::string> p : options) {
        std::cout << p.second << " (Enter " << p.first << "): " << std::endl;
    }
}

std::map<int, std::string> App::get_saves(std::string file_path) {
    std::map<int, std::string> res;
    struct dirent* entry;
    DIR* dp;

    dp = opendir(file_path.c_str());
    if (dp == NULL) {
        std::cerr << "opendir: Path does not exist or could not be read." << std::endl;
    }

    int i = 1;
    while (entry = readdir(dp)) {
        res[i] = entry->d_name;
        i++;
    }

    closedir(dp);
    return res;
}