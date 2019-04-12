//
//  카드 구매하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(10001);
int dp[1001];
int main(void){
    
    int n;
    cin >> n;
    // n개 까지의 가격을 입력받는다.
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    // n개 만큼의 값을 입력받고 i-j까지의 수를 넘어갈 수 없으므로, max를
    // i-j까지 p값을 더해나가면서 이용하여 최댓값을 구해준다.
    // 결국 최종 n의 값에 최대값이 들어가있는것을 확인 할 수 있다.
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i],dp[i-j]+p[j]);
        }
    }
    cout << dp[n];
    
    return 0;
}
