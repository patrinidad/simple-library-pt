#include "file_creator.hpp"


namespace seneca::example
{

FileCreator::FileCreator(std::string& file_path)
:m_file_path(file_path)
{
    std::cout << "Files will be created in " << m_file_path << std::endl;
}

FileCreator::~FileCreator()
{
    std::cout << "Destructor" << std::endl;
}

void FileCreator::create_file(std::string& file_content)
{
    std::cout << "Create File " << m_file_path << "With Content" << file_content <<std::endl;
}

std::string FileCreator::read_file(std::string& file_name)
{
    std::cout << "Print File Content of " << file_name << std::endl;
    return "File Content";
}

}
