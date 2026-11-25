/* 모의고사
3명이서 모든문제를 다 찍을거임.
해당 시험의 정답이 들어간 배열이 주어지는데, 가장많이 문제를 맞힌사람이 누구인지 배열에 담아 리턴하라
- 시험은 최대 10,000문제
- 정답은 1~5
- 이들의 점수가 같으면 오름차순으로 리턴

[풀이]
- 각 문제 찍는 패턴을 분석한 후 진행하면 될듯
  - 1번: 1 2 3 4 5 ... 반복
  - 2번: 2 1 2 3 2 4 2 5 ... 반복
  - 3번: 3 3 1 1 2 2 4 4 5 5 ... 반복
- 이 배열로 정답배열에 대입하여 리턴값 가져오면 될듯
*/

#include "bits/stdc++.h"
using namespace std;

struct cmp{
    bool operator()(const pair<int,int> & a, const pair<int,int> & b) const{
        return a.second > b.second;
    }
};

vector<vector<int>> g_checkers = {
    {1,2,3,4,5},
    {2,1,2,3,2,4,2,5},
    {3,3,1,1,2,2,4,4,5,5}
};
vector<pair<int,int>> g_results;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int maxPoint = 0;
    for(int chIdx = 0; chIdx < 3; chIdx++)
    {
        pair<int,int> result ={chIdx+1,0};
        for(int pIdx = 0; pIdx < answers.size(); pIdx++)
        {
            int checker = pIdx%(g_checkers[chIdx].size());
            int ans = g_checkers[chIdx][checker];
            if(ans == answers[pIdx])
            {
                result.second++;
            }
        }
        maxPoint = max(maxPoint, result.second);
        g_results.push_back(result);
    }
    sort(g_results.begin(), g_results.end(), cmp());
    for(auto & res: g_results)
    {
        if(res.second == maxPoint)
        {
            answer.push_back(res.first);
        }
    }
    return answer;
}