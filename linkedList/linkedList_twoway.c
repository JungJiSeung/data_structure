#include <stdio.h>
#include <stdlib.h>

// item of LinkedList 
typedef struct _Node {
    int data;
    struct _Node* next;
    struct _Node* prev;
} Node;

// LinkedList DataStructure
typedef struct _LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* link;

/*
 * Operation : Make node and Add node to list
 * Arguments : list - A pointer of LinkedList
 *             data - A Data is added to LinkedList
 */
void addItem(LinkedList* list, int data) {
    Node* node;

    if(list == NULL) return;

    node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        node->next->prev = node;
        list->head = node;
    }
}

/*
 * Operation : Search item from LinkedList
 * Arguments : list - A pointer of LinkedList
 *             data - it is data to search item
 */
Node* searchNode(LinkedList* list, int data) {
    Node* node;

    if(list == NULL) return NULL;

    node = list->head;

    while(node != NULL) {
        if(node->data == data) return node;
        node = node->next;
    }

    return NULL;
}

/*
 * Operation : Remove Node that is same argument data with linkedList data 
 * Arguments : list - A pointer of LinkedList
 *             data - A data is removed to LinkedList
 * return : if exsist error then 0
 *          else return 1
 *          
 */
int removeItem(LinkedList* list, int data) {
    Node *node;

    if(list == NULL) return 0;
    
    node = searchNode(list, data);

    // Not exsist data
    if(node == NULL) return 0;

    if(node == list->head) {
        list->head = node->next;
        
        if(list->head == NULL) {
            list->tail = NULL;
        } else {
            list->head->prev = NULL;
        }

    } else if(node == list->tail) {
        list->tail = node->prev;
        list->tail->next = NULL;
    } else { 
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    return 1;
}

/*
 * Operation : Print data of LinkedList
 * Argument  : list - A pointer of LinkedList
 */
void printList(LinkedList* list) {
    Node* node;

    if(list == NULL) return;
    
    printf("printList\n");

    node = list->head;

    while(node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

void printList_reverse(LinkedList* list) {
    Node* node;

    if(list == NULL) return;

    printf("printList_Reverse\n");

    node = list->tail;

    while(node != NULL) {
        printf("%d\n", node->data);
        node = node->prev;
    }
}

void initLinkedList(LinkedList* list) {
    if(link == NULL) return;

    link->head = NULL;
    link->tail = NULL;
}
   
int main(void) {
    link = malloc(sizeof(LinkedList));
    initLinkedList(link);

    addItem(link, 10);   
    addItem(link, 11);   
    addItem(link, 12);   
    addItem(link, 13);   
    printList(link);
    printList_reverse(link);
    removeItem(link, 10);
    printList(link);
    removeItem(link, 11);
    printList(link);
    removeItem(link, 12);
    printList(link);
    removeItem(link, 13);
    printList(link);
    return 0;
}
