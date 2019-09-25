//
//  10971 외원판순회 2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
1) TEST CASE 1,2,3,4 를 따로 vector에 담아 처리
2) Next_permutation 처리 후 현재 값 , 현재값 + 1 의 값이 == 0인지 체크 -> 0이라면 가중치가 0이면 종료한다.
 가중치 값이 0이라함은 v[i][i]값을 제외하곤 없기떄문에 올바른 그래프로 이루어진게아니다.

 그게 아니라면, n-1번쨰 까지 i, i+1값의 가중치를 더해간다.
 
3) 가중치값이 0인게 없고, 가중치값이 있으면
    012 120 201
 
 1,2의 과정은 순열로서 과정을 이룬것이므로 다시 자기자신의 경로로 돌아와야하므로 마지막점에서 -> 처음점에 이어진 가중치를 더해주어야한다.
 n-1 -> 0으로 이동해서 처음의 값의 가중치를 더해주어야하므로, 추가시켜줘야한다.
 
 
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10][10];
int main(void){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        v[i] = i;
    }
    
    int ans = 210000000;
    
    do{
        bool check = true;
        int sum = 0;
        // 1 2 3
        for(int i=0; i<n-1; i++){
            if(arr[v[i]][v[i+1]] == 0){
                check = false;
            }else {
                sum += arr[v[i]][v[i+1]];
            }
        }
        // 다시 되돌아 오는경우 자기 자신으로 1 2 3 1 로 돌아오는경우다 예를들면
        
        if(check && arr[v[n-1]][v[0]] != 0){
            sum += arr[v[n-1]][v[0]];
            if(ans > sum){
                ans = sum;
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << '\n';
}
