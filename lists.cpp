// Copyright (c) 2023 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Dec 17, 2023
// This program will calculate the average of
// 10 nums with user input

#include <iostream>
#include <list>
#include <stdexcept>

// Function to calculate the average of a list of integers
double calcAverage(const std::list<int>& listOfMarks) {
    double sum = 0;

    // Loop through the list and calculate the sum
    for (int mark : listOfMarks) {
        sum += mark;
    }

    // find avg
    sum = sum / listOfMarks.size();

    // Return the calculated average
    return sum;
}

int main() {
    // Create a list to store user input marks make other variables
    std::list<int> listOfMarks;
    int userMarkInt;
    double average;

    // Display program information to the user
    std::cout
        << "This program calculates the average of the numbers you insert."
        << std::endl;

    do {
        try {
            // Get marks
            std::cout <<
            "Enter a mark between 0 and 100 (use negative to stop): ";
            std::cin >> userMarkInt;

            // Check if the entered mark is greater than 100
            if (userMarkInt > 100) {
                std::cout << userMarkInt << " is greater than 100."
                << std::endl;
            } else {
                // Add the mark to the list
                listOfMarks.push_back(userMarkInt);
            }
        } catch (std::exception) {
            // Check if input is invalid
            std::cout << "Invalid input. Please enter a valid integer."
            << std::endl;
        }
    } while (userMarkInt > 0);
    // remove last input
    listOfMarks.pop_back();
    // Check if the user entered at least one number
    if (listOfMarks.size() == 0) {
        std::cout << "Please enter a number." << std::endl;
    } else {
        // Calculate and display the average of the marks
        average = calcAverage(listOfMarks);
        std::cout << "\nAverage of marks: " << average << std::endl;
    }
}
