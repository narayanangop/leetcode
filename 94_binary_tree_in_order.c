#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void helper(struct TreeNode* root, int *arr, int *index) {

    if(root == NULL) {
        return;
    }
    if(root->left) {
        helper(root->left, arr, index);
    }
    arr[*index] = root->val;
    *index = *index + 1;

    if(root->right) {
        helper(root->right, arr, index);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int *ret = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    helper(root, ret, returnSize);
    

    return ret;
    
}