#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(std::string content, const std::string s1, const std::string s2) 
{

    size_t index = 0;
    std::string result;

    while (index < content.length()) 
    {
        size_t foundPos = content.find(s1, index);

        if (foundPos == std::string::npos) {
            result += content.substr(index);
            break;
        }
        result += content.substr(index, foundPos - index);
        result += s2;
        index = foundPos + s1.length();
    }

    return result;
}

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        std::cerr << "Wrong Input, \n Please try again, with ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream ifs(filename);

    if (!ifs.is_open()) 
    {
        std::cerr << "Error when trying to open file" << std::endl ;
        return (1);
    }

    std::string result;

    std::getline(ifs, result, '\0');
    ifs.close();

    result = ft_replace(result, s1, s2);

    std::ofstream ofs(filename + ".replace");

    if (!ofs.is_open()) 
    {
        std::cerr << "Error when trying to open file" << std::endl ;
        return (1);
    }

    ofs << result;
    ofs.close();

    return 0;
}
