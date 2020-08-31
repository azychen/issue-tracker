#include "app.h"

App::App()
    : list(new Group("New Issue List")), selected_entry(list) {}

App::App(const std::string& t)
    : list(new Group(t)), selected_entry(list) {}

App::App(Group* g)
    : list(g), selected_entry(list) {}

App::~App() {
    delete list;
    // selected_entry is always in list, so it doesn't need to be deleted
}

bool App::load_list_from_save(const std::string& file_path) {
    if (std::filesystem::exists(file_path)) {
        list = new Group();
        list->load_from_file(file_path);
        return true;
    } else {
        return false;
    }
}