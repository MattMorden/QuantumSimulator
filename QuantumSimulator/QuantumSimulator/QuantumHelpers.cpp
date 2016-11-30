/*
	QuantumHelpers.cpp
	Matthew Morden
	November 25, 2016
	Implementation file for QuantumHelpers.h
*/

#include "QuantumHelpers.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


/*
Name:	GenerateBitOutput
Purpose:To generate the correct output for 64 bits
Accepts:Two string type vectors: correctChoice and randomBits
Returns:A string type vector
*/
std::vector<std::string> GenerateBitOutput(std::vector<std::string> correctChoice, std::vector<std::string> randomBits)
{
	std::vector<std::string> bitOutput;
	for (unsigned i = 0; i < 64; ++i) {
		if (correctChoice[i] == "Y") {
			if (randomBits[i] == "-" || randomBits[i] == "/") {
				bitOutput.push_back("0");
			}
			else {
				bitOutput.push_back("1");
			}
		}
		else {
			bitOutput.push_back(" ");
		}
	}
	return bitOutput;
}

/*
Name:	GeneratePerceivedBits
Purpose:To generate 64 perceived bits, based on the bits sent with the filter
Accepts:Two string type vectors: bits and filters
Returns:A string type vector
*/
std::vector<std::string> GeneratePerceivedBits(std::vector<std::string> bits, std::vector<std::string> filters)
{
	std::vector<std::string> perceivedBits;
	for (unsigned i = 0; i < 64; ++i) {
		if (filters[i] == "+") {
			if (bits[i] == "-") { perceivedBits.push_back("-"); }
			else if (bits[i] == "|") { perceivedBits.push_back("|"); }
			else if (bits[i] == "\\") { perceivedBits.push_back("|"); }
			else if (bits[i] == "/") { perceivedBits.push_back("-"); }
		}
		else if (filters[i] == "X") {
			if (bits[i] == "-") { perceivedBits.push_back("/"); }
			else if (bits[i] == "/") { perceivedBits.push_back("/"); }
			else if (bits[i] == "|") { perceivedBits.push_back("\\"); }
			else if (bits[i] == "\\") { perceivedBits.push_back("\\"); }
		}
	}
	return perceivedBits;
}

/*
Name:	GenerateCorrectChoice
Purpose:To generate the if the perceived bits are the correct choice (the same) as the random bits
Accepts:Two string type vectors: randBits and perceivedBits
Returns:A string type vector
*/
std::vector<std::string> GenerateCorrectChoice(std::vector<std::string> randBits, std::vector<std::string> perceivedBits)
{
	std::vector<std::string> correctChoice;
	for (int i = 0; i < 64; i++) {
		if (randBits[i] == perceivedBits[i]) { correctChoice.push_back("Y"); }
		else { correctChoice.push_back("N"); }
	}
	return correctChoice;
}

/*
Name:	GenerateFilters
Purpose:To generate random bit filters
Accepts:Nothing
Returns:A string type vector
*/
std::vector<std::string> GenerateFilters()
{

	std::vector<std::string> randomFilters;
	int randNum;
	for (unsigned i = 0; i < 64; ++i) {
		randNum = rand() % 2;
		switch (randNum) {
		case 0:
			randomFilters.push_back("+");
			break;
		case 1:
			randomFilters.push_back("X");
			break;
		default:
			randomFilters.push_back("Default called");
			break;
		}
	}
	return randomFilters;
}

/*
Name:	GenerateRandomBits
Purpose:To generate 64 random bits
Accepts:Nothing
Returns:A string type vector
*/
std::vector<std::string> GenerateRandomBits()
{

	std::vector<std::string> randomBits;
	int randNum;

	for (unsigned i = 0; i < 64; ++i) {
		randNum = rand() % 4;
		switch (randNum) {
		case 0:
			randomBits.push_back("-");
			break;
		case 1:
			randomBits.push_back("/");
			break;
		case 2:
			randomBits.push_back("|");
			break;
		case 3:
			randomBits.push_back("\\");
			break;
		default:
			randomBits.push_back("Default called");
			break;
		}
	}
	return randomBits;
}

/*
Name:	DisplayResults
Purpose:To diplay the results of the generated bits, and how they were perceived with the filters
Accepts:Nothing
Returns:Nothing, but will display results through iostream
*/
void DisplayResults() {
	//Generate and assign the random bits, filters, perceived bits, correct choice, and output bits.
	srand(time(NULL));
	std::vector<std::string> randomBits = GenerateRandomBits();
	std::vector<std::string> randomFilters = GenerateFilters();
	std::vector<std::string> perceivedBits = GeneratePerceivedBits(randomBits, randomFilters);
	std::vector<std::string> correctChoice = GenerateCorrectChoice(randomBits, perceivedBits);
	std::vector<std::string> bitOutput = GenerateBitOutput(correctChoice, randomBits);

	//Display the Results
	std::cout << "Sent" << "\tFilter Used" << "\tPerceived Bits" << "\tCorrect Choice" << "\t\tBit Output" << std::endl;

	for (int i = 0; i < 64; i++) {
		std::cout <<
			randomBits[i] << "\t\t" << randomFilters[i] << "\t\t" << perceivedBits[i] << "\t\t" <<
			correctChoice[i] << "\t\t" << bitOutput[i] << std::endl;
	}
}