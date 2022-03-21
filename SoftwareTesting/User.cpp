#include "User.h"
#include <sstream>
#include <fstream>

std::istream& operator>>(std::istream& in, User& u)
{
	in.clear(); in.sync();

	std::string name, type, line;

	std::getline(in, line);
	std::stringstream attrib(line);

	std::getline(attrib, name, ';');
	u.name = name;

	std::getline(attrib, type, ';');
	u.type = type;
	
	return in;
}
