#include "utils.h"

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

string to_lower(string s)
{
    string result;
    for (char c : s)
    {
        result += tolower(c);
    }
    return result;
}

chrono::system_clock::time_point start;
chrono::system_clock::time_point finish;

void startTime()
{
    start = chrono::high_resolution_clock::now();
}

double elapsedTime()
{
    finish = std::chrono::high_resolution_clock::now();
    auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
    return mili;
}