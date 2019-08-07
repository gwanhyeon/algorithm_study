//
//  1748수이어쓰기1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    long long ans = 0;
    
    for(int start = 1, len=1; start <=n; start*= 10, len++){
        cout << "start" << start << endl;
        cout << "len" << len << endl;
        
        int end = start*10-1;   // 끝점
        cout << "end" << end << endl;
        // end가 n보다크면 그점이 끝점임
        if(end > n){
            end = n;
        }
        // 끝점에서 - 시작점을 빼면 자리수를 제외한 값이 나옴 거기서 *len을 곱하게 된다면 그 현재 len의 길이의 곱만큼이 나오게 된다.
        ans += (long long)(end-start +1) * len;
        cout << "ans" << ans << endl;
        
    }

    // 시간복잡도 측면에서 불가능한 방법임
//    int n = 120;
//    string str;
//    int cnt;
//    for(int i=1; i<=n; i++){
//        if(i >= 1 && i <= 9){
//            cnt += 1;
//        }else if(i >= 10 && i <= 99){
//            cnt += 10;
//        }else if(i >= 100 && i <= 999){
//            cnt += 100;
//        }
//    }
//    cout << cnt;
    
    
    return 0;
}
