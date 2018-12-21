//
//  2743(단어길이재기).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    
    // type 1 - 기본적인 문자열 길이 구하는 방법
    string str;
    cin >> str;
    cout << str.size();
//    
//    // type 2 - string,size,length를 사용못하고 고전적인 방법으로 구하는방법 (코딩테스트의 경우 제한이 걸려있을 수 있음)
//    int len = 0;
//    for (int i=0; str[i]; i++) {
//        len += 1;
//    }
//    
//    // type 3 - strlen의 시간복잡도는 O(N)이기 때문에, for문과 함께 쓰이면 O(N^2)의 복잡도가 나오게 됩니다.
//    for (int i=0; i<strlen(str); i++) {
//        // Do something
//    }
//    // type 3 의 해결방법 -  len의 변수에 strlen을 사용해서 미리 담아 놓으면 전체적인 시간복잡도는 O(N)을 유지 할 수 있습니다.
//    int len = strlen(s);
//    for (int i=0; i<len; i++) {
//        // Do something
//    }
//    
//    return 0;
    
}
