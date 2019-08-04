//
//  10824(네수).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    
    // a,b,c,d 변수 선언 여기서 중요한것 ! 문제에서 1,000,000 까지의 수를 입력이 가능하다고 하였다.
    // 최대 입력범위를 생각하였을때 a(1,000,000),b(1,000,000) + c(1,000,000),d(1,000,000) 이므로 최대 4,000,000,000,000까지의 범위를 갖는다.
    // 기존의 int범위를 생각했을때 약 21억 정도이므로, int자료형으로 값을 저장해서 출력해버리면 오버플로우가 발생하므로 long long 자료형을 써야겠다고 생각을 함.
    
    int a,b,c,d =0;
    string result1, result2;
    // 값 입력
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    // integer to String 변환
    result1 = to_string(a) + to_string(b);
    result2 = to_string(c) + to_string(d);
    
    // long long은 8바이트의 공간을 가지는 자료형이기에 signed long long을 기준으로 하면 최대 계산할 수 있는 양의 정수 범위는 0 ~ 9,223,372,036,854,775,807(16진수로 7FFFFFFFFFFFFFFF)가 되어 범위가 큰 문제를 해결 할 수 있게되었다.
    long long A = stoll(result1);
    long long B = stoll(result2);

    cout << A + B << endl;

    return 0;
}
