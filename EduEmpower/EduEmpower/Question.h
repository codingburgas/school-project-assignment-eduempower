#pragma once
#include <iostream>
#include <string>
#include <vector>

class Questio {
public:
	int questionNumber;
	std::string question;
	std::vector<std::string> answers;
	int rightAnswerIndex;

	void toString() {
		std::cout << questionNumber << ". " << question << std::endl;
		for (size_t i = 0; i < answers.size(); i++) {
			std::cout << answers[i] << std::endl;
		}
		std::cout << "Right answer: " << answers[rightAnswerIndex];
	}
};