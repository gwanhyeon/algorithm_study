//
//  2.cpp
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

typedef struct LIST{
    node *head;
    node *tail;
    node *cur;
    int num;
}List;

void insertNode(LIST* llist,int data){
    // 새로운 노드 생성
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(llist->head == NULL && llist->tail == NULL){
        llist->head = newNode;
        llist->tail = newNode;
    }else{
        llist->tail->next = newNode;
        llist->tail= newNode;
    }
}
void deleteNode(LIST* llist){
    node *p = llist->head;
    // 마지막지점까지 이동한다음
    while(p->next->next != NULL){
        p = p->next;
    }
    // 그점에 있는 지점에서 그전 테일까지 이동하여 p값을 list값으로 이용한다.
    p->next = p->next->next;
    llist->tail = p;
}
void printNodes(LIST* llist){
    node *curr = llist->head;
    
    while(curr != NULL){
        cout << curr->data;
         curr = curr->next;
    }
    
}
/* 일단 보류 */
LIST* partition(LIST* node, int x){
    LIST* head = node;
    LIST* tail = node;
    
    while((node != NULL)){
        LIST* next = node->next;
    }
    
}
int main(void){
    LIST* llist = (List*)malloc(sizeof(List));
    llist->cur = NULL;
    llist->head = NULL;
    llist->tail = NULL;
    
    insertNode(llist,3);
    insertNode(llist,5);
    insertNode(llist,8);
    insertNode(llist,5);
    insertNode(llist,10);
    insertNode(llist,2);
    insertNode(llist,1);
    llist = partition(llist,5);
    printNodes(llist);
    
    
    
    
    

}
