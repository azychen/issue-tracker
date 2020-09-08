/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "group.h"

// Constructors

Group::Group(std::string t, int pid)
    : Entry(t, pid) {}

Group::Group(int id, int pid, std::string cd, std::string t, bool active)
    : Entry(id, pid, cd, t, active) {}

Group::Group(const Group& g) : Entry(g) {
    for (Entry* e : g.subentries) {
        subentries.push_back(e->get_copy());
    }
}

Group::Group(const Entry& e) 
    : Entry(e) {}

Group::Group(const char* file_path) {
    std::vector<Entry*> entries = get_entries_from_file(file_path);

    std::unordered_map<int, int> id_to_index;  // <id, index>
    Group(*entries[0]);

    for (int i = 0; i < entries.size(); i++) {
        id_to_index[entries[i]->get_id()] = i;
    }

    // all entries[1:] must have parent entry
    for (int i = 1; i < entries.size(); i++) {
        entries[id_to_index[entries[i]->get_parent_id()]]->add_entry(entries[i]);
    }


}


// Destructor
Group::~Group() {
    for (Entry* e : subentries) {
        delete e;
    }
}

// Copy assignment
Group& Group::operator=(const Group& g) {
    if (this != &g) {
        clear();
        parent_id = g.parent_id;
        id = g.id;
        creation_date = g.creation_date;
        title = g.title;
        for (Entry* e : g.subentries) {
            subentries.push_back(e->get_copy());
        }
    }
    return *this;
}

// Edit fields

void Group::set_repository(std::string r) {
    for (Entry* e : subentries) {
        e->set_repository(r);
    }
}

// Adds existing entry, sets its parent id to this' id
bool Group::add_entry(Entry* e) {
    for (Entry* sub : subentries) {
        if (e->get_id() == sub->get_id()) {
            return false;
        }
    }
    subentries.push_back(e);
    e->set_parent_id(id);
    return true;
}

void Group::add_new_issue(std::string t, std::string d, std::string r) {
    Issue* i = new Issue(t, d, r, id);
    subentries.push_back(i);
}

void Group::add_new_group(std::string t) {
    Group* g = new Group(t, id);
    subentries.push_back(g);
}

bool Group::delete_entry(int id) {
    if (this->id == id) {
        clear();
        return true;
    }

    // check subentries
    bool deleted = false;
    for (auto it = subentries.begin(); it != subentries.end(); it++) {
        deleted = (*it)->delete_entry(id);
        if (deleted) {
            subentries.erase(it);
            return true;
        }
    }
    return false;
}

void Group::activate() {
    for (Entry* e : subentries) {
        e->activate();
    }
    is_active = true;
}

void Group::deactivate() {
    for (Entry* e : subentries) {
        e->deactivate();
    }
    is_active = false;
}

// Auxiliary methods

void Group::print_info(const int level) const {
    std::cout << std::string(level, '\t') << "GROUP: " << title << '\n'
              << std::string(level, '\t') << "ID: " << id << '\n'
              << std::string(level, '\t') << "DATE CREATED: " << creation_date << '\n';
    std::cout << std::string(level, '\t') << "SUB-ISSUES: ";
    if (subentries.empty()) {
        std::cout << "None" << std::endl;
    } else {
        std::cout << '\n';
        for (const Entry* const e : subentries) {
            std::cout << "\n";
            e->print_info(level + 1);
        }
    }
}

bool Group::save_to_file(std::string file_path, bool overwrite) {
    std::ofstream save_file;

    if (overwrite) {
        save_file.open(file_path, std::ios_base::trunc);
    } else {
        save_file.open(file_path, std::ios_base::app);
    }

    if (save_file.fail()) return false;

    save_file << id << ','
              << parent_id << ','
              << creation_date << ','
              << sanitize(title) << ','
              << is_active << '\n';

    save_file.close();

    for (Entry* e : subentries) e->save_to_file(file_path, false);

    return true;
}

Entry* Group::get_copy() const {
    Group* res = new Group(id, parent_id, creation_date, title);
    for (Entry* e : subentries) {
        res->subentries.push_back(e->get_copy());
    }
    return res;
}

// deletes all fields
void Group::clear() {
    for (Entry* e : subentries) {
        delete e;
    }
}

// loads savefile as group
void Group::load_from_file(std::string file_path) {
    std::vector<Entry*> entries = get_entries_from_file(file_path);

    std::unordered_map<int, int> id_to_index;  // <id, index>
    int root_id = entries[0]->get_id();

    for (int i = 0; i < entries.size(); i++) {
        id_to_index[entries[i]->get_id()] = i;
    }

    // all entries[1:] must have parent entry
    for (int i = 1; i < entries.size(); i++) {
        entries[id_to_index[entries[i]->get_parent_id()]]->add_entry(entries[i]);
        if (entries[i]->get_parent_id() == root_id) {
            // segmentation fault ?????
            add_entry(entries[i]);
        }
    }

    assign_fields(entries[0]);
}

// reconstructs and returns all Entries found in savefile
std::vector<Entry*> Group::get_entries_from_file(const std::string& file_path) {
    std::vector<Entry*> res;
    std::ifstream save_file;
    save_file.open(file_path);

    if (!save_file.fail()) {
        std::string line;
        while (std::getline(save_file, line)) {
            res.push_back(parse_line(line));
        }
    }
    return res;
}

// reconstructs Entry from a single line of savefile
Entry* Group::parse_line(const std::string& line) {
    Entry* res;
    std::vector<std::string> fields = get_fields_from_line(line);

    int id = std::stoi(fields[0]);
    int pid = std::stoi(fields[1]);
    std::string cd = fields[2];
    std::string t = fields[3];
    bool active = (fields[4] == "1");

    if (fields.size() == 7) {  // if number of fields indicates an Issue
        std::string d = fields[5];
        std::string r = fields[6];

        res = new Issue(id, pid, cd, t, d, r, active);
    } else {  // then number of fields indicates a Group
        res = new Group(id, pid, cd, t, active);
    }

    return res;
}

// returns list of fields from line as strings
std::vector<std::string> Group::get_fields_from_line(const std::string& line) {
    std::stringstream ss(line);
    std::vector<std::string> res;
    std::string cell;

    while (std::getline(ss, cell, ',')) {
        res.push_back(cell);
    }
    if (!ss && cell.empty()) {
        res.push_back("");
    }
    return res;
}

void Group::assign_fields(Entry* e) {
    id = e->get_id();
    parent_id = e->get_parent_id();
    creation_date = e->get_creation_date();
    title = e->get_title();
    is_active = e->get_active();
}