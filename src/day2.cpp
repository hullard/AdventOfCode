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
    int num_2Letter {0}, num_3Letter {0};

    for (const auto &str : strings)
    {
        std::array<unsigned, 256> num_chars;
        num_chars.fill(0);

        // count the letters in an array indexed by ASCI codes
        for (std::string::const_iterator itr = str.begin(); itr != str.end(); ++itr)
        {
            uint8_t asci_code = static_cast<uint8_t>(*itr);
            num_chars[asci_code] += 1;
        }

        // detect double and triple letter occurances (each counts only once!)
        bool count_2Letter {false}, count_3Letter {false};
        for (unsigned idx {0}; idx < 256; ++idx)
        {
            if (num_chars[idx] == 2) { count_2Letter = true; }
            if (num_chars[idx] == 3) { count_3Letter = true; }
        }

        if (count_2Letter) { num_2Letter += 1; }
        if (count_3Letter) { num_3Letter += 1; }
    }

    return num_2Letter * num_3Letter;
}
