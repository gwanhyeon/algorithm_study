//
//  실수자료형.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// 3 = 2^1 + 2^0

// 실수의 자료형의 float 32bit의 구조는 sign(1bit)-음수 양수 저장 필드 / exponent(8bit) 과학적 표기법에서 지수승을 저장하는 필드/ fraction(23bit) 유효 숫자 부분 저장
// double 자료형은 64bit sign(1bit) / exponent(11bit) / fraction filed(52bit)

// 예 )
// -6.75 => -1.1011(2) * 2^2 => 1 = sign, 10000001 = exponent 지수승이 2이므로 127에 더한 129를 8bit 공간에 기록하고 , 110111 = fraction filed로 나타 낼 수 있다.
// IEEE 754 format 검색을 해서 자료를 찾을 수 있을것이다.
// 실수 저장/연산 과정에서는 반드시 오차파 발생 할 수 밖에 없다. 실수를 비교할때는 등호를 사용하면 안된다.
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;


// 지역변수는 0으로 초기화 되지 않지만, 전역변수는 0으로 초기화되므로
//코딩시에 전역변수를 선언하여 코딩하면 시간을 낭비하지 않을 수 있음.단, 실무에서는 절대 하면 안된다.

// cd /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 경로에 bits/stdc++.h 설정
#include <bits/stdc++.h>
using namespace std;

int main(void){
    cout << "hello world!";
    return 0;
}
