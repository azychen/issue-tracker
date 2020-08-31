#include "app.h"

const std::string SAVE_PATH = "data";

void App::create_new_list() {
    std::cout << "What do you want to call your list?\n"
              << "Please enter name:" << std::endl;
    std::string name = get_string_input();
    list = new Group(name);
}

void App::load_list_from_save() {
    std::unordered_map<int, std::string> file_paths;
    int i = 1;
    for (const auto& save : std::filesystem::directory_iterator(SAVE_PATH)) {
        file_paths[i] = save.path().u8string();
        i++;
    }
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

void App::print_options(const std::unordered_map<int, std::string>& options) {
    for (auto [key, val] : options) {
        std::cout << val << " (Enter " << key << "): " << std::endl;
    }
}