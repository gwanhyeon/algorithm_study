//
//  1062 가르침.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 16/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

int learn[100];

using namespace std;
// index 알파벳 번호 k = 배운 단어 개수, 현재 단어
int count(int mask, vector<int> &words){
    int cnt = 0;
    for(int word : words){
        // word는 어떤 단어가 어떤 단어로만 이루어져있는지 저장되어있음, mask 내가 배운 알파벳
        // word에서 1 인것이 mask도 1이 되어야한다.
        // 가장 좋은 방법은 각각의 알파벳마다 비트연산을 수행해야한다.
        // word에 내가 배우지 않은 알파벳이 없다(모두 배웠다는말임)
        if((word & ((1<<26)-1-mask)) == 0){
            cnt += 1;
        }
        // 1 26개를 만들기 위한 비트연산을 수행하기 위해서 위에 식 처럼 처리하였다.
        
    }
    return cnt;
}
int go(int index, int k,int mask, vector<int> &words){
    // 음수가 될 경우 조건 처리해서 종료한다.
    if(k < 0){
        return 0;
    }
    // 총 26개 단어를 모두 돌았을 경우 count로 해당 단어를 가져온다.
    if(index == 26){
        return count(mask,words);
    }
    int ans = 0;
    
    //    learn[index] = true;
    //bitmask 값을 추가한다.
    int t1 = go(index+1, k-1,mask | (1 << index), words);
    //    learn[index] = false;
    
    // t1 값이 더 크면 변경
    if(ans < t1){
        ans = t1;
    }
    // 아직 배우지 않은경우면 그 값을 학습시킨다.
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        t1 = go(index+1,k,mask,words);
        if(ans < t1){
            ans = t1;
        }
    }
    return ans;
}
int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> words(n);
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(char x : s){
            words[i]|=(1<<(x-'a'));
        }
    }
    cout << go(0,k,0,words) << '\n';
    
    return 0;
}
