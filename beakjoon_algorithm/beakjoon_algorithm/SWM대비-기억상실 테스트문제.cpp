//
//  기억상실(소마).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
//민규는 가벼운 기억상실증을 앓고 있습니다. 오늘 무엇인가를 외우면 잠을 자면서 일부를 잊는 증세를 보입니다. 영어시험을 준비하는 민규는 단어 N개를 모두 외워야 합니다. 민규는 하루에 A개의 단어를 외울 수 있습니다. 하지만, 밤에 잠을 자면서 B개를 까먹습니다. N개를 모두 외우는 날에 민규는 목적을 달성합니다.
//
//또한 모두 외우는 날에는 밤에 단어를 까먹는 것을 생각하지 않고 N개의 단어를 모두 외웠다고 간주합니다. 민규가 외워야 하는 N개의 단어가 주어졌을 때, 단어를 모두 외우려면 며칠이 걸리는지 구하는 프로그램을 작성하세요.
//
//입력값 설명
//
//첫째 줄에 세 정수 A, B, N이 공백으로 구분되어서 주어집니다. (1 ≤ B < A ≤ N ≤ 1,000,000,000)
//
//출력값 설명
//
//첫째 줄에 민규가 N개의 단어를 모두 외우는데 며칠이 걸리는지 출력합니다.
//
//
//입력 예시1
//
//2 1 5
//
//출력 예시1
//
//4
//입력 예시2
//
//3 2 6
//
//출력 예시2
//
//4

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int A,B,N;
    // 하루에외우는것 까먹는것 총
    int cnt=0;
    cin >> A >> B >> C;
    while(cnt != N){
    cnt += (A - B)
        
    }
    
    
    
    
}




#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int A,B,N;
    int sum = 0;
    cin >> A >> B >> N;
    
    for(int i=1; i<= N; i++){
        if(sum == N){
            break;
        }else {
            sum += A;
            sum -= B;
        }
    }
    cout << sum - B << endl;
}

