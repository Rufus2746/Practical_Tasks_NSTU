#ifndef TREE_H
#define TREE_H

#include <stdio.h>

struct tree
{
   char elem;
   tree *left;
   tree *right;

   tree(char _elem = '0', tree *_left = NULL, tree *_right = NULL);
   void input(FILE *fp);
   void inorder(tree *t, char el);
};

#endif