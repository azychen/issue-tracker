/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/group.h"

// Constructors

Group::Group(int pid, string t)
    : Entry(pid, t) {}

Group::Group(int id, int pid, string cd, string t)
    : Entry(id, pid, cd, t) {}

Group::Group(int id, int pid, string cd, string t, vector<Entry*> es)
    : Entry(id, pid, cd, t),
      subentries(es) {}

Group::Group(const Group& g) : Entry(g) {
    for (Entry* e : g.subentries) {
        subentries.push_back(e->get_copy());
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

void Group::set_repository(string r) {
    for (Entry* e : subentries) {
        e->set_repository(r);
    }
}

bool Group::add_entry(Entry* e) {
    for (Entry* sub : subentries) {
        if (e->get_id() == e->get_id()) {
            return false;
        }
    }
    subentries.push_back(e);
    return true;
}

void Group::add_new_issue(string t, string d, string r) {
    Issue* i = new Issue(id, t, d, r);
    subentries.push_back(i);
}

void Group::add_new_group(string t) {
    Group* g = new Group(id, t);
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
    cout << string(level, '\t') << "GROUP: " << title << '\n'
         << string(level, '\t') << "ID: " << id << '\n'
         << string(level, '\t') << "DATE CREATED: " << creation_date << '\n';
    cout << string(level, '\t') << "SUB-ISSUES: ";
    if (subentries.empty()) {
        cout << "None" << endl;
    } else {
        cout << '\n';
        for (const Entry* const e : subentries) {
            cout << "\n";
            e->print_info(level + 1);
        }
    }
}

bool Group::save_to_file(string file_path, bool overwrite) {
    ofstream save_file;

    save_file.open(file_path, ((overwrite) ? ios_base::trunc : ios_base::app));
    if (save_file.fail()) return false;

    save_file << id << ','
              << parent_id << ','
              << creation_date << ','
              << title << ','
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

void Group::clear() {
    for (Entry* e : subentries) {
        delete e;
    }
}