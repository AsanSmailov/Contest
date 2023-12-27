#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    int user_id;
    std::cin >> user_id;

    std::ifstream file("data.json");
    json data;
    file >> data;

    int completed_tasks = 0;
    for (auto& project : data) {
        for (auto& task : project["tasks"]) {
            if (task["user_id"] == user_id&&task["completed"]) {
                completed_tasks++;
            }
        }
    }

    std::cout << completed_tasks << std::endl;
    return 0;
}