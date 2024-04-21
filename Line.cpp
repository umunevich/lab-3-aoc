#include "Line.h"
#include <iostream>

Line::Line(std::string line)
{
	int i = 0;
	Command = Line::word(line, i);
	if (Command == "MOV")
	{
		Register1 = Line::word(line, i);
		Register2 = Line::word(line, i);
	}
	else if (Command == "AND")
	{
		Register1 = Line::word(line, i);
		Register2 = Line::word(line, i);
		Register3 = Line::word(line, i);
	}
	else
	{
		throw std::invalid_argument("Command hasn't founded.");            ///////
	}
}

std::string Line::word(std::string line, int& i)
{
	std::string word = "";
	for (i; line[i] == ' '; i++) {}
	for (i; line[i] != ' ' && i < size(line); i++)
	{
		word += line[i];
	}
	i++;
	return word;
}
