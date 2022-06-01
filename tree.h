#ifndef TREE_H
#define TREE_H

#include <stdio.h>

struct tree
{
   char elem;
   tree *left, *right;

   tree(char _elem = '\0', tree *_left = NULL, tree *right = NULL);

   void input(FILE *fp);
   void inorder(char find);
   void preorder(char find);
   void postorder(char find);
   bool preorder_rec(char find);
   bool inorder_rec(char find);
   bool postorder_rec(char find);
};

#endif TREE_H