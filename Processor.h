#pragma once
#include <string>
const int N = 24;
struct Processor
{
	bool R1[N] = {};
	bool R2[N] = {};
	bool R3[N] = {};
	bool R4[N] = {};
	bool PS = 0;
	int PC = 0;
	int TC = 1;
	std::string IR = "";

	Processor();
	bool Processing(std::string line, Processor& proc);
	void Tact(Processor);
	bool MOV(bool(&R)[N], int num);
	bool AND(bool(&Register1)[N], bool(&Register2)[N], bool(&Register3)[N]);
};

