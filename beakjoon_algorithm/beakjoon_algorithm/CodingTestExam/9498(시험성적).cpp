//
//  9498(시험성적).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// 1억번까지 시간복잡도를 수행해야하고 메모리 제한 128M
// 1bit 0,1 컴퓨터 연산의 단위이다.
// 1byte = 8bit를 의미하며 01010302 식으로 표현할 수 있다.
// 1024KB = 1MB
// 1024 MB = 1GB

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int score;
    cin >> score;
    
    if(score >= 90 && score <= 100){
        cout << "A";
    }else if(score >= 80 && score < 90){
        cout << "B";
    }else if(score >= 70 && score < 80){
        cout << "C";
    }else if(score >= 60 && score < 70){
        cout << "D";
    }else{
        cout << "F";
    }
    
    
}
