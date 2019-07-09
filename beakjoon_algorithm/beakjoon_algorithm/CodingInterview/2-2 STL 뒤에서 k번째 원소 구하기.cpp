//
//  2-2 STL 뒤에서 k번째 원소 구하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
/*
 뒤에서 k번째 원소를 구하기: 단방향 연결리스트가 주어졌을때 뒤에서 k번째 원소를 찾는 알고리즘을 구현하라.
 */
#include <stdio.h>
#include <iostream>
#include <forward_list>
using namespace std;
bool single_digit (const int& value) { return (value<10); }
int main(void){
    forward_list<int> f_list;
    auto iter = f_list.before_begin();
    
    int n = 5;
    for(int i=0; i<n; i++){
        iter = f_list.insert_after(iter,i);
    }
    

    int cnt = 0;
    int k=0;
    
    for(iter = f_list.begin(); iter != f_list.end(); iter++){

    }
    
    
    
    
    return 0;
}

