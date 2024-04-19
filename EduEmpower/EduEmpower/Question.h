#pragma once
#include <iostream>
#include <string>
#include <vector>

class Question {
public:
	int questionNumber;
	// Holds the text of the question
	std::string question; 

	// Holds a list of possible answers to the question
	std::vector<std::string> answers;
	int rightAnswerIndex;

	// Public member function to print the question and answers
	void toString() {
		// Print the question number and text
		std::cout << questionNumber << ". " << question << std::endl;
		// Loop through each answer and print it
		for (size_t i = 0; i < answers.size(); i++) {
			std::cout << answers[i] << std::endl;
		}
		std::cout << "Right answer: " << answers[rightAnswerIndex];
	}
};