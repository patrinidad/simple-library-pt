#include <iostream>

#include "include/file_creator.hpp"

int main()
{
    std::cout << "Hello world" << std::endl;
    std::string file_path = "test_file.txt";
    std::string file_content = "This is a test file content.";
    seneca::example::FileCreator file_creator(file_path);
    file_creator.create_file(file_content);
}
