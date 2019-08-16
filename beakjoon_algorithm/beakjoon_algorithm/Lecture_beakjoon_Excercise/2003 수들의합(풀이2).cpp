//
//  2003 수들의합(풀이2).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int left = 0;
    int right = 0;
    int sum = v[0];
    int ans =0;
    while(left <= right && right < n){
        // 더 진행 조건
        if(sum < m){
            right +=1;
            sum += v[right];
        } // 결과값 증가 조건
        else if(sum == m){
            ans +=1;
            right += 1;
            sum += v[right];
        }else if(sum > m){ // 종료 조건
            sum -= v[left];
            left +=1;
            // R 이자리에서 멈추고 대기
            // L 실행
            if(left > right && left < n){
                right = left;
                sum = v[left];
            }
        }
    }
    cout << ans;
    
    
    return 0;
}
