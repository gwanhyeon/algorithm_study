//
//  GCD-SUM.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
        
    }else {
        int r = gcd(b,a%b);
        return r;
    }
}
int main(void){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int a[111];
        int n;
        cin >> n; // 앞에 개수가 있구나
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        // 데이터 처리 생각
        
        long long sum = 0;
    
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum += gcd(a[i],a[j]);
            }
        }
        cout << sum << endl;
        
        
        
        
    }
    
    return 0;
}
