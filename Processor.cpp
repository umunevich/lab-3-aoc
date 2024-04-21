#include "Processor.h"
#include "Line.h"
#include <iostream>
#include <string>
bool to_binary(int num, bool(&R)[N]);
bool complement(bool(&R)[N]);

Processor::Processor() {}

bool Processor::Processing(std::string line, Processor& proc)
{
	PC++;
	IR = line;
	Line l = Line(line);
	Tact(proc);
	if (l.Command == "MOV")
	{
		if (l.Register1 == "R1")
		{
			MOV(R1, stoi(l.Register2));
			Tact(proc);
		}
		else if (l.Register1 == "R2")
		{
			MOV(R2, stoi(l.Register2));
			Tact(proc);
		}
		else if (l.Register1 == "R3")
		{
			MOV(R3, stoi(l.Register2));
			Tact(proc);
		}
		else if (l.Register1 == "R4")
		{
			MOV(R4, stoi(l.Register2));
			Tact(proc);
		}
		else
		{
			throw std::invalid_argument("Register hasn't founded.");      /////////
		}
	}
	else if (l.Command == "AND")
	{
		if (l.Register1 == l.Register2 || l.Register1 == l.Register3 || ((l.Register2 == l.Register3) && (l.Register2 == "R1" || l.Register2 == "R2" || l.Register2 == "R3" || l.Register2 == "R4")))
		{
			throw std::invalid_argument("Wrong input.");
		}
		bool (*Reg1_ptr)[N];
		if (l.Register1 == "R1")
		{
			Reg1_ptr = &R1;
		}
		else if (l.Register1 == "R2")
		{
			Reg1_ptr = &R2;
		}
		else if (l.Register1 == "R3")
		{
			Reg1_ptr = &R3;
		}
		else if (l.Register1 == "R4")
		{
			Reg1_ptr = &R4;
		}
		else
		{
			throw std::invalid_argument("Register hasn't founded.");
		}

		bool(*Reg2_ptr)[N];
		if (l.Register2 == "R1")
		{
			Reg2_ptr = &R1;
		}
		else if (l.Register2 == "R2")
		{
			Reg2_ptr = &R2;
		}
		else if (l.Register2 == "R3")
		{
			Reg2_ptr = &R3;
		}
		else if (l.Register2 == "R4")
		{
			Reg2_ptr = &R4;
		}
		else
		{
			if (l.Register1 == "R1" && l.Register3 == "R2" || l.Register1 == "R2" && l.Register3 == "R1")
			{
				Reg2_ptr = &R3;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R2" && l.Register3 == "R3" || l.Register1 == "R3" && l.Register3 == "R2")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R3" && l.Register3 == "R4" || l.Register1 == "R4" && l.Register3 == "R3")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R4" && l.Register3 == "R1" || l.Register1 == "R1" && l.Register3 == "R4")
			{
				Reg2_ptr = &R2;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R2" && l.Register3 == "R4" || l.Register1 == "R4" && l.Register3 == "R2")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R1" && l.Register3 == "R3" || l.Register1 == "R3" && l.Register3 == "R1")
			{
				Reg2_ptr = &R2;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R1")
			{
				Reg2_ptr = &R2;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R2")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R3")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else if (l.Register1 == "R4")
			{
				Reg2_ptr = &R1;
				MOV(*Reg2_ptr, stoi(l.Register2));
				Tact(proc);
			}
			else
			{
				throw std::invalid_argument("Wrong input");
			}
		}

		bool(*Reg3_ptr)[N];
		if (l.Register3 == "R1")
		{
			Reg3_ptr = &R1;
		}
		else if (l.Register3 == "R2")
		{
			Reg3_ptr = &R2;
		}
		else if (l.Register3 == "R3")
		{
			Reg3_ptr = &R3;
		}
		else if (l.Register3 == "R4")
		{
			Reg3_ptr = &R4;
		}
		else
		{
			if (l.Register1 == "R1" && l.Register2 == "R2" || l.Register1 == "R2" && l.Register2 == "R1")
			{
				Reg3_ptr = &R3;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R2" && l.Register2 == "R3" || l.Register1 == "R3" && l.Register2 == "R2")
			{
				Reg3_ptr = &R1;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R3" && l.Register2 == "R4" || l.Register1 == "R4" && l.Register2 == "R3")
			{
				Reg3_ptr = &R1;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R4" && l.Register2 == "R1" || l.Register1 == "R1" && l.Register2 == "R4")
			{
				Reg3_ptr = &R2;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R2" && l.Register2 == "R4" || l.Register1 == "R4" && l.Register2 == "R2")
			{
				Reg3_ptr = &R1;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R1" && l.Register2 == "R3" || l.Register1 == "R3" && l.Register2 == "R1")
			{
				Reg3_ptr = &R2;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R1")
			{
				Reg3_ptr = &R3;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R2")
			{
				Reg3_ptr = &R3;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R3")
			{
				Reg3_ptr = &R4;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else if (l.Register1 == "R4")
			{
				Reg3_ptr = &R3;
				MOV(*Reg3_ptr, stoi(l.Register3));
				Tact(proc);
			}
			else
			{
				throw std::invalid_argument("Wrong input");
			}
		}

		AND(*Reg1_ptr, *Reg2_ptr, *Reg3_ptr);
		Tact(proc);
	}

	std::cout << "======================================================" << std::endl;

	TC = 1;
	return true;
}

// Output tact.
void Processor::Tact(Processor)
{
	std::cout << IR << std::endl;

	std::cout << "R1:   ";
	for (int i = 0; i < N; i++)
	{
		std::cout << R1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "R2:   ";
	for (int i = 0; i < N; i++)
	{
		std::cout << R2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "R3:   ";
	for (int i = 0; i < N; i++)
	{
		std::cout << R3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "R4:   ";
	for (int i = 0; i < N; i++)
	{
		std::cout << R4[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "PS:   " << PS << std::endl;
	std::cout << "PC:   " << PC << std::endl;
	std::cout << "TC:   " << TC << std::endl;

	TC++;
	std::cin.get();
}

bool Processor::MOV(bool(&R)[N], int num)
{
	to_binary(num, R);
	if (num < 0)
	{
		complement(R);
	}
	PS = R[0];
	return true;
}
bool Processor::AND(bool(&Register1)[N], bool(&Register2)[N], bool(&Register3)[N])
{
	for (int i = 0; i < N; i++)
	{
		Register1[i] = Register2[i] && Register3[i];
	}
	PS = Register1[0];
	return true;
}

// Convert number to binary.
bool to_binary(int num, bool(&R)[N])
{
	if (num > 8388608 or num < -8388608)
	{
		std::cout << "Number is too big. Possible loss of data" << std::endl;
	}
	bool arr[N]{};
	for (int i = 0; i < N && num != 0; i++)
	{
		arr[i] = bool(num % 2);
		num /= 2;
	}
	for (int i = 0; i < N; i++)
	{
		R[i] = arr[N - 1 - i];
	}
	return true;
}

// Complement code for binary number.
bool complement(bool(&R)[N])
{
	// Inverse.
	int i = 0;
	for (i; i < N; i++)
	{
		if (R[i] == 1)
			R[i] = 0;
		else
			R[i] = 1;
	}
	// Add 1.
	bool RF = 1;
	for (i; i > 0; i--)
	{
		if (R[i] && RF)
		{
			R[i] = (R[i] + RF) % 2;
			RF = 1;

		}
		else
		{
			R[i] = (R[i] + RF) % 2;
			RF = 0;
		}
	}
	return true;
}