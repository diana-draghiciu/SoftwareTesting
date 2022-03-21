#include "Repository.h"
#include <sstream>
#include <fstream>

void IssueRepo::load()
{
	std::ifstream fin;
	fin.open(this->file);
	if (!fin.is_open())
		return;
	fin.get();
	Issue el;
	while (!fin.eof()) {
		fin >> el;
		this->issues.push_back(el);
	}
	fin.close();
}

void IssueRepo::save()
{
	std::ofstream fout;
	fout.open(this->file);
	if (!fout.is_open())
		return;
	for (const auto& e : this->issues)
		fout << e;
	fout.close();
}

void UserRepo::load()
{
	std::ifstream fin;
	fin.open(this->file);
	if (!fin.is_open())
		return;
	User el;
	fin.get();
	while (!fin.eof()) {
		fin >> el;
		this->users.push_back(el);
	}
	fin.close();
}
