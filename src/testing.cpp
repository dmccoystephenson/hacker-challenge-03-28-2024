#include <string>
#include <iostream>
#include <list>
#include <cstdlib>

bool debugFlag = true;
std::string indent = "";

/**
 * Log a message to the console.
 */
void log(std::string message) {
    std::cout << "[LOG] " << message << std::endl;
}

/**
 * Log a debug message to the console.
 */
void debug(std::string message) {
    if (debugFlag) {
        std::cout << "[DEBUG] " << message << std::endl;
    }
}

int getRecommendedBroadcastRange(std::list<int> listenerPositions, std::list<int> towerPositions) {
    int recommendedBroadcastRange = -1;
    for (int listenerPosition : listenerPositions) {
        // std::cout << "Listener position: " << listenerPosition << std::endl;
        int distanceToTower = 999999;
        for (int towerPosition : towerPositions) {
            // std::cout << "Tower position: " << towerPosition << std::endl;
            int tempDistance = abs(listenerPosition - towerPosition);
            // std::cout << "Distance: " << tempDistance << std::endl;
            if (tempDistance < distanceToTower) {
                distanceToTower = tempDistance;
            }
        }
        std::cout << "Listener at position " << listenerPosition << " is " << distanceToTower << " units away from the nearest tower." << std::endl;
        if (distanceToTower > recommendedBroadcastRange) {
            recommendedBroadcastRange = distanceToTower;
        }
    }
    return recommendedBroadcastRange;
}

int test1() {
    std::cout << "=== Test 1 ===" << std::endl;
    std::list<int> listenerPositions = {1, 5, 11, 20};
    std::list<int> towerPositions = {4, 8, 15};
    
    int expected = 5;

    int result = getRecommendedBroadcastRange(listenerPositions, towerPositions);
    
    if (expected == result) {
        std::cout << "Success" << std::endl;
        return 0;
    }
    else {
        std::cout << "Failure" << std::endl;
        return 1;
    }
}

int runTests() {
    int result = 0;
    result &= test1();

    if (result == 0) {
        std::cout << "Tests Succeeded!" << std::endl;
        return 0;
    }
    else {
        std::cout << "One or more tests failed." << std::endl;
        return 1;
    }
}

int main() {
    bool shouldRunTests = false;

    if (shouldRunTests) {
        runTests();
    }
    
    std::cout << "=== Hacker Challenge 3/28/2024 ===" << std::endl;

    // prepare
    std::list<int> listenerPositions = {1, 5, 11, 20};
    std::list<int> towerPositions = {4, 8, 15};
    
    // execute
    int recommendedBroadcastRange = getRecommendedBroadcastRange(listenerPositions, towerPositions);

    // report
    std::cout << "The recommended broadcast range to reach all listeners is " << recommendedBroadcastRange << std::endl;

    return 0;
}