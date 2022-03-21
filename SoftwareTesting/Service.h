#pragma once
#include "Observer.h"
#include "Repository.h"
class ServiceI:public Observable
{
private:
	IssueRepo* repo;
public:
	ServiceI(IssueRepo* repo): repo(repo){}
	std::vector<Issue>& getElems() { return this->repo->getElems(); }
	void sort() { this->repo->sort(); }
	void add(Issue i) { this->repo->add(i); }
	void remove(Issue i) { this->repo->remove(i); }
	void notifyAll() { notify(); }
};

class ServiceU : public Observable {
private:
	UserRepo* repo;
public:
	ServiceU(UserRepo* repo) : repo(repo) {}
	std::vector<User>& getElems() { return this->repo->getElems(); }
	void add(User u) { return this->repo->add(u); }
};
