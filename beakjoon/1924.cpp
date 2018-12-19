// comment : Success


//  1924.cpp
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 4. 9..
//  Copyright © 2018년 kgh. All rights reserved.
//


//문제
//오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.
//
//출력
//첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int month[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int x =0;
    int y =0;
    int result = 0;

    
    
    // month, day input line
    
    //cout << "you select given the number!" << endl;
    scanf("%d %d",&x,&y);
    cin >> x >> y;
    for(int i=0; i<x - 1; i++){
        result += month[i];
        
    }
    result = result + y;
    //cout << result << endl;
    //cout << result + y << endl;
    //result = result + y;
    
    // x달 까지의 총 일수 더하기
     //cout << "result : " << result << endl;
    result = (result % 7);
    //cout << result;
    //cout << "result : " << result << endl;
    
    
    switch(result){
            
        case 0:
            cout << "SUN";
            
            break;
        case 1:
            cout << "MON";
            
            break;
        case 2:
            cout << "TUE";
            
            break;
        case 3:
            cout << "WED";
            
            break;
        case 4:
            cout << "THU";
            
            break;
        case 5:
            cout << "FRI";
            
            break;
        case 6:
            cout << "SAT";
            break;
    }
    
}

