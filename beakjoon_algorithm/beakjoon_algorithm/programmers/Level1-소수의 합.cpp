//
//  Level1-소수의 합.cpp
//  beakjoon_algorithm
//  Created by kgh on 06/08/2019.
//  Copyright © 2019 kgh. All rights reserved.

// 에라토스테네스의 체
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n = 7;
    vector<bool> check(n+1);
    long long answer = 0;
    
    check[0] = check[1] = true;
    
    for(int i=2; i*i<=n; i++){
        if(check[i] == false){
            for(int j=i+i; j<=n; j+=i){
                check[j] = true;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(check[i] == false){
            answer += i;
            cout << i;
        }
    }
    cout << answer;
    
    return 0;
}

/*
 또다른 풀이인데, 너무 획기적으로 잘구현하였음
 */
/*
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    bool check[10000001] = {false, };
    for (int i=2; i<=N; i++) {
        if (!check[i]) answer += i;
        for (int j=i; j<=N; j+=i) {
            check[j] = true;
        }
    }
    return answer;
}
*/
