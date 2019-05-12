//
//  스택배열구현.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000007;
int dat[MX];
int pos;
// 스택을 배열처럼 구현하기 위해서는
// {10,20,30,}
//   0  1  2  pos 처럼 3번째 인덱스에 포지션이 위치해있음을 기억해야한다.

void push(int val){
    dat[pos] = val;
    pos++;
    // dat[pos++] = val; 이렇게 한줄로 표현 할 수 도있음.
}
void pop(){
    if(pos != 0){
        pos--; // pos만 --해주는 이유는 값을 삭제하지 않아도 참조가
    }
    
}
int top(){
    if(pos != 0){
    return dat[pos-1]; // pos-1 만큼을 확인하면 top을 확인 할 수 있다.
    }else{
        return 0;
    }
    
}
int main(void){
    push(5);       // {5}
    push(4);       // {5 4}
    pop();          // {5}
    
    for(int i=0; i<pos; i++){
        cout << dat[i];
    }
    
    
}
