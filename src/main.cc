#include <iostream>
#include <cmath>
#include "nlohmann/json.hpp"
using namespace std;
using namespace nlohmann;

// For testing purpose
// Due to we are students
int main() {
    json j;
    j["pi"] = M_PI;
    cout << j["pi"] << endl;
    return 0;
}