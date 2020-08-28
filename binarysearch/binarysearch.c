#include <stdio.h>
#include <string.h>

#define TREESIZE 129

// Binary Tree using array
int tree[TREESIZE];

// find item from tree
int search(int item) {
    // fill out!
    return -1;
}

// Add Data to binary tree
void add(int item) {
    int idx = 1;
    int *cur = tree+idx;

    while(tree[idx] != -1) {
        if(tree[idx] >= item) {
            // left child
            idx *= 2;
        } else {
            // right child
            idx = idx * 2 + 1;
        }
    }
    
    tree[idx] = item;
}

// print all items of binary tree
void tree_print(int idx) {

    if(tree[idx] == -1)
        return;
    //left
    tree_print(idx*2);
    //parent
    printf("%d\n", tree[idx]);
    //right
    tree_print(idx*2+1);
}

int main(void) {
    // init tree
    memset(tree, -1, TREESIZE*sizeof(int));

    add(9);
    tree_print(1);
    add(11);
    tree_print(1);
    add(3);
    tree_print(1);
    add(2);
    tree_print(1);
    add(6);
    tree_print(1);
    add(5);
    tree_print(1);
    add(10);
    tree_print(1);
    add(7);
    tree_print(1);
    add(13);

    tree_print(1);
    // Add 9, 11, 3, 2, 6, 5, 10, 7, 13
    
}
