//
//  11656(접미사배열).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    
    string str;
    string result[1000];
    cin >> str;
    // substr을 사용하여 하나씩 늘려가면서 접미사 저장
    for(int i=0; i<str.size(); i++){
        result[i] = str.substr(i,str.size());
    }
    // #include <algorithm>, sort()함수의 첫번째 파라미터 = 시작점 포인터지점(주소) , 두번째 파라미터 = 도착지 포인터지점(주소)+문자열개수(str.size)
    sort(result,result+str.size());
    
    // 저장된 접미사값 sort된값을 사용하여 정렬
    for(int i=0; i<str.size(); i++){
        cout << result[i] << endl;
    }
    
}
