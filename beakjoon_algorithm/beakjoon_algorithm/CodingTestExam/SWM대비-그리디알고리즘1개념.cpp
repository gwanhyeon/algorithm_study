//
//  SWM대비-그리디알고리즘.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
//  그리디 알고리즘의 대표적인 예제는 거스름 돈 문제입니다. 우리가 흔히 거스름 돈을 줄 때 가장 적은 양의 화폐를 주는 것이 제일 편합니다. 예를 들어 560원을 걸러주어야 할 때 10원짜리 56개를 주는 것보다 500원짜리 1개, 50원짜리 1개, 10원짜리 1개를 주는 것이 총 3개로 더 편합니다. 따라서 이런 경우 '무조건 더 큰 화폐 단위부터 거슬러 준다'는 알고리즘만 지키면 최적의 해를 보장할 수 있습니다.

//** 핵심: 정렬과 함께 쓰인다 / 무조건 더 큰 화폐 단위부터 거슬러 준다 -> 최적의 해를 구할 수 있음. / 동전 거스르는 문제

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int money = 0; // 입력 받기 위한 자금 변수
    int result = 0; // 동전의 개수를 저장하기 위한 변수
    cin >> money; // 돈 입력
    
    // 1.1260원을 거슬러줘야 할 경우 -> 500원 2개
    
    result += (money / 500);
    money %= 500;
    
    // 2.260원을 거슬러줘야 할 경우 -> 100원 2개
    result += (money / 100);
    money %= 100;
    
    // 3. 60원을 거슬러 주어야 할 경우 -> 50원 1개
    result += (money / 50);
    money %= 50;

    // 4. 10원을 거슬러 주어야 할 경우 -> 10원 1개
    result += (money / 10);
    
    cout << result;
    
    
    return 0;
}
