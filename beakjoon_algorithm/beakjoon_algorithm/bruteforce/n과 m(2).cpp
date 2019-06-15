//
//  n과 m(2).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
 1~N 자연수중에서 중복 없이 M개를 고른 수열
 고른 수열은 오름차순이여야함
 사전순으로 증가하는 순서로 출력해야함
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int arr[10];
bool check[10];
void recursive(int index,int start,int n, int m){
    
    // m개 만큼 선택이 되었을 경우
    if(index == m){
        for(int i=0; i<m; i++){
            cout << arr[i];
            if(i != m-1){
                cout << ' ';
            }
            
        }
        cout << '\n';
    }
    // 1 ~ N 까지의 수를 반복문 돌린다.
    for(int i=start; i<=n; i++){
        if(check[i]){
            continue;
        }

        check[index] = true;
        arr[index] = i;
        // 여기부분이 중요하다 i+1만큼 기준점을 바꿔주어야한다. 중복이 없어야하고, 오름차순으로 조져야하기때문에
        // 2 1 3 4 같은 반례를 생각해야한다. 성립하지 않는다.
        recursive(index+1,i+1,n,m);
        check[index] = false;
    }
}
int main(void){
    int n,m;
    
    cin >> n >> m;
    recursive(0,1,n,m);
    return 0;
}
