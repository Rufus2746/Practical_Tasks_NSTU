#include <stdio.h>
#include <locale.h>
#include "tree.h"
#include "stack.h"

enum commands
{
   PREORDER = 1,
   INORDER,
   POSTORDER,
   PREORDER_REC,
   INORDER_REC,
   POSTORDER_REC
};
bool input(tree *t)
{
   FILE *fp;
   fopen_s(&fp, "input.txt", "r");
   if (!fp) return false;

   t->input(fp);

   return true;
}
//ъуъ
int main()
{
   tree *t = new tree();
   input(t);

   stack *s = new stack();
   s->push(t);

   tree *peeked = s->peek();
   tree *leftiguess = peeked->left;
   
   /*
   setlocale(LC_ALL, "");
   char c = '\0', cmd = '\0';

   printf("Введите искомый элемент дерева:\n");
   scanf_s(" %c", &c, sizeof(char));
   printf("Выберите метод поиска\n");
   scanf_s(" %c", &cmd, sizeof(char));

   switch (cmd)
   {
   case (INORDER):

         break;
   default:
      printf("nonon listenlisten\n");
      break;
   }
   */
   return 0;
}