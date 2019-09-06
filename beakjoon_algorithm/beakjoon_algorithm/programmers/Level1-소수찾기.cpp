//
//  Level1-소수찾기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
//bool prime(int n){
//
//    if(n < 2){
//        return false;
//    }
//
//    for(int i=2; i*i<=n; i++){
//        if(n % i == 0){
//            return false;
//        }
//    }
//    return true;
//}

int main(void){
    int check[101];
    int prime[101];
    int n = 10;
    int cnt = 0;
    check[0] = check[1] = true;
    for(int i=2; i<=n; i++){
        if(check[i] == false){
            for(int j=i*i; j<=n; j+=i){
                    check[j] = true;
            }
            
        }
    }
    for(int i=2; i<=n; i++){
        if(check[i] == false){
            cnt += 1;
        }

    }
        cout << cnt;

    return 0;
}

