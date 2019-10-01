//
//  1759 암호만들기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
 0. 정렬된 상태로 뽑아야한다. 일단 sort부터 조지자
 1. 일단 4개를 만들자
 2. 그리고 자,모 체크하자
 3. cnt값이 입력된값과 같다면 종료하자
 4. 재귀호출로 계속진행하자 현재 password = "" 이니까 여기에 알파벳을 하나씩 추가할꺼다, 추가하면서 CNT변수를 하나 놓아서 같이 진행한다.
 5. 이번의 경우에는 최종적으로 값을 만족하는경우가 있다면 바로 출력때려버리는거다 값을 담아도되긴한다.
 
 
 */






/*
1. 암호 L개의 소문자 최소 한개의 모음, 최소 두개의 자음로 구성 되어있음
2. 알파벳이 증가되는 순서로 배열 -> 정렬해야되는구나 abc OK bac X
3. 문자 종류 C가지의 문자중에서 L개를 선택해서 암호의 방법의 문자열을 모두 구하는 문제
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
void recursive(string password,vector<char> &v, int cnt){

    // 불가능한 경우
  
    // 가능한 경우
    if(password.size() == n){
        int ja = 0;
        int mo = 0;
        for(int i=0; i<password.size(); i++){
            if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u'){
                mo +=1;
            }else {
                ja +=1;
            }
        }
        if(mo >= 1 && ja >= 2){
            cout << password << '\n';
        }
        return;
    }
    if(v.size() == cnt){
        return;
    }
    
    
    
    // i번째 알파벳을 사용하는 경우
    recursive(password+v[cnt], v, cnt+1);
    // i번째 알파벳을 사용하지 않는 경우
    recursive(password, v , cnt+1);
    
    
}


int main(void){
    
    cin >> n >> m;
    vector<char> v(m);
    
    for(int i=0; i<m; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    recursive("",v,0);
    return 0;
}























