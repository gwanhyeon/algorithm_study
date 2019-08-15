//
//  1062 가르침(비트마스크).cpp
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
int count(vector<string> &words){
    int cnt = 0;
    for(string word: words){
        bool ok = true;
        for(char x: word){
            if(!learn[x-'a']){
                ok = false;
                break;
            }
        }
        if(ok){
            cnt += 1;
        }
    }
    return cnt;
}
int go(int index, int k, vector<string> &words){
    // 음수가 될 경우 조건 처리해서 종료한다.
    if(k < 0){
        return 0;
    }
    // 총 26개 단어를 모두 돌았을 경우 count로 해당 단어를 가져온다.
    if(index == 26){
        return count(words);
    }
    int ans = 0;
    
    learn[index] = true;
    int t1 = go(index+1, k-1, words);
    learn[index] = false;
    
    // t1 값이 더 크면 변경
    if(ans < t1){
        ans = t1;
    }
    // 아직 배우지 않은경우면 그 값을 학습시킨다.
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        t1 = go(index+1,k,words);
        if(ans < t1){
            ans = t1;
        }
    }
    return ans;
}
int main(void){
    int n,k;
    cin >> n >> k;
    
    vector<string> words;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        words.push_back(str);
        str.clear();
    }
    cout << go(0,k,words) << '\n';
    
    return 0;
}
