#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int dfs(Node * node);

bool equalPaths(Node * root)
{
  return dfs(root) != -1;

}

int dfs(Node * node){
  if (node == nullptr){
    return 1;
  }

  int left = dfs(node->left);
  int right = dfs(node->right);

  if (left == -1 || right == -1){
    return -1;
  }

  if (node->left == nullptr){
    return right + 1;
  }

  if (node->right == nullptr){
    return left + 1;
  }

  if (left != right){
    return -1;
  }

  return right + 1;

}