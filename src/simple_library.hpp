#include <nlohmann/json.hpp>

void create_file(const nlohmann::json& j, const std::string& path);
nlohmann::json read_file(const std::string& path);

