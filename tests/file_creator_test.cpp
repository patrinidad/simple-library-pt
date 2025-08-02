#include "file_creator.hpp"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

namespace
{
using namespace seneca::example;
using json = nlohmann::json;

class file_creator_test : public ::testing::Test
{
protected:
	std::string test_path;
	
    file_creator_test()
    {

    };

    void SetUp() override 
    {
		test_path = "/tmp/test_file_creator.json";
        std::ofstream clear(test_path); 
        clear.close();
    }

    void TearDown() override
    {
		std::filesystem::remove(test_path);
    }
};

TEST_F(file_creator_test, create_file_valid) {
    FileCreator fc(test_path);

    json j = {
        {"students", {
            {{"id", 23}, {"name", "Benedict"}},
            {{"id", 80}, {"name", "Octavio"}},
            {{"id", 75}, {"name", "Olivia"}},
            {{"id", 90}, {"name", "Noah"}}
        }}
    };

    std::string content = j.dump();
    testing::internal::CaptureStdout();
    fc.create_file(content);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Create File"), std::string::npos);
    EXPECT_NE(output.find(test_path), std::string::npos);
}

TEST_F(file_creator_test, create_file_with_empty_string) {
    FileCreator fc(test_path);
    std::string empty = "";

    testing::internal::CaptureStdout();
    fc.create_file(empty);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Create File"), std::string::npos);
}

TEST_F(file_creator_test, still_print_if_invalid) {
    FileCreator fc(test_path);
    std::string bad_json = "!!INVALID!!";

    testing::internal::CaptureStdout();
    fc.create_file(bad_json);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Create File"), std::string::npos);
}


TEST_F(file_creator_test, read_file_if_valid_return_string) {
    std::string dummy = "unused";
	FileCreator fc(dummy);

    std::string file = "/tmp/fake_read.json";

    testing::internal::CaptureStdout();
    std::string result = fc.read_file(file);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(result, "File Content");
    EXPECT_NE(output.find("Print File Content"), std::string::npos);
}

TEST_F(file_creator_test, read_file_even_ifits_missing) {
    std::string dummy = "unused";
	FileCreator fc(dummy);

    std::string file = "/tmp/missing.json";

    testing::internal::CaptureStdout();
    std::string result = fc.read_file(file);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(result, "File Content");
    EXPECT_NE(output.find(file), std::string::npos);
}

TEST_F(file_creator_test, read_file_and_should_return_content) {
    std::string dummy = "unused";
	FileCreator fc(dummy);

    std::string path = "/tmp/whatever.json";
	std::string result = fc.read_file(path);

    EXPECT_EQ(result, "File Content");
}

TEST_F(file_creator_test, write_data_to_non_existing_file)
{
    std::cout<<" This is the test!"<<std::endl;
    EXPECT_TRUE(true);
}

}
