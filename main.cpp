#include <iostream>
#include <vector>

void generateMap(int n);

int main(int argc, char **argv) {

    // argv[1] = n for an n x n map

    generateMap(std::stoi(argv[1]));

    return 0;
}

void generateMap(int n) {

    std::cout << n << std::endl;

    // Create empty map
    std::vector<std::vector<int> > mapRep = std::vector<std::vector<int> >(n);
    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        *(it) = std::vector<int>(n);
    }

    // Display map
    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            std::cout << *(it2);
        }
        std::cout << std::endl;
    }

}