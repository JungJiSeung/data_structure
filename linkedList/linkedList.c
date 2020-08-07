#include <stdio.h>
#include <stdlib.h>

// item of LinkedList 
typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

// LinkedList DataStructure
typedef struct _LinkedList {
    Node* head;
    //Node* tail;
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
    node->next = NULL;

    if(list->head == NULL) {
        list->head = node;
    } else {
        node->next = list->head;
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
    Node *node, *prev;

    if(list == NULL) return 0;

    // Not exsist data
    if(searchNode(list, data) == NULL) return 0;

    node = list->head;
    prev = node;

    while(node != NULL) {
        if(node->data == data) {
            if(node == list->head) {
                list->head = list->head->next;
            } else { 
                prev->next = node->next;
            }
            break;
        }
        prev = node;
        node = node->next;
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

void initLinkedList(LinkedList* list) {
    if(link == NULL) return;

    link->head = NULL;
}
   
int main(void) {
    link = malloc(sizeof(LinkedList));
    initLinkedList(link);

    addItem(link, 10);   
    addItem(link, 11);   
    addItem(link, 12);   
    addItem(link, 13);   
    printList(link);
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
