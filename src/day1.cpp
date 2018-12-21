#include "day1.h"

void solveDay1()
{
    std::cout << "Day1 has started!" << '\n';

    std::array<int, GL_SIZE> numbers = readFile<int, GL_SIZE>("numbers.txt");

    //printArray<int, GL_SIZE>(numbers);

    std::cout << '\n';
    std::cout << "RESULTING FREQUENCY: " << sumUp<int, GL_SIZE>(numbers) << std::endl;

    std::cout << '\n';
    std::cout << "FIRST DUPLICATED FREQUENCY: " << getFirstDuplFreq<int, GL_SIZE>(numbers) << std::endl;
}

