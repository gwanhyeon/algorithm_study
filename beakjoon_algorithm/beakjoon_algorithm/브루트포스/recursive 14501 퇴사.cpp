//
//  14501 퇴사.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
1. N+1날 퇴사 (정답)
2. N+1날 이상되면 (비정답)
금액의 최댓값
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int t[16];
int p[16];
int ans=0;
int n;
void recursive(int sum, int time){
    
    // 정답
    if(time == n+1){
        if(ans < sum){
            ans = sum;
        }
        return;
        
    }
    // 비정답
    if(time > n+1){
        return;
    }
    recursive(sum, time+1);
    recursive(sum+p[time],time+t[time]);

}

int main(void){
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> t[i];
        cin >> p[i];
        
    }
    recursive(0,1);
    cout << ans << '\n';
    
    return 0;
}
