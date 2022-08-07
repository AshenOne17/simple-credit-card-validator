#pragma once

#include <string>
#include <vector>

int input();

void consoleClear();

std::string getCardNumber(int num);

bool isStringNumber(const std::string& string);

int notDoubledNumberSum(const std::vector<int>& vector);

int doubledNumberSum(const std::vector<int>& vector);

void cardNumberConvert(const std::string& string, std::vector<int>& vector);