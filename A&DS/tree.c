#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Nodeptr;
struct TreeNode {
  int data;
  Nodeptr FirstChild;
  Nodeptr NextSibling;
};
typedef struct BinaryTree *Treeptr;
struct BinaryTree {
  int data;
  Treeptr left;
  Treeptr right;
};

void Preorder(Treeptr root) {
  if (root) {
    printf("%d", root->data);
    Preorder(root->left);
    Preorder(root->right);
  }
}
void Postorder(Treeptr root) {
  if (root) {
    Postorder(root->left);
    Postorder(root->right);
    printf("%d", root->data);
  }
}
void Inorder(Treeptr root) {
  if (root) {
    Inorder(root->left);
    printf("%d", root->data);
    Inorder(root->right);
  }
}
int main() {

  printf("\n");
  return 0;
}
