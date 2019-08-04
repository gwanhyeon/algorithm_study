//
//  union_find.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>

// 최종 부모를 찾아오는 함수
int getParent(int parent[], int x){
    // 재귀함수의 종료부분
    if(parent[x] == x)
        return x;
    return parent[x] = getParent(parent,parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    // 부모가 더 작은값으로 값을 변경해준다.
    if(a<b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}

// 같은 부모를 가지는지 확인 한다
int findParent(int parent[], int a,int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    
    if(a==b) return 1;
    return 0;
}

int main(void){
    int parent[11];
    // 노드는 1부터 시작하므로
    for(int i=1; i<=10; i++){
        parent[i] = i;
    }
    
    unionParent(parent,1,2);
    unionParent(parent,2,3);
    unionParent(parent,3,4);
    unionParent(parent,5,6);
    unionParent(parent,6,7);
    unionParent(parent,7,8);
    printf("1 - 5 연결 ? %d\n", findParent(parent,1,5));
    unionParent(parent,1,5);
    printf("1 - 5 연결 ? %d\n", findParent(parent,1,5));
    
    
}
