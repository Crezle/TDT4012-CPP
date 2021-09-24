// 1a)
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>

void vectorIterator (std::vector<std::string> v);

// 1b)

void reverseVectorIterator (std::vector<std::string> v);

// 1c)

void replace (std::vector<std::string>& v, std::string old, std::string replacement);

// 1d)

void setIterator (std::set<std::string> s);

void reverseSetIterator (std::set<std::string> s);

void setReplace (std::set<std::string>& s, std::string old, std::string replacement);
