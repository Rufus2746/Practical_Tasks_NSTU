#include <stdio.h>
#include "tree.h"
#include "stack.h"


tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {}
void tree::input(FILE *fp)
{
   tree *current = this;
   stack *s = new stack();

   elem = fgetc(fp);
   for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
   {
      switch (c)
      {
      case '(':
         char next = fgetc(fp);
         if (next == ',')
         {
            s->push(current);
            current = current->left = new tree(next);
            break;
         }
      case ',':
         current = s->peek();
         current = current->right = new tree(fgetc(fp));
         break;
      default:
         s->pop(&current);
         break;
      }
   }
};

void inorder(tree *t, char el)
{
   stack *s = new stack();
   char tmp = '\0';
   while (tmp != el)
   {
      while (t != NULL)
      {
         s->push(t);
         t = t->left;
      }
      if (t == NULL)
         s->pop(&t);

   }

   delete s;
};