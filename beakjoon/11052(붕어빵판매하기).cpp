/*
 문제
 강남역에서 붕어빵 장사를 하고 있는 해빈이는 지금 붕어빵이 N개 남았다.
 
 해빈이는 적절히 붕어빵 세트 메뉴를 구성해서 붕어빵을 팔아서 얻을 수 있는 수익을 최대로 만드려고 한다. 붕어빵 세트 메뉴는 붕어빵을 묶어서 파는 것을 의미하고, 세트 메뉴의 가격은 이미 정해져 있다.
 
 붕어빵 i개로 이루어진 세트 메뉴의 가격은 Pi 원이다.
 
 붕어빵이 4개 남아 있고, 1개 팔 때의 가격이 1, 2개는 5, 3개는 6, 4개는 7인 경우에 해빈이가 얻을 수 있는 최대 수익은 10원이다. 2개, 2개로 붕어빵을 팔면 되기 때문이다.
 
 1개 팔 때의 가격이 5, 2개는 2, 3개는 8, 4개는 10 인 경우에는 20이 된다. 1개, 1개, 1개, 1개로 붕어빵을 팔면 되기 때문이다.
 
 마지막으로, 1개 팔 때의 가격이 3, 2개는 5, 3개는 15, 4개는 16인 경우에는 정답은 18이다. 붕어빵을 3개, 1개로 팔면 되기 때문이다.
 
 세트 메뉴의 가격이 주어졌을 때, 해빈이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
 
 입력
 첫째 줄에 해빈이가 가지고 있는 붕어빵의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
 
 둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)
 
 출력
 해빈이가 얻을 수 있는 최대 수익을 출력한다.
 
 예제 입력 1
 4
 1 5 6 7
 예제 출력 1
 10
 예제 입력 2
 5
 10 9 8 7 6
 예제 출력 2
 50
 예제 입력 3
 10
 1 1 2 3 5 8 13 21 34 55
 예제 출력 3
 55
 예제 입력 4
 10
 5 10 11 12 13 30 35 40 45 47
 예제 출력 4
 50
 예제 입력 5
 4
 5 2 8 10
 예제 출력 5
 20
 예제 입력 6
 4
 3 5 15 16
 예제 출력 6
 18
 
 
 
*/

//
//  11052(붕어빵판매하기).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 13..
//  Copyright © 2018년 kgh. All rights reserved.
//

//================================================
// Filename : 11052_Bungeoppang
//
// Solved by PSDent.
//
// https://www.acmicpc.net/problem/11052
//================================================
/*
#include <iostream>
#include <stdio.h>
using namespace std;

int dp[1001], set[1001], N;
int max(int a, int b) {
    return a > b ? a : b;
}
void DP() {
    dp[1] = set[1];

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j] + set[j]);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> set[i];
    }
    
    DP();
    cout << dp[N];
    return 0;
    
}
 
 */

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;          // 입력 최대붕어
    int fish_price[1001];   // 붕어 가격
    int dp[1001];           // 붕어 저장 dp
    scanf("%d", &n);        // 붕어 수 입력
    
    // 붕어 가격 입력
    for (int i = 1; i <= n; i++){
        scanf("%d", &fish_price[i]);
    }
    
    // dp[i] = i-j번째 최댓값 + j개 세트의 가격(하나씩모두 비교하기 위해서 2중포문)
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            // 최대값일경우만 dp[i]에 저장
            if (dp[i] < dp[i-j] + fish_price[j]){
                dp[i] = dp[i-j] + fish_price[j];
            }
        }
    }
    
    // 붕어 새끼 출력
    printf("%d", dp[n]);
    return 0;
}
