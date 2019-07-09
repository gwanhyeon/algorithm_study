//
//  DoubleLinkedList.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct listNode{
    int data;
    struct listNode* Next;
    struct listNode* Prev;
    
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->Next = NULL;
    newNode->Prev = NULL;
    return newNode;
}

void deleteNode(Node* Node){
    free(Node);
}
Node* getNodeAt(Node* head,int index){
    Node* horse = head;
    int count = 0;
    
    while(horse != NULL){
        if(count++ == index){
            return horse;
        }
        horse = horse->Next;
    }
    return NULL;
}
int countNode(Node* head){
    int count = 0;
    Node* horse = head;
    
    while(horse != NULL){
        horse = horse->Next;
        count++;
    }
    return count;
    
}

void addNode(Node** head, Node* newNode){
    if((*head) == NULL){
        *head = newNode;
    }else{
        Node* horse = (*head);
        
        while(horse->Next != NULL){
            horse = horse->Next;
        }
        horse->Next = newNode;
        newNode->Prev = horse;
    }
}
void insertNode(Node* Current,Node* newNode){
    //head
    if(Current->Prev == NULL && Current->Next == NULL){
        Current->Next = newNode;
        newNode->Prev = Current;
    }
    // not head
    if(Current->Next == NULL){
        Current->Next = newNode;
        newNode->Prev = Current;
        
    }
    else{
        Current->Next->Prev = newNode;
        newNode->Prev = Current;
        newNode->Next = Current->Next;
        Current->Next = newNode;
    }
    
}

void removeNode(Node** head, Node* remove){
    // head
    if(*head == remove){
        *head = remove->Next;
    }
    
    if(remove->Next != NULL){
        remove->Next->Prev = remove->Prev;
    }
    
    if(remove->Prev != NULL){
        remove->Prev->Next = remove->Next;
    }
    deleteNode(remove);
    
}

int main(void){
    
    int count=0;
    
    Node* List = NULL;
    
    Node* newNode = NULL;
    
    Node* Curr = NULL;
    for(int i=0; i<5; i++){
        newNode = createNode(i);
        addNode(&List, newNode);
        
    }
    count = countNode(List);
    
    for(int i=0; i<count; i++){
        Curr = getNodeAt(List,i);
        cout << Curr->data;
    }
    
    cout << "Node Craeted\n";
    newNode = createNode(99);
    Curr = getNodeAt(List,0);
    insertNode(Curr,newNode);
    
    newNode = createNode(444);
    Curr = getNodeAt(List,4);
    insertNode(Curr,newNode);
    
    count = countNode(List);
    
    for(int i=0; i<count; i++){
        Curr = getNodeAt(List,i);
        cout << Curr->data;
    }
    cout << "After 2 Node Insterd\n";
    newNode = getNodeAt(List,1);
    removeNode(&List,newNode);
    
    newNode = getNodeAt(List,0);
    removeNode(&List,newNode);
    
    count = countNode(List);
    for(int i=0; i<count; i++){
        Curr = getNodeAt(List,i);
        cout << Curr->data;
    }
    
    
}
