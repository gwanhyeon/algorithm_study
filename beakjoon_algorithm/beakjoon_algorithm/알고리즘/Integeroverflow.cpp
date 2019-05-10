//
//  Integeroverflow.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// Integer overflow란 무엇인가?
// 예를 들어보자, char형의 자료형의 수를 더할경우를 생각해보자
// 127 + 1 의 경우는 과연 어떻게 더할 수 있을까? 대부분의 경우에는
// 127 + 1 => 128이라고 생각하기 쉽상이다.
// 컴퓨터는 멍청해서 2진수 연산을 진행한다.
// 01111111 + 00000001 로 연산을 수행한다. 이렇게 된다면 -2^7 = - 128 이 나오게된다.
// 바로 Integer overflow가 발생하게 된 것이다.

#include <stdio.h>
#include <iostream>
using namespace std;
// 다음 3가지 함수중에 Integer overflow가 발생하는 경우는 어떤경우인가?


// char 자료형의 경우 127 + 1 이 더해지면 -128이 되므로 의도한대로 동작하지 않고
// 무한 루프행 => 해결방법 : char타입의 자료형을 int로 변경
void func1(){
    for(char s=0; s<128; s++){
        cout << s;
    }
    for(int i=0; i<128; i++){
        cout << i;
    }
    
}
// 정상
int func2() {
    int r = 1;
    for(int i=1; i<= 50; i++){
        r = r * i % 61;
    }
    return r;
}
// int 자료형의 경우 10^9에서 10이 곱해지면 integer overflow
// 1000000000 10억 * 10 이 되면
// int 자료형은 약 21억이므로 범위를 벗어나게 되므로 Integer overflow event!
// => 이것들을 어떻게 고칠 수 있을까?
// long long 타입으로 변경해준다면 가능해진다.
// 이것보다 큰 수를 연산해야 될 경우 GCC의 __int128 자료형을 이용하거나 직접 큰수의 연산 클래스를 만들어야한다.

int func3() {
    int a = 10;
    int mod = 1e9+7;
    for(int i=0; i<10; i++){
        a = 10 * a % mod;
    }
    return a;
    
}


int main(void){
    func1();
    func2();
    func3();
    
    
    return 0;
}
