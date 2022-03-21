#pragma once
#include <string>

class User {
private:
	std::string name;
	std::string type; //tester/programmer
public:
	User() { this->name = ""; this->type = ""; }
	const std::string& getName() const { return this->name; }
	const std::string& getType() const { return this->type; }
	friend std::istream& operator>>(std::istream& in, User& u);
};