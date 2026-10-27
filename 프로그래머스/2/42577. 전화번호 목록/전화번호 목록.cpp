/* 전화번호 목록
[문제]
전화번호부에서 특정번호가 다른번호 앞에 겹치는지 체크한 후 true,false를 반환한다.
- 전화번호는 1~1,000,000 개다.
- 각 번호의 길이는 1~20 개다.
- 같은 전화번호가 중복저장되어있지않다.
- 겹치면 false, 안겹치면 true.

[풀이]
sort로 문자열번호 정렬후 번호가 들어가있는지 체크하는 2중루프로 해결해보자
*/

#include "bits/stdc++.h"
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int bookSize = phone_book.size();
    sort(phone_book.begin(),phone_book.end());
    
    for(int y = 0; y <bookSize-1; y++)
    {
        int nextY = y+1;
        if(phone_book[y].size() >= phone_book[nextY].size())
        {
            continue;
        }
        for(int x = 0; x < phone_book[y].size(); x++)
        {
            if(phone_book[y][x] != phone_book[nextY][x])
            {
                break;
            }
            if(x == phone_book[y].size()-1)
            {
                return false;
            }
        }
    }
    return answer;
}