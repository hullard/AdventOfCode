#include "day2.h"
#include "_common.h"

void solveDay2()
{
    std::cout << "Day2 has started!" << '\n';

    std::array<std::string, GL_SIZE> strings = readFile<std::string, GL_SIZE>("box_ids.txt");

    std::cout << '\n';
    printArray<std::string, GL_SIZE>(strings);

    std::cout << "CHECKSUM IS: " << makeCheckSum(strings) << '\n';

    try
    {
        std::cout << '\n';
        std::cout << "COMMON LETTERS ARE: " << getCommonLetters(strings) << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int makeCheckSum(const std::array<std::string, GL_SIZE> &strings)
{
    int num_2Letter {0}, num_3Letter {0};

    for (const auto &str : strings)
    {
        std::array<unsigned, 256> num_chars = getSpectrumASCII(str);

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

std::array<unsigned, 256> getSpectrumASCII(const std::string &str)
{
    std::array<unsigned, 256> num_chars;
    num_chars.fill(0);

    // count the letters in an array indexed by ASCII codes
    for (std::string::const_iterator itr = str.begin(); itr != str.end(); ++itr)
    {
        uint8_t ascii_code = static_cast<uint8_t>(*itr);
        num_chars[ascii_code] += 1;
    }
    return num_chars;
}

std::string getCommonLetters(const std::array<std::string, GL_SIZE> &strings)
{
    for (unsigned i {0}; i < strings.size(); ++i)
    {
        for (unsigned j {0}; j < strings.size(); ++j)
        {
            // no comparison with itself
            if (i == j) continue;

            if (countDifferentLetters(strings[i], strings[j]) == 1)
                return getCommonString(strings[i], strings[j]);
        }
    }
    return std::string("");
}

int countDifferentLetters(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
        throw std::length_error("The two strings are not of equal length!");

    int count {0};
    for (unsigned idx {0}; idx < str1.length(); ++idx)
        if (str1[idx] != str2[idx])
            ++count;

    return count;
}

std::string getCommonString(const std::string &str1, const std::string &str2)
{
    std::string commonString;
    for (unsigned idx {0}; idx < str1.length(); ++idx)
        if (str1[idx] == str2[idx])
            commonString += str1[idx];

    return commonString;
}
