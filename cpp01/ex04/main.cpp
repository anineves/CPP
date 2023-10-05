#include <iostream>
#include <fstream>
#include <string>

std::string replaceOccurrences(std::string content, const std::string s1, const std::string s2) 
{
    if (s1.empty())
        return (content);
    size_t  index = content.find(s1);
  
    while(index != std::string::npos)
    {
        content.erase(index, s1.size());
        content.insert(index, s2);
        index = content.find(s1);
    }
    return (content);
}

int main(int argc, char* argv[]) 
{
    if (argc != 4) {
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

    result = replaceOccurrences(result, s1, s2);

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
