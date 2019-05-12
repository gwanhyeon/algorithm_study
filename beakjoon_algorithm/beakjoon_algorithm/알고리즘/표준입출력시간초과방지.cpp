//
//  표준입출력시간초과방지.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


// printf, scanf를 제외한 나머지 값은 괜찮으나, cin cout을 사용할때 주의 할점이있다.
// => 주의할 점은 시간초과 방지를 위해서 다음 아래와 같은 코드를 사용해야한다.
// ios::sync_with_stdio(0);
// cin.tie(0);
#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    sync => ?
    sync =>
    // sync
    sync => ios:sync_with_stdio(0);
    
    // c -> c++ print -> cout
//    printf("%d",num);
//    cout << num << '\n';
//    printf("%d",num);
//    cout << num << '\n';
    
    ios::sync_with_stdio(0);    // c++, c stream사이의 sync를 끄는 역할을 한다.
    //cin.tie(0); cin과 cout이 번갈아 나올때 마다 flush 를 하지 않도록 하는 명령어 이다.
    // => 왜 cout에서 endl를 사용하지 않고 "\n" 를 사용할까?
    // endl 라는것은 줄바꿈이후에 flush를 처리하라는 의미를 가지고 있다.
    // printf,scanf와 cout,cin을 함께 사용하면 sync를 유지 시키는데,
    // sync를 유지시킨다는것은 c,c++문법의 순서의 sync를 순서대로 처리한다고 생각하면 된다.
    // cout,cin만을 사용하면 sync가 필요없기때문에 불필요한 시간을 낭비하게 된다.
    // 다음 예제로 살펴보자.
    printf("1\n");
    cout << "2\n";
    printf("3\n");
    cout << "4\n";
    // => 출력 결과 1, 2, 3, 4
    
    
    
    
    
    
    
    return 0;
}
