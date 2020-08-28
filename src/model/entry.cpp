/*
    Anton Chen 2020
    github.com/azychen/issue-tracker
*/

#include "../headers/entry.h"

// Fields
int Entry::prev_id = 0;

// Constructors

Entry::Entry(std::string t, int pid)
    : id(++prev_id),
      parent_id(pid),
      title(t),
      is_active(true) {
    char* curr_time = new char[creation_date_length];
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    strftime(curr_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    creation_date = std::string(curr_time);
    delete curr_time;
}

Entry::Entry(int pid, std::string cd, std::string t)
    : id(++prev_id),
      parent_id(pid),
      creation_date(cd),
      title(t),
      is_active(true) {}

Entry::Entry(int id, int pid, std::string cd, std::string t)
    : id(id),
      parent_id(pid),
      title(t),
      creation_date(cd),
      is_active(true) {
    prev_id = (id > prev_id) ? id : prev_id;
}

bool Entry::delete_entry(int id) {
	if (this->id == id) {
		clear();
		return true;
	}
	return false;
}