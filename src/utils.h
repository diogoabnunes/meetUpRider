#ifndef MEETUPRIDER_UTILS_H
#define MEETUPRIDER_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;

vector<string> split(const string& str, const string& delim);

string to_lower(string s);

void startTime();

double elapsedTime();

#endif //MEETUPRIDER_UTILS_H
