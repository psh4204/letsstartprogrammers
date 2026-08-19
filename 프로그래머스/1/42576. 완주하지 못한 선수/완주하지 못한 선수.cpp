#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> runners;
    for(auto part: participant)
    {
        if(runners.find(part) == runners.end())
            runners.insert({part,1});
        else
            runners[part]++;
    }
    for(auto complet: completion)
    {
            runners[complet]--;
    }
    for(auto runner: runners)
    {
        if(runner.second >= 1)
        {
            answer = runner.first;
            break;
        }
    }
    
    return answer;
}