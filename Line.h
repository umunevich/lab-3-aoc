#pragma once
#include <string>

struct Line
{
	std::string Command = "";
	std::string Register1 = "";
	std::string Register2 = "";
	std::string Register3 = "";

	Line(std::string line);
	std::string word(std::string line, int& i);
};

