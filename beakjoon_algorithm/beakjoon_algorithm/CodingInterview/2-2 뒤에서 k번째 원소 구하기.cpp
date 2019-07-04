//
//  2-2 뒤에서 k번째 원소 구하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

void insert_node(NODE* head, int data){
    
    NODE* curr = (NODE*)malloc(sizeof(node));
    curr->data = data;
    curr->next = head->next;
    head->next = curr;
}
void print_node(NODE* head){

    NODE* curr = head->next;
    while(curr != NULL){
        cout << curr->data;
        curr = curr->next;
    }
}
NODE* search_node(NODE* head, int k, int& i){
/* # 풀이 2번 C++의 참조를 통한 값 전달 Recursive */
    if(head == NULL){
        return 0;
    }

    NODE* curr = search_node(head->next,k,i);
    i=i+1;
    //k번째에 해당하는 원소를 찾았을 경우
    if(i == k){
        cout << head->data;
        return head;
    }
    return curr;

}
NODE* search_node(NODE* head, int k){
    int i=0;
    return search_node(head,k,i);
}


/* # 풀이 1번 가장 기본적인 순회 방법 - 비재귀 문제 */
//void search_node(NODE* head, int k){
//      if(head != NULL){
//          return 0;
//      }
//    NODE* curr = head->next;
//    int cnt = 1;
//
//    while(curr != NULL){
//        if(k == cnt){
//            cout << curr->data;
//        }
//        curr = curr->next;
//        cnt++;
//    }
//}

int main(void){
    NODE* head = (NODE*)malloc(sizeof(node));
    head->next = NULL;
    
    insert_node(head,10);
    insert_node(head,20);
    insert_node(head,30);
    print_node(head);
    search_node(head,2);

    return 0;
}
