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
//need to be fixed
void preorder_rec(tree *&node, char find, char cmd)
{
   if (node == NULL)
      return;
   if (node->elem != find)
   {
      printf("%c -> ", node->elem);
      if (!cmd)
         preorder_rec(node->left, find, cmd);
      if (!cmd)
         preorder_rec(node->right, find, cmd);
   }
   else cmd = true;
};

void inorder_rec(tree *&node, char find, char tmp)
{
   bool completed = false;
   if (node == NULL)
      return;
   if (tmp != find)
   {
      inorder_rec(node->left, find, tmp);
      tmp = node->elem;
      printf("%c", node->elem);
      inorder_rec(node->right, find, tmp);
   }
};

void postorder_rec(tree *&node, char find, char tmp)
{
   bool completed = false;
   if (node == NULL)
      return;
   if (tmp != find)
   {
      postorder_rec(node->left, find, tmp);
      postorder_rec(node->right, find, tmp);
      tmp = node->elem;
      printf("%c", node->elem);
   }
};


int main()
{
   setlocale(LC_ALL, "");
   tree *t = new tree();
   FILE *f{};
   t->input(f);
   char cmd = '\0', elem = '\0', tmp = '\0';
   bool cmd = false;

   printf("Введите искомый элемент дерева:\n");
   scanf_s("%c", &elem, sizeof(char));
   printf_s("Выберете метод поиска элемента:\n\n %d - Прямой\n %d - Обратный\n %d - Концевой\n %d - Прямой рекурсивный\n %d - Обратный рекурсивный\n %d - Концевой рекурсивный\n %d - Выход из программы\n\n", PreOrder, InOrder, PostOrder, PreOrderRec, InOrderRec, PostOrderRec, Exit);
   bool repeatFlag = true;
   do
   {
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
            preorder_rec(t, elem, cmd);
            break;
         case InOrderRec:
            inorder_rec(t, elem, tmp);
            break;
         case PostOrderRec:
            postorder_rec(t, elem, tmp);
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