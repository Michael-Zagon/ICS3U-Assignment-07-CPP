// Copyright (c) 2021 Michael Zagon All rights reserved

// Created by: Michael Zagon
// Created on: October 2021
// This program checks whether an element occurs in a list

#include <iostream>
#include <random>
#include <array>

template<size_t N>
int check(int integerFromUser, std::array<int, N> randomList) {
    // This function checks if a number is in the list
    int isItThere;

    for (int counter = 0; counter < randomList.size(); counter++) {
        if (integerFromUser == randomList[counter]) {
            isItThere = 1;
        } else {
            isItThere = 2;
        }
    }
    return isItThere;
}


int main() {
    std::array<int, 10> generatedRandomList;
    int randomNumber;
    std::string userInput;
    int userInteger;
    int isTheNumberInList;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 25);

    for (int counter = 0; counter < 10; counter++) {
        randomNumber = idist(rgen);
        generatedRandomList[counter] = randomNumber;
    }
    std::cout << "\n" << std::endl;

    std::cout << "What integer are you searching for? (0-25): ";
    std::cin >> userInput;
    std::cout << "" << std::endl;

    try {
        userInteger = std::stoi(userInput);
        isTheNumberInList = check(userInteger, generatedRandomList);
        if (isTheNumberInList == 1) {
            std::cout << "\nThe number " << userInteger
            << " is in the list." << std::endl;
        } else {
            std::cout << "\nThe number " << userInteger
            << " is not in the list." << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
