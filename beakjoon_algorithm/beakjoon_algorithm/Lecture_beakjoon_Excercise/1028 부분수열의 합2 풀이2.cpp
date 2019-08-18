//
//  1028 부분수열의합2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int m = n/2;
    n = n-m;
    vector<int> first(1<<n);
    vector<int> second(1<<m);
    
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                first[i] += v[j];
            }
        }
    }
    
    for(int i=0; i<(1<<m); i++){
        for(int j=0; j<m; j++){
            if(i & (1<<j)){
                second[i] += v[j+n];
            }
        }
    }
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    reverse(second.begin(), second.end());
    
    n = (1<<n);
    m = (1<<m);
    int x=0;
    int y=0;
    long long ans = 0;
    
    while(x < n && y < m){
        if(first[x] + second[y] == s){
            long long c1 = 1;
            long long c2 = 1;
            x +=1;
            y +=1;
            
            while(x <n && first[x] == first[x-1]){
                c1 += 1;
                x += 1;
            }
            while(y < m && second[y] == second[y-1]){
                c2 +=1;
                y +=1;
            }
            ans += c1 * c2;
        }else if(first[x] + second[y] < s){
            x += 1;
        }else {
            y += 1;
            
        }
    }
    //공집합 빼기
    if(s == 0) {
        ans -= 1;
    }
    cout << ans << '\n';

    
    
//    int n,s;
//    vector<int> arr;
//    cin >> n >> s;
//
//    for(int i=0; i<n; i++){
//        int num;
//        cin >> num;
//        arr.push_back(num);
//
//    }
//
//    int left = 0;
//    int right = n-1;
//    long long sum = (arr[0] + arr[n-1]);
//    int cnt = 0;
//
//
//    while(left >= 0 && right < n && left < n && right >= 0){
//        // sum > s 값이 넘어 가는 경우
//        if(sum < s){
//            left += 1;
//            sum += arr[left];
//        }
//        else if(sum > s){
//            sum += arr[right];
//            right -=1;
//        }else if(sum == s){
////            sum += arr[right];
//            right -=1;
//            left +=1;
//            cnt++;
//        }
//    }
//    cout << cnt << '\n';
    return 0;
    
}
