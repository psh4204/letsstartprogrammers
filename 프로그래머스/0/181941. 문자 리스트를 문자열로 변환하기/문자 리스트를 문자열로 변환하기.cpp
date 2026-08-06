#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    for(auto ch: arr)
        answer += ch;
    return answer;
}