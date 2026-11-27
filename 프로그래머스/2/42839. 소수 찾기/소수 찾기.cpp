/* 소수찾기
한자리 수로 적힌 문자열이 주어지는데, 이 숫자조합으로 소수를 몇개 만들수 있는지 확인하라
- 숫자는 1~7개 주어짐
- 범위는 0~9
- 17-> 7,17,71

[풀이]
- 소수체크면 캐쉬 써야할텐
- 숫자 조합을 7가지를 해버리면 2^7 -1 = 127.
- 조합 + 소수점 찾기로 가면 되겠네
  - 7자리 수라고했으니까.. 0~9,999,999. 1000만개짜리 배열이라면, 너무 많은거 아님? -> 안터지네
  - 진행 하자 그래.
*/

#include <bits/stdc++.h>
#define MAX_NUM 10000000
using namespace std;
vector<bool> g_sosus(MAX_NUM,true);
unordered_set<int> g_nums;
vector<int> g_visited(7,0);
int g_maxNum = 0;
void GetSosus()
{
    g_sosus[0] = false;
    g_sosus[1] = false;
    for(int num = 2; num < MAX_NUM; num++)
    {
        if(g_sosus[num] == false)
        {
            continue;
        }
        for(int deepNum = num+num; deepNum < MAX_NUM; deepNum+=num)
        {
            g_sosus[deepNum] = false;
        }
    }
}

void GetCombi(string & strNum, string strCombi,vector<int> visited, int nowIdx)
{
    if(nowIdx >= strNum.size())
    {
        return;
    }
    for(int idx = 0; idx < strNum.size(); idx++)
    {
        if(visited[idx] == 1)
        {
            continue;
        }
        string combiNum = strCombi+ strNum[idx];
        int numIdx = stoi(combiNum);
        g_maxNum = max(g_maxNum, numIdx);
        visited[idx] = 1;
        g_nums.insert(numIdx);
        GetCombi(strNum, combiNum,visited,nowIdx+1);
        visited[idx] = 0;
    }
}

int solution(string numbers) {
    int answer = 0;
    GetCombi(numbers,"",g_visited,0);
    GetSosus();
    for(auto & num: g_nums)
    {
        if(g_sosus[num])
        {
            answer++;
        }
    }
    cout << endl;
    return answer;
}