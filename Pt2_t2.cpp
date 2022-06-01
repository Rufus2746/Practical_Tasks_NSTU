#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "stack.h"

enum command
{
   PreOrder = 1, //Root, Left, Right - в глубину, прямой, префиксный
   InOrder,      //Left, Root, Right - обратный, инфиксный
   PostOrder,    //Left, Right, Root - концевой, постфиксный
   PreOrderRec,
   InOrderRec,
   PostOrderRec,
   Exit
};

void preorder_rec(tree *&node, char find, bool *completed)
{
   if (node == NULL)
      return;
   if (node->elem != find)
   {
      if (!*completed)
         printf("%c -> ", node->elem);
      if (!*completed)
         preorder_rec(node->left, find, completed);
      if (!*completed)
         preorder_rec(node->right, find, completed);
   }
   else
   {
      printf("%c", node->elem);
      *completed = true;
   }
};

void inorder_rec(tree *&node, char find, bool *completed)
{
   if (node == NULL)
      return ;
   if (node->elem != find)
   {
      if (!*completed)
         inorder_rec(node->left, find, completed);
      if (!*completed)
         printf("%c -> ", node->elem);
      if (!*completed)
         inorder_rec(node->right, find, completed);
   }
   else
   {
      *completed = true;
      printf("%c", node->elem);
   }
};

void postorder_rec(tree *&node, char find, bool *completed)
{
   if (node == NULL)
      return;
   if (node->elem != find)
   {
      if (!*completed)
         postorder_rec(node->left, find, completed);
      if (!*completed)
         postorder_rec(node->right, find, completed);
      if (!*completed)
         printf("%c -> ", node->elem);
   }
   else
   {
      *completed = true;
      printf("%c", node->elem);
   }
};


void math(int *_a, int *_b)
{
   *_a = 20;
   *_b = 30;
}



int main()
{
   setlocale(LC_ALL, "");
   tree *t = new tree();
   FILE *f{};
   t->input(f);
   char cmd = '\0', elem = '\0', tmp = '\0';
   bool completed = false;

   int a = 10, b = 15;

   math(&a, &b);
   printf("%d, %d\n", a, b);

   printf("Введите искомый элемент дерева:\n");
   scanf_s("%c", &elem, sizeof(char));
   do
   {
      printf_s("Выберете метод поиска элемента:\n\n %d - Прямой\n %d - Обратный\n %d - Концевой\n %d - Прямой рекурсивный\n %d - Обратный рекурсивный\n %d - Концевой рекурсивный\n %d - Выход из программы\n\n", PreOrder, InOrder, PostOrder, PreOrderRec, InOrderRec, PostOrderRec, Exit);
      bool repeatFlag = true;
      do
      {
         scanf_s("\n%c", &cmd, 1);
         switch (cmd - '0')
         {
         case PreOrder:
            t->preorder(elem);
            break;
         case InOrder:
            t->inorder(elem);
            break;
         case PostOrder:
            t->postorder(elem);
            break;
         case PreOrderRec:
            completed = false;
            preorder_rec(t, elem, &completed);
            break;
         case InOrderRec:
            completed = false;
            inorder_rec(t, elem, &completed);
            break;
         case PostOrderRec:
            completed = false;
            postorder_rec(t, elem, &completed);
            break;
         case Exit:
            cmd = cmd - '0';
            break;
         default:
            repeatFlag = false; break;
         }
         printf_s("\n\n");
      } while (repeatFlag && cmd != Exit);
   } while (cmd != Exit);


   return 0 * _getch();
}