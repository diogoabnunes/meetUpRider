//
// Created by clara on 08/05/2020.
//

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

/*double distance(Local &sourc, Local &dest) {
    return sqrt(pow(sourc.getX()-dest.getX(),2)+pow(sourc.getY()-dest.getY(),2));
}*/

void wait() {
    cout << "ENTER to continue";
    getchar();
}


