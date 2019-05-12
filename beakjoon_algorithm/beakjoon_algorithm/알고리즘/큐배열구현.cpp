//
//  큐배열구현.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


// head는 맨앞에 인덱스에 위치 해있고 head
// tail 맨마지막 데이터 뒤 tail + 1을 가지고 있음(stack의 pos와 동일)
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MX = 1000007;
int dat[MX];
int head,tail;

void push(int val){
    dat[tail] = val;
    tail++;
//    dat[tail++] = val; 한줄로 표현 가능!
}
void pop(){
    if(head != 0){
    head++;
    }
}
int front() {
    return dat[head];
}
int back(){
    return dat[tail-1];
}
int main(void){
    push(5);
    push(4);
    pop();
    
   
    return 0;
}
