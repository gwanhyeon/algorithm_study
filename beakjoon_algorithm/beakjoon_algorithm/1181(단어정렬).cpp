//
//  1181(단어정렬).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
//시간 제한    메모리 제한    제출    정답    맞은 사람    정답 비율
//2 초    256 MB    18347    6594    4708    36.995%
//문제
//알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
//
//길이가 짧은 것부터
//길이가 같으면 사전 순으로
//입력
//첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
//
//출력
//조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
//
//예제 입력 1
//13
//but
//i
//wont
//hesitate
//no
//more
//no
//more
//it
//cannot
//wait
//im
//yours
//예제 출력 1
//i
//im
//it
//no
//but
//more
//wait
//wont
//yours
//cannot
//hesitate
//출처
//문제를 만든 사람: author5
//알고리즘 분류
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool compare(string a,string b){
    
    if(a.length() < b.length()){
        return 1;
    }else if(a.length() > b.length()){
        return 0;
    }else {
        return a < b; //자동으로 사전순으로 해준다.
    }
    
}
int main(void){
    int n = 0;
    string str[20000];
    cin >> n;
    // n의 개수만큼 문자열 입력
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    // 정렬해서 비교 해주고
    sort(str,str+n,compare);
    
    // string 중복 처리
    for(int i=0; i<n; i++){
        if(str[i] == str[i-1] && i > 0 ){
            continue;
        }else{
            cout << str[i] << endl;
        }
        
    }
    return 0;    
}
