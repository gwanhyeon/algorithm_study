//
//  prime_number.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 16/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
bool prime(int n){
    if(n < 2){
        return false;
    }
    // i 초기값을 0으로 해주어서 런타임 에러가 났었음.. 왜그런지는 모르겠고, 일단..
    
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

int main(void){
    int n;
    cin >> n;
    int cnt=0;
    
    for(int i=0; i<n; i++){
        // n개의 개수만큼 값을 입력해주기 위함.
        int num;
        cin >> num;
        // true만 반환되었을때 값 처리 해준다.
        if(prime(num)){
            cnt++;
            
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
