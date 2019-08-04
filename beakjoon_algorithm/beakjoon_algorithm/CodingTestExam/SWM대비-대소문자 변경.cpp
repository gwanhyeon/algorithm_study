//
//  SWM대비-대소문자 변경.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(void){
    string str ="Hello World";
    //*** 전체 String 변환하기 transform , :: toupper , :: tolower , 콜로니 써먹는거 잊지말것 !!
    transform(str.begin(),str.end(),str.begin(),::toupper);
    
    for(int i=0; i<str.size(); i++){
        cout << str[i];
    }
    
    transform(str.begin(),str.end(),str.begin(),::tolower);
    
    for(int i=0; i<str.size(); i++){
        cout << str[i];
    }
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] -'A' + 'a';
        }else if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] -'a' + 'A';
        }
    }
    
    for(int i=0; i<str.size(); i++){
        cout << str[i];
    }
    
    
    return 0;
}





























//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main(void){
//    string str="Hello";
//
//
//    transform(str.begin(), str.end(),str.begin(),::toupper);
//    transform(str.begin(), str.end(),str.begin(),::tolower);
//
//    // **** 대문자 소문자 바꾸는 정석
//    for(int i=0; i<str.size(); i++){
//        // 소문자 일경우 -> 'a' 를 빼주고 + 'A'를 더해준다.
//        if(str[i] >= 'a' && str[i] <='z'){
//            str[i] = str[i] -'a'+'A';
//
//        // 대문자 일경우 -> 'A' 를 빼주고 + 'a'를 더해준다.
//        }else if(str[i] >='A' && str[i] <='Z'){
//            str[i] = str[i] -'A'+'a';
//        }
//    }
//
//    cout << str;
//
//    return 0;
//}
//
