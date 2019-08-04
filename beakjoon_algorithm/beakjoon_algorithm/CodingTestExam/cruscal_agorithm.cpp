//
//  union_find.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
// 맞는 문제인데 에러나는 거임 !!!! 컴파일 에러가 나옴...


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 여기부분은 크루스칼 알고리즘에서 사용되는것들은 그대로 둘것임 union-find algorithm


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
// 간선 정보를 담는 간선 클래스 선언

class Edge{
public:
    int node[2];  // 노드 정보
    int distance; // 비용 정보
    Edge(int a,int b, int distance){
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge){
        return this->distance < edge.distance;
    }
    
};

int main(void){
    int n = 7; // 정점개수
    int m = 11; // 간선 개수
    
    vector<Edge> v;
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,4,28));
    v.push_back(Edge(1,2,67));
    v.push_back(Edge(1,5,17));
    v.push_back(Edge(2,4,24));
    v.push_back(Edge(2,5,62));
    v.push_back(Edge(3,5,20));
    v.push_back(Edge(3,6,37));
    v.push_back(Edge(4,7,13));
    v.push_back(Edge(5,6,45));
    v.push_back(Edge(5,7,73));
    // 간선의 비용을 기준으로 오름차순 정렬
    sort(v.begin(),v.end());
    
    // 각 정점이 포함된 그래프가 어디인지 저장
    
    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    int sum =0;
    for(int i=0; i<v.size(); i++){
        // 사이클이 발생하지 않는 경우 그래프에 포함시켜준다.
        if(!findParent(parent,v[i].node[0] -1,v[i].node[1] -1)){
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] -1, v[i].node[1] -1);
            
        }
    }
    printf("%d\n",sum);
}
