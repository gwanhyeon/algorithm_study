//
//  1406.cpp
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 4. 13..
//  Copyright © 2018년 kgh. All rights reserved.
//

//한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.
//
//이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.
//
//이 편집기가 지원하는 명령어는 다음과 같다.
//
//L    커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
//D    커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
//B    커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
//삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
//P $    $라는 문자를 커서 왼쪽에 추가함
//초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.
//
//입력
//첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 이 문자열은 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 N(1≤N≤500,000)이 주어진다. 셋째 줄부터 N개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.
//
//출력
//첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Template 를 사용한 print
template < typename T > void print( const stack<T>& stk )
{
    struct cheat : stack<T> {
        using stack<T>::c ;
    } ;
    const auto& seq = static_cast< const cheat& >(stk).c ;
    for( const auto& v : seq ){
        cout << v << ' ' ;
    }
    cout << '\n' ;
}
int main(void){
    // 반복 횟수
    int n;
    string str;
    // stack 에다가 char 형을 넣어서 처리할 수 있음. string 보단 char형으로 사용해야 하나씩 값비교 가능
    stack<char> left_s;
    stack<char> right_s;
    cin >> str;
    cin >> n;
    // init part
    
    for(int i=0; i<str.size(); i++){
        left_s.push(str[i]);
    }
    
    // 현재 스택에 있는값 출력하기
    
    //print(left_s);
    //print(right_s);

    // N번의 반복을 수행하기 위한 문장
    // left stack , right stack
    while(n--){
        char cmd;
        cin >> cmd;
        
        for(int i=0; i<str.size(); i++){
  
            // 커서를 왼쪽으로 옮기기 L
            if(cmd == 'L'){
                
                if(left_s.empty()){
                    continue;
                }else{
                // 오른쪽에 push(), 왼쪽 스택이 가지고 있던 커서 값
                right_s.push(left_s.top());
                // 그리고 왼쪽 스택에 있던 top 값 pop()
                left_s.pop();
               // print(left_s);
               // print(right_s);
                // 왜 이렇게 분리하냐? 커서값 기준으로 두 분류로 나누기 위해서
                }
            // 커서를 오른쪽으로 옮기기 D
            }else if(cmd == 'D'){
                if(right_s.empty()){
                    continue;
                }else{
                left_s.push(right_s.top());
                right_s.pop();
                }
            // 커서 왼쪽 문자 삭제 B
            }else if(cmd == 'B'){
                if(left_s.empty()){
                    continue;
                }else{
                // 실제이동하는값은 그대로다 왼쪽이 사라져도 오른쪽 값은 그대로라고 조건에 주어져있음.
                left_s.pop();
                }
            // 커서 왼쪽에 문자 추가 P $
            }else{
                char p_str;
                cin >> p_str;
                left_s.push(p_str);
            }
        }
    }
    
    
    print(left_s);
    print(right_s);
    
    
}

//
//    print(left_s);
//    print(right_s);



// Template
/*
#include <iostream>
#include <stack>

template < typename T > void print( const std::stack<T>& stk )
{
    struct cheat : std::stack<T> { using std::stack<T>::c ; } ;
    const auto& seq = static_cast< const cheat& >(stk).c ;
    
    for( const auto& v : seq ) std::cout << v << ' ' ;
    std::cout << '\n' ;
}
 */
