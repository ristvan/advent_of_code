#pragma once

#include <string>

bool isValidPassword(const std::string& passwordCandidate);

std::string nextPasswordCandidate(const std::string& passwordCandidate);

std::string findTheNextValidPassword(const std::string& statingPassword);