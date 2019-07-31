//
//  2-4 STL 분할 값.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>

typedef struct NODE{
    int data,
    struct NODE* next;
}node;

node *head = NULL;
node *tail = NULL;
linked_list() {
    head = NULL;
    tail = NULL;
}

node* add_node(int n) {
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
    
    return temp;
}

void addFirst(int x) {
    node *temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
    if (tail == NULL) tail = temp;
}

void addFirst(node *node) {
    node->next = head;
    head = node;
    if (tail == NULL) tail = node;
}

int removeFirst() {
    int data = head->data;
    head = head->next;
    return data;
}

node* first() {
    return head;
}


void printLinkedList() {
    if (head == NULL) return;
    
    node* currentNode = head;
    while (currentNode->next != NULL) {
        printf("%d - ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("%d", currentNode->data);
    
    printf("\n");
}

int main(void){
    
    return 0;
    
}

