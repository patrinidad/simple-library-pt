#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "../src/simple_library.hpp" 

using json = nlohmann::json;

TEST(CreateFileTest, test_json_if_valid) 
{
    json valid = {
        {"students", {
            {{"id", 1}, {"name", "Alice"}},
            {{"id", 2}, {"name", "Bob"}}
        }}
    };
    EXPECT_NO_THROW(create_file(valid, "/tmp/test.json"));
}

TEST(CreateFileTest, throw_json_if_invalid) 
{
    json invalid = {
        {"invalid_key", {
            {{"id", 1}, {"name", "Alice"}}
        }}
    };
    EXPECT_THROW(create_file(invalid, "/tmp/test.json"), std::runtime_error);
}

TEST(ReadFileTest, return_valid_json) 
{
    std::string path = "/tmp/test.json";
    json valid = {
        {"students", {
            {{"id", 3}, {"name", "Carol"}}
        }}
    };
    create_file(valid, path);
    json result = read_file(path);
    EXPECT_EQ(result["students"].size(), 1);
    EXPECT_EQ(result["students"][0]["name"], "Carol");
}

