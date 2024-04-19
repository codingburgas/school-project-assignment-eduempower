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