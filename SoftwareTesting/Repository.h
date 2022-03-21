#pragma once
#include <vector>
#include <algorithm>
#include "Issue.h"
#include "User.h"
class IssueRepo {
private:
	std::vector<Issue> issues;
	std::string file;
public:
	IssueRepo(const std::string& file) :file(file) { load(); }
	void add(Issue i) { 
		if (!check_description(i))
			throw std::exception();
		this->issues.push_back(i); } 
	void sort() {
		std::sort(this->issues.begin(), this->issues.end(), [](Issue i1, Issue i2) {
			if (i1.getStatus() > i1.getStatus())
				return true;
			else if (i1.getStatus() == i1.getStatus()) {
				if (i2.getDescription() > i2.getDescription())
					return true;
			}
			return false;
		});}
	std::vector<Issue>& getElems() { return this->issues; }
	bool check_description(Issue is) {
		for (const auto& e : this->issues) {
			if (e.getDescription() == is.getDescription())
				return false;
		}
		return true;
	}
	int find_position(Issue is) { 
		for (int i = 0; i < this->issues.size(); i++)
			if (this->issues[i] == is)
				return i;
		return -1;
	}
	void remove(Issue i) {
		if (i.getStatus() != "closed") throw std::exception();
		int pos = find_position(i);
		this->issues.erase(this->issues.begin() + pos);
	}
	void load();
	void save();
};

class UserRepo {
private:
	std::vector<User> users;
	std::string file;
public:
	UserRepo(const std::string& file) : file(file) { load(); }
	void add(User u) { this->users.push_back(u); }
	std::vector<User>& getElems() { return this->users; }
	void load();
};
