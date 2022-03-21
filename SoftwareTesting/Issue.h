#pragma once
#include <string>
class Issue {
private:
	std::string description;
	std::string status; //open, closed
	std::string reporterName;
	std::string solverName;
public:
	Issue(const std::string& d, const std::string& s, const std::string& rep, const std::string& sol): solverName(sol), description(d), reporterName(rep), status(s){}
	Issue() { this->description = ""; this->status = ""; this->reporterName = ""; this->solverName = ""; }
	const std::string& getDescription() const { return this->description; }
	const std::string& getStatus() const { return this->status; }
	const std::string& getReporter() const { return this->reporterName; }
	const std::string& getSolver() const { return this->solverName; }
	friend std::istream& operator>>(std::istream& in, Issue& i);
	friend std::ostream& operator<<(std::ostream& out, const Issue& i);
	bool operator==(const Issue& i);

	void setSolver(const std::string& name) { this->solverName = name; }
	void setStatus(const std::string& status) { this->status = status; }
};