#include "Processor.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    Processor proc = Processor();
    std::fstream file;
    file.open("input.txt", std::ios::in);
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            try
            {
                proc.Processor::Processing(line, proc);
            }
            catch (std::invalid_argument& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        file.close();
    }
}