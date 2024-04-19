#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "Question.h"

// Function to calculate the length of a string
int len(std::string str) {
	int length = 0;
	/*Iterates over the characters of the string str until it encounters the null character '\0',
	  at which point it knows it has reached the end of the string.*/ 
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

// Function to split a string based on a separator character
std::vector<std::string> split(std::string str, char seperator) {
	// Create a vector to store the resulting strings
	std::vector<std::string> strings; 
	int i = 0;
	int startIndex = 0, endIndex = 0;
	// Loop through each character of the string
	while (i <= len(str)) {
		// Check if the current character is the separator or if it's the end of the string
		if (str[i] == seperator || i == len(str))
		{
			endIndex = i;
			// Extract the substring from the original string and add it to the vector
			std::string subStr = " ";
			// Extract the substring
			subStr.append(str, startIndex, endIndex - startIndex);
			// Add the substring to the vector
			strings.push_back(subStr);
			startIndex = endIndex + 1;
		}
		i++;
	}
	return strings;
}

// Function to read questions from a file and return them as a vector
std::vector<Question> getAllQuestions(std::string testName)
{
	std::vector<Question> questions;
	// Create a file stream object
	std::fstream dataFile;

	// Open the file for reading
	dataFile.open(testName, std::ios::in);
	if (dataFile.is_open()) {
		// Variable to store each lines of the file
		std:: string line;

		// Read each line of the file until the end is reached
		while (getline(dataFile, line)) {
			// Split the line into substrings using '|' as the separator
			std::vector<std::string> strings = split(line, '|');
			if (strings.size() != 6) {
				return questions;
			}

			Question question;
			// Set the question number by converting the string at index 0 to an integer
			question.questionNumber = stoi(strings[0]);
			question.question = strings[1];
			// Add the first answer option to the question object by appending it to the 'answers' vector
			question.answers.push_back(strings[2]);
			// Add the second answer option
			question.answers.push_back(strings[3]);
			// Add the third answer option
			question.answers.push_back(strings[4]);
			// Set the index of the correct answer by converting the string at index 5 to an integer
			question.rightAnswerIndex = stoi(strings[5]);

			questions.push_back(question);
		}
		dataFile.close();
	}
	return questions;
}