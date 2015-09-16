#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void generateMap(int n);
void addNoise(std::vector<std::vector<int> > &mapRep);
void digMap(std::vector<std::vector<int> > &mapRep);
void dig(std::vector<std::vector<char> > &dugMap, std::vector<std::vector<int> > &mapRep, unsigned int level, unsigned int digPoint);
void displayDugMap(std::vector<std::vector<char> > &mapRep);
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
    digMap(mapRep);

    // Display map
    //std::cout << std::endl;
    //displayMap(mapRep);

}

void addNoise(std::vector<std::vector<int> > &mapRep) {

    unsigned int max = 9;
    unsigned int min = 0;

    //std::srand(0); // For testing only
    std::srand(std::time(0));

    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            *it2 = (std::rand() % (abs(max + 1) + abs(min)));
        }
    }
}

void digMap(std::vector<std::vector<int> > &mapRep) {

    unsigned int digPoint = std::rand() % mapRep.size();
    unsigned int level = 0;


    // Fill dug map with "soil" -> 0
    std::vector<std::vector<char> > dugMap = std::vector<std::vector<char> >(mapRep.size());
    for (auto it = dugMap.begin(); it < dugMap.end(); ++it) {
        *(it) = std::vector<char>(mapRep.size());
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            *it2 = '0';
        }
    }

    // Dig through the map
    /*// Brute force

    while (level != mapRep.size()) {
        int curr = mapRep[level][digPoint];
        dugMap[level][digPoint] = ' ';

        if (mapRep[level + 1][digPoint] < curr) {
            level = level + 1;
            continue;
        } else if (digPoint - 1 >= 0) {
            if ( mapRep[level][digPoint - 1] < curr) {
                digPoint = digPoint - 1;
                continue;
            }
        }
            
        if (mapRep[level][digPoint + 1] < curr) {
            digPoint = digPoint + 1;
            continue;
        } else {
            level = mapRep.size();
        } 
    }
    */

    // Recursive

    dig(dugMap, mapRep, level, digPoint);

    displayDugMap(dugMap);

}

void dig(std::vector<std::vector<char> > &dugMap, std::vector<std::vector<int> > &mapRep, unsigned int level, unsigned int digPoint) {

    // Exit case
    if (level >= mapRep.size()) return;
    //std::cout << level << std::endl;
    // Recursion
    dugMap[level][digPoint] = ' '; 
    int curr = mapRep[level][digPoint];

    if (level + 1 <= mapRep.size()) {
        if (mapRep[level + 1][digPoint] < curr) {
            dig(dugMap, mapRep, level + 1, digPoint);
        } 
    }
    if (digPoint + 1 <= mapRep.size()) {
        if (mapRep[level][digPoint + 1] < curr) {
            dig(dugMap, mapRep, level, digPoint + 1);
        }
    }
    if (digPoint - 1 >= 0) {
        if (mapRep[level][digPoint - 1] < curr) {
            dig(dugMap, mapRep, level, digPoint - 1);
        }
    }

    return;

}

void displayDugMap(std::vector<std::vector<char> > &mapRep) {
    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            std::cout << ' ' << *(it2);
        }
        std::cout << std::endl;
    }
}

void displayMap(std::vector<std::vector<int> > &mapRep) {
    for (auto it = mapRep.begin(); it < mapRep.end(); ++it) {
        for (auto it2 = (*it).begin(); it2 < (*it).end(); ++it2) {
            std::cout << ' ' << *(it2);
        }
        std::cout << std::endl;
    }
}