//
//  Level1-2016년.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string>
using namespace std;

int main(void){
    int a = 5;
    int b = 24;
    // 30일 46911 31일 135781012 29일 2
    string answer = "";
    int total=0;
    int dayInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    string weeks[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    for (int i = 0; i < a-1; i++)
    {
        total += dayInMonth[i];
    }
    total += b-1;
    answer += weeks[total % 7];
    
    cout << answer;
    return 0;
}
