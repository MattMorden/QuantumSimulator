/*
	QuantumHelpers.h
	Matthew Morden
	November 25, 2016
	Header file to contain method declarations to be used in the Quantum Simulator
*/

#ifndef __QUANTUM_HELPERS_H__
#define __QUANTUM_HELPERS_H__

#include <vector>
#include <string>

std::vector<std::string> GenerateBitOutput(std::vector<std::string> correctChoice, std::vector<std::string> randomBits);
std::vector<std::string> GeneratePerceivedBits(std::vector<std::string> bits, std::vector<std::string> filters);
std::vector<std::string> GenerateCorrectChoice(std::vector<std::string> randomBits, std::vector<std::string> perceivedBits);
std::vector<std::string> GenerateFilters();
std::vector<std::string> GenerateRandomBits();
void DisplayResults();

#endif