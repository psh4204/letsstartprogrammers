/* 더맵게
스코빌지수 K. 스코빌 지수가 가장낮은 두개의 음식 두개를 섞어서 만듬
- 섞은 스코빌지수 = 가장맵지않은 스코빌지수 / (두번째로 맵지않은 스코빌지수*2)

Leo가 원하는 스코빌지수 K이상이 될때까지 계속 썩을거임.
- scoville: 스코빌지수 배열 (길이 2~ 1,000,000)
- K: 원하는 스코빌지수 (0~1,000,000,000)

모든음식의 스코빌지수가 K이상으로 만들어지기 위해 섞어야하는 최소 횟수를 return하자.
- K이상으로 못만들경우 -1 return.

[풀이]
pq 활용해서 시뮬돌리면 될듯. (오름차순으로 ㅇㅇ) 
*/

#include "bits/stdc++.h"
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto sc : scoville)
    {
        pq.push(sc);
    }
    
    while(pq.top() < K && pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int mixed = first + (second*2);
        pq.push(mixed);
        answer++;
    }
    if(pq.top() < K)
    {
        answer = -1;
    }
    
    return answer;
}