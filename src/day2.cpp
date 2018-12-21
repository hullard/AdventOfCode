#include "day2.h"
#include "_common.h"

void solveDay2()
{
    std::cout << "Day2 has started!" << '\n';

    std::array<std::string, GL_SIZE> strings = readFile<std::string, GL_SIZE>("box_ids.txt");

    std::cout << '\n';
    printArray<std::string, GL_SIZE>(strings);

    std::cout << "CHECKSUM IS: " << makeCheckSum(strings) << std::endl;

}

int makeCheckSum(std::array<std::string, GL_SIZE> &strings)
{

    return 0;
}
