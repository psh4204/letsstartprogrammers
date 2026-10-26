/* 폰켓몬.
[문제]
총 N마리의 폰켓몬 중 N/2마리를 가져가도됨. (4마리면 2마리 가능)
번호로 관리되고 같은종류의 폰켓몬도 있음.
우리는 최대한 다양한 종류의 폰켓몬을 선택하려함.
nums 배열 내에서 최대 몇종류를 가질수있는지 return하라.
- nums길이는 1~10,000
- 폰켄못종류는 1~200,000


[풀이]
몇종류의 폰켓몬이 있나 먼저 정리한 후,
N/2보다 많으면 N/2를 뱉고, 아니면 몇종류까지있는지 뱉으면될듯.
set 쓰면 한방에 끝날듯
*/

#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int numSize = nums.size();
    set<int> pockets;
    
    for(int pocket: nums)
    {
        pockets.insert(pocket);
    }
    
    if(numSize == 1)
    {
        answer = 1;
    }
    else if((numSize/2) <= pockets.size())
    {
        answer = numSize/2;
    }
    else
    {
        answer = pockets.size();
    }
    return answer;
}