#include "Issue.h"
#include <sstream>
#include <fstream>

std::istream& operator>>(std::istream& in, Issue& i)
{
	in.clear(); in.sync();

	std::string description, status, reporter, solver, line;

	std::getline(in, line);
	std::stringstream attrib(line);

	std::getline(attrib, description, ';');
	i.description = description;

	std::getline(attrib, status, ';');
	i.status = status;

	std::getline(attrib, reporter, ';');
	i.reporterName = reporter;

	std::getline(attrib, solver, ';');
	i.solverName = solver;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Issue& i)
{
	out << "\n" << i.getDescription() << ";" << i.getStatus() << ";" << i.getReporter() << ";" << i.getSolver();
	return out;
}

bool Issue::operator==(const Issue& i)
{
	if (this->reporterName == i.getReporter() && this->description == i.getDescription() && this->solverName == i.getSolver() && this->status == i.getStatus())
		return true;
	return false;
}
