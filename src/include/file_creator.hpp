#include <iostream>

namespace seneca::example
{

class FileCreator{
public:
    FileCreator(std::string& file_path);
    FileCreator() = delete;
    //Rule of 5
    ~FileCreator();

    FileCreator(const FileCreator&) = delete;
    FileCreator(FileCreator&&) = delete;

    FileCreator& operator=(const FileCreator&) = delete;
    FileCreator& operator=(FileCreator&&) = delete;

    void create_file(std::string& file_content);
    std::string read_file(std::string& file_name);

private:
    std::string m_file_path;
    int m_fd;
};

} //namepace seneca::example
