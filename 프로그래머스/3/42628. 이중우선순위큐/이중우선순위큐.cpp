/* 이중 우선순위 큐
명령어 세가지
- I 숫자: 큐에 주어진 숫자 삽입
- D 1: 큐에서 최대값 삭제
- D -1: 큐에서 최솟값 삭제

큐가 비어있으면 answer는 {0,0} 출력, 안비어있으면 {최대,최소} 출력

제한사항
- 문자열 길이 1~1,000,000 이하
- 문자열 하나는 단 하나의 명령만 담음. (최대,최소 값을 삭제하는 연산에서 최대/최소값이 둘 이상인 경우 하나만 삭제함. << ?)
- 빈큐에 데이터 삭제 명령이 들어오면 무시한다.
*/

#include "bits/stdc++.h"
using namespace std;
enum Oper{
    INSERT = 0,
    POP_FRONT,
    POP_BACK,
};
typedef struct {
    Oper cmd;
    int num;
}OpParse_t;

OpParse_t ParseOper(const string & oper)
{
    OpParse_t operation;
    if(oper[0] == 'I')
    {
        operation.cmd = INSERT;
        string strNum = oper.substr(2);
        operation.num = stoi(strNum);
    }
    else if(oper[0] == 'D')
    {
        operation.cmd = INSERT;
        if(oper[2] == '-')
        {
            operation.cmd = POP_BACK;
        }
        else
        {
            operation.cmd = POP_FRONT;
        }
    }
    return operation;
};

multiset<int, greater<int>> g_dpq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(auto & operation: operations)
    {
        OpParse_t op = ParseOper(operation);
        switch(op.cmd){
            case(INSERT):
            {
                g_dpq.insert(op.num);
                break;
            }
            case(POP_FRONT):
            {
                if(g_dpq.empty() == false)
                {
                    g_dpq.erase(g_dpq.begin());                
                }
                break;
            }
            case(POP_BACK):
            {
                if(g_dpq.empty() == false)
                {
                    g_dpq.erase(prev(g_dpq.end()));             
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
    if(g_dpq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(g_dpq.begin()));
        answer.push_back(*(prev(g_dpq.end())));
    }
    return answer;
}