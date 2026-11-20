/* 주식가격
[문제]
초단위로 기록된 주식가격이 담긴 배열에서
주식가격이 떨어지지 않는 기간이 몇초인이 return하라
- 가격은 1~10,000
- 가격들의 수는 2~100,000

[풀이]
(문제설명이 너무이상한데. 그냥헛소리이해력테스트하는건가)
-| 1 2 3 2 3
1| 0 1 1 1 1 (4)
2| - 0 2 2 2 (3)
3| - - 0 - - (?????)
2| - - - 0 2 (1)
3| - - - - 0 (0)

해당가격이 맨뒤에까지 유지되는 초가 몇인지 체크하라는건가?
-> 아님. 캐시써서 했는데 하아. 근데 예제는 그렇게해도 됨. 뭐야이게 

결론. 시간간 간격을 봐야함(몇번 보다가 도저히 안되겠어서 힌트받음.할말많다)
-| 1 2 3 2 3
1|  1 1 1 1  (4)
2|   2 2 2   (3)
3|      3    (1)
2|        2  (1)
3|           (0)

단순히 시뮬돌리면서 시간줄여보자
*/

#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    for(int startIdx = 0; startIdx < prices.size(); startIdx++)
    {
        int nowMoney = prices[startIdx];
        int checkIdx = startIdx;
        for( ; checkIdx < prices.size(); checkIdx++)
        {
            if(nowMoney > prices[checkIdx])
            {
                break;
            }
            if(checkIdx == prices.size()-1)
            {
                break;
            }
        }
        answer[startIdx] = checkIdx - startIdx;
    }
    
    return answer;
}