/* 하드디스크
가상의 우선순위 디스크 컨트롤러를 쓴다고 가정한다.
1. 작업번호,요청시각,작업소요시간 을 저장하는 '대기큐'가 있음. (처음엔 비어있음)
2. 아무 작업이 없을땐, 대기큐에서 우선순위가장 높은걸 꺼내서 작업시킴.
  - 소요시간이 짧은것, 요청시각이 빠른것, 작업번호가 작은것 순으로 우선적임.
3. 작업은 시작하면 끝날때까지 그것만 함.
4. 작업 도중에 작업요청시간으로 인해 다른 요청이 온다면 해당 작업은 대기큐에 넣어야함.
  - 작업이 마치는 시점에 새작업이 들어올 수 있음. (시간카운트도 안됨)

변수
- jobs(작업) 개수는 1~500
- jobs[i]: i번 작업. 내부 변수 두개는 (요청되는 시점 0~1000, 작업소요시간 1~1000)

[풀이]
- 우선순위 큐를 쓰되, 요청시간별로 정렬 후에, 요청시간 별로 job을 투입해야함
- 큐는 두가지: 작업큐, 대기큐
   - 작업큐: 요청시간 순으로 정리됨
   - 대기큐: 작업중에 대기시킬 큐로써 2번에 언급된 규칙으로 대기큐가 생성됨.
- 1time 씩 동작하는 루프를 만들어서, 작업큐에서 작업을 가져와서 시키고, 작업중이라면 대기큐에 넣어서 관리하는 형식으로 시뮬레이션 진행한다.
   - 단, 작업이 끝나는 타이밍에 새로운 작업을 바로 기입하여 새작업 카운트가 겹치도록(세지 않도록) 진행한다.
- 각 작업별로 요청시간별 얼마나 걸렸는지 체크후에 평균내서 답을 구해야함.
*/

#include "bits/stdc++.h"
using namespace std;
typedef struct{
    int idx;
    int reqT;
    int loadT;
}Job_t;

struct CmpJob{
    bool operator() (const Job_t a, const Job_t b)const{
        if(a.reqT != b.reqT)
        {
            return a.reqT > b.reqT;
        }
        return false;
    }
};

struct CmpReady{
    bool operator() (const Job_t a, const Job_t b)const{
        // 소요시간이 짧은것, 요청시각이 빠른것, 작업번호가 작은것 순으로 우선적임
        if(a.loadT != b.loadT)
        {
            return a.loadT > b.loadT;
        }
        if(a.reqT != b.reqT)
        {
            return a.reqT > b.reqT;
        }
        if(a.idx != b.idx)
        {
            return a.idx > b.idx;
        }
        return false;
    }
};

priority_queue <Job_t, vector<Job_t>, CmpJob> g_jobs;
priority_queue <Job_t, vector<Job_t>, CmpReady> g_ready;
vector<Job_t> g_work;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    for(int jIdx = 0; jIdx < jobs.size(); jIdx++)
    {
        g_jobs.push({jIdx, jobs[jIdx][0], jobs[jIdx][1]});
    }
    
    do
    {
        // 1.지금 일할 것들 대기큐 처리
        while((g_jobs.empty() == false) && (g_jobs.top().reqT <= time))
        {            
            g_ready.push(g_jobs.top());
            g_jobs.pop();
        }
        
        // 2. 진행중인 일이 있는지 없는지 체크
        if(g_work.empty()==false)
        {
            // 2.1. 진행중인 일이 끝 났을 때 일 삭제
            if(g_work[0].loadT <=0)
            {
                answer += time - g_work[0].reqT;
                g_work.pop_back();
                // 대기큐에 일이 있다면 삽입
                if(g_ready.empty()== false)
                {
                    g_work.push_back(g_ready.top());
                    g_ready.pop();
                }
            }
        }
        else if(g_work.empty() &&(g_ready.empty() == false))
        {
            // 2.2. 진행중인 일이 아예 없을 때
            // 대기큐에 일이 있다면 삽입
            g_work.push_back(g_ready.top());
            g_ready.pop();
        }
        // 일 처리
        if(g_work.empty() == false)
        {
            g_work[0].loadT -=1;
        }
        // 시간 처리
        time +=1;
    }while(g_work.empty()==false || g_jobs.empty()==false); // 일 다마치면 끝.
    
    answer = answer/jobs.size();
    return answer;
}