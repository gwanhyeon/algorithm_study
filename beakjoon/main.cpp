#include <stdio.h>
#include <iostream>
using namespace std;
int max_score(int a, int b)
{
    return a > b ? a : b;
}
int main(void){
    
    int stair_num;                  // 계단수 변수
    int stair_score[303] = {};            // 계단수 300
    int store[301] = {};            // 저장 배열 변수
    scanf("%d", &stair_num);        // 계단수 입력
    
    // 점수 입력
    for (int i = 1; i <= N; i++){
        scanf("%d", &stair_score[i]);
    }
    for (int i=1; i <=3 && i<=stair_num; i++){
        if (i!=3){
            store[i] = store[i - 1] + stair_score[i];
        }
        else{
            store[i] = max_score(stair[i] + store[i-2], stair_score[i] + stair_score[i-1]);
        }
    }
    for (int i=4; i<=stair_num; i++){
        store[i]=max_score(stair[i] + store[i-2], stair_score[i] + stair_score[i-1] + store[i-3]);
    }
    printf("%d\n", store[stair_num]);
}



