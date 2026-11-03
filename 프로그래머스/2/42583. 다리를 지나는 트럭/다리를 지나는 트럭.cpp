/*다리를 지나는 트럭
[문제]
트럭이 일차선다리를 정해진순서에 따라 최소 몇초가 걸리는지 알아봐야함
다리에 bridge_length 만큼 트럭이 올라가고, weight이하까지 무게를 견딜수있음.
- bridge_length 1~10000
- weight 1~10000
- truck_weight 1~10000

[풀이]
- bridge_length가 다리버퍼 크기. 시뮬돌릴때 큐처럼 배열짜서 쓰라는거네
- (5번정도 생각 고쳐먹고 정리 중)
- 한트럭씩 큐에 트럭을 집어넣는데, bridge_length 최대길이만큼 그냥 복붙해서 계속넣어줘야함
- 큐에 값이 들어갈때 무게체크해주고, 큐에서 값이 빼질때 무게체크또해서 다음값이 들어갈지 안들어갈지 판단
- 이렇게 시뮬돌려서 모든트럭들이 최소몇카운트에 빠져나오는지 체크한다.
- 문제에선 트럭의 조합을보진않는것으로 보이며 주어진 트럭 순서대로 그대로 시뮬돌리면됨
*/
#include "bits/stdc++.h"
using namespace std;
typedef struct{
    int weight;
    int idx;
}Truck_t;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int wSum = 0;
    int nowIdx = -1;
    queue<Truck_t> bQ;
    vector<Truck_t> trucks;
    
    // 트럭들 정리
    for(int truckIdx=0; truckIdx < truck_weights.size(); truckIdx++)
    {
        trucks.push_back({truck_weights[truckIdx],truckIdx});
    }

    do
    {
        // 1. 트럭 지나가기
        if((bQ.size() <= bridge_length) && ((int)nowIdx < (int)trucks.size()-1))
        {
            // 1.1. 지금 도로에 신규트럭 추가가능한지 (무게체크)
            if((bQ.size()==bridge_length)
               &&(wSum-bQ.front().weight+trucks[nowIdx+1].weight <= weight))
            {
                nowIdx+=1;
                wSum+=trucks[nowIdx].weight;
            }
            // 1.2. 최초의 신규트럭 추가가능한지
            else if(wSum+trucks[nowIdx+1].weight <= weight)
            {
                nowIdx+=1;
                wSum+=trucks[nowIdx].weight;
            }
            // 1.3. 그냥 그대로 지나가기
            else
            {
                
            }
        }
        bQ.push(trucks[nowIdx]);
        answer+=1;
        // 2. 지나간 트럭 정리하기
        if(bQ.size() > bridge_length)
        {
            // 2.1. 완전히 지나간 트럭 체크 후 바로 삭제
            Truck_t frontTruck = bQ.front();
            bQ.pop();
            // 2.2. 해당 트럭이 완전히 지나갔으면 무게삭제
            if(frontTruck.idx != bQ.front().idx)
            {
                wSum -= frontTruck.weight;
            }
            // 2.3. 혹시 마지막 트럭이면, 루프탈출 (answer는 이미 추가되어있음)
            if(frontTruck.idx == trucks[nowIdx].idx)
            {
                break;
            }
        }
    }while(bQ.empty()!=true);
    
    
    return answer;
}