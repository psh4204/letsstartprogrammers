/* H-Index
과학자의 스탯인 h는 이렇게 구해짐
- 논문 수 n 중에서 h번이상 인용된논문이 h편 이상, 
- 나머지 논문이 h번 이하 인용되었다면 h의 최대값이 그 스탯값이 됨

논문 인용횟수를 담은 배열 citations을 통해 h를 리턴하라
- 논문수 N은 1~1000 편
- 논문 인용횟수는 0~10,000

[풀이]
- 논문중에서 h번 이상 된 논문이 h번 이상이면 논문수가 메인임. 
글구 나머진 안봐도 됨.
*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int hIdx = 0; hIdx < citations.size(); hIdx++)
    {
        if(citations[hIdx] <=hIdx)
        {
            answer = hIdx;
            break;
        }
    }
    if(answer == 0 && citations[citations.size()-1] > 0)
    {
        if(citations.size() <= citations[citations.size()-1])
        {
            answer = citations.size();
        }
        else
        {
            answer = citations[citations.size()-1];
        }
    }
    return answer;
}