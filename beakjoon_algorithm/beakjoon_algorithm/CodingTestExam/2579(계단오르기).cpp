/*
 계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. <그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.
 
 
 
 예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째, 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.
 
 
 
 계단 오르는 데는 다음과 같은 규칙이 있다.
 
 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
 마지막 도착 계단은 반드시 밟아야 한다.
 따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세번째 계단을 연속해서 모두 밟을 수는 없다.
 
 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최대값을 구하는 프로그램을 작성하시오.
 
 입력
 입력의 첫째 줄에 계단의 개수가 주어진다.
 
 둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다. 계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.
 
 출력
 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최대값을 출력한다.
 
 예제 입력 1
 6
 10
 20
 15
 25
 10
 20
 예제 출력 1
 75
 
 
*/


//
//  2579(계단오르기).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 13..
//  Copyright © 2018년 kgh. All rights reserved.
//
/*
#include <stdio.h>
#include <iostream>

using namespace std;
int main(void){
    
    int stair_num;
    int stair_score[300];       // 계단 개수 300이하
    
    
    printf("계단수를 입력하시오");
    scanf("%d",&stair_num);
    
    
    printf("계단 점수를 입력하시오");
    for(int i=0; i<stair_num; i++){
        scanf("%d",&stair_score[i]);
    }
    // 다음 or 다다음 가능

    // 1계단씩 오르는 경우

    // 2계단씩 오르는 경우
    
    // 세개 계단은 모두 밟으면 안된다.
    
    // 마지막 계단 밟으면 안된다
    
    // 이게임에서 얻을 수 있는 총 정수 max 최대값
}
 
 */

/*

#include <stdio.h>
#include <iostream>
using namespace std;
int max_score(int a, int b)
{
    return a > b ? a : b;
}
int main(void){
    
    int stair_num;                  // 계단수 변수
    int stair_score[303] = {};      // 계단수 300
    int store[303] = {};            // 저장 배열 변수
    scanf("%d", &stair_num);        // 계단수 입력
    
    // 점수 입력
    for (int i = 1; i <= stair_num; i++){
        scanf("%d", &stair_score[i]);
    }
    for (int i=1; i <=3 && i<=stair_num; i++){
        if (i!=3){
            store[i] = store[i - 1] + stair_score[i];
        }
        else{
            store[i] = max_score(stair_score[i] + store[i-2], stair_score[i] + stair_score[i-1]);
        }
    }
    for (int i=4; i<=stair_num; i++){
        store[i]=max_score(stair_score[i] + store[i-2], stair_score[i] + stair_score[i-1] + store[i-3]);
    }
    printf("%d\n", store[stair_num]);
}
*/



#include <stdio.h>
#include <iostream>
using namespace std;
int max_score(int a, int b)
{
    return a > b ? a : b;
}
int main(void){
    
    int stair_num;                  // 계단수 변수
    int stair_score[301] = {};      // 계단수 300
    int store[301] = {};            // 계단 저장 배열 변수(dp)
    scanf("%d", &stair_num);        // 계단수 입력
    
    // 계단 점수 입력
    for (int i = 1; i <= stair_num; i++){
        scanf("%d", &stair_score[i]);
    }
    store[1] = stair_score[1];

    //계단을 한번 밟았다고 생각하였을때 값 dp값 저장
    if(stair_num >= 2){
        store[2] = store[1]+stair_score[2];
    }
    
    for(int i=3; i<=stair_num; i++){
        // 계단이 한번연속인 경우 - N계단 N-1번째 계단 생각 X , N-2번째 계단의 총점 생각
        // 계단이 두번연속인 경우 - N계단 2번 연속일 경우 N-1계단은 밟아야함 , N-2밟아버리면 규칙어긋나버림 , N-3 계단까지 얻은 점수 합
        
        store[i] = max_score(store[i-2]+stair_score[i],store[i-3]+stair_score[i-1]+stair_score[i]);
    }
    
    printf("%d\n", store[stair_num]);
}




