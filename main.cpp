#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void generateMap(int n);
void addNoise(std::vector<std::vector<int> > &mapRep);
void digMap(std::vector<std::vector<int> > &mapRep);
void displayMap(std::vector<std::vector<int> > &mapRep);

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

    // Add noise
    addNoise(mapRep);

    // Dig through map
    // TODO

    // Display map
    displayMap(mapRep);

}

void addNoise(std::vector<std::vector<int> > &mapRep) {

    unsigned int max = 5;
    unsigned int min = 0;

    std::srand(0); // For testing only
    //std::srand(std::time(0));

    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            *it2 = (std::rand() % (abs(max + 1) + abs(min)));
        }
    }
}

void digMap(std::vector<std::vector<int> > &mapRep) {
    return;
}


void displayMap(std::vector<std::vector<int> > &mapRep) {
    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            std::cout << ' ' << *(it2);
        }
        std::cout << std::endl;
    }
}