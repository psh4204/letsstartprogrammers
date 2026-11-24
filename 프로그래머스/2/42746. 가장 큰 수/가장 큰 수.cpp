/* 가장 큰 수
0 이상의 정수들이 주어지면, 정수들을 이어붙여 가장큰수를 알아낸다.
- 배열길이는 1~100,000
- 숫자는 0~1000
- string으로 return한다.

[풀이]
- 해당 숫자 전체로 봤을때 가장 큰 조합이니, string으로 greater sort하면 될듯.
*/

#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (const string & a, const string & b) const
    {
        string ab = a+b;
        string ba = b+a;
        return ab > ba;
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;
    for(auto & num: numbers)
    {
        strNums.push_back(to_string(num));
    }
    sort(strNums.begin(),strNums.end(),cmp());
    for(auto & strNum: strNums)
    {
        answer+=strNum;
    }
    if(answer[0] == '0')
    {
        return "0";
    }
    return answer;
}