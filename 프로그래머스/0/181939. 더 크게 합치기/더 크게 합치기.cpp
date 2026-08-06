#include <string>
#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int aSize = to_string(a).size(), bSize = to_string(b).size();
    
    answer = ((a * (pow(10,bSize))) + b) >= 
              ((b * (pow(10, aSize))) + a) ? 
              ((a * (pow(10,bSize))) + b): 
              ((b * (pow(10, aSize))) + a);
    return answer;
}