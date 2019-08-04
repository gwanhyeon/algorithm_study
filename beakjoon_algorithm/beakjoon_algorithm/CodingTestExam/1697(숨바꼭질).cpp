/*
숨바꼭질
시간 제한    메모리 제한    제출    정답    맞은 사람    정답 비율
2 초    128 MB    35272    9761    6127    24.946%
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때
 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1
5 17
예제 출력 1
4
힌트
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
 */
#include <stdio.h>
#include <queue>
#include <iostream>

bool Check[100000]={0,};            // 모든 배열 값 0 으로 초기화

using namespace std;
int main(void){
    int result_time= 0;                 // 최종 시간 저장
    int me,sister;                      // 수빈 , 동생
    int cur,cnt;
    queue<pair<int,int>> q;         // Queue pair
    cin >> me >> sister;            // 수빈,동생 Input
    q.push(pair<int,int>(me,0));    // 수빈이의 위치 Queue
    
    while(!q.empty()){
        cur = q.front().first;          // 수빈 위치 가져오기
        cnt = q.front().second;         // 수빈 위치 인덱스
        q.pop();                        // 큐 맨앞에 있는것들 pop
        
        // 범위 체크
        if (cur < 0 || cur > 100000){
            continue;
        }
        // 중복 체크
        if (Check[cur]){
            continue;
        }
        Check[cur] = true;          // Check배열에 수빈 위치 체크
        
        // 수빈이의 거리와 동생의 거리가 같을경우
        if(cur == sister){
            result_time = cnt;
        }
    
        q.push( pair<int,int>(cur * 2 , cnt + 1));          // 수빈위치에서 2배 증가
        q.push( pair<int,int>(cur + 1 , cnt + 1));          // 위치에서 -1 체크 (범위 체크 및 중복체크에서 처리)
        q.push( pair<int,int>(cur - 1 , cnt + 1));          // 위치에서 +1 체크 (범위 체크 및 중복체크에서 처리)
    }
    
    printf("%d", result_time);

    return 0;
    
}
