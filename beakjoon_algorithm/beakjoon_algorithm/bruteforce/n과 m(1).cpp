//
//  n과m(1).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 15/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
 자연수 N과 M 주어졌을때 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 
 */
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int arr[10];
int check[10];
void recursive(int index,int n,int m){
    
    // index 값과 m이 같으면 종료 모두 순회하였으므로,
    if(index == m){
        for(int i=0; i<m; i++){
            cout << arr[i];
            if(i != m-1){
                cout << ' ';
            }
            
        }
        cout <<'\n';
        return;
    }
    // 1 <= N <= 8 까지의 범위이므로 for문 i=1부터 시작해서 n개 까지
    // n은 숫자의 범위를 나타내고 있으므로, m이 아니라 n까지 비교해주어야함. 모든 수를 비교해야하므로
    for(int i=1; i<=n; i++){
        
        // 중복 제거
        if(check[i]){
            continue;
        }
        // 사용하였으니까
        check[i] = true;
        // arr에는 정답을 저장한다.
        arr[index] = i;
        recursive(index+1,n,m);
        check[i] = false;
        // 예를 들어 1에 대한 값들에 대해 정답을 다 저장하고 recursive로 처리하였으므로
        // 다시 1을 사용하기 위하여 false로 바꾸어준다.
    }
    
}

int main(void){
    
    int n,m;
    cin >> n >> m;
    
    recursive(0,n,m);
    return 0;
}
