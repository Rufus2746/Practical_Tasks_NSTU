#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "stack.h"

enum command
{
   PreOrder = 1, //Root, Left, Right - � �������, ������, ����������
   InOrder,      //Left, Root, Right - ��������, ���������
   PostOrder,    //Left, Right, Root - ��������, �����������
   PreOrderRec,
   InOrderRec,
   PostOrderRec,
   Exit
};

int main()
{
   setlocale(LC_ALL, "");
   tree *t = new tree();
   FILE *f = NULL;
   t->input(f);
   char cmd = '\0', elem = '\0';

   printf("������� ������� ������� ������:\n");
   scanf_s("%c", &elem, sizeof(char));
   do
   {
      printf_s("�������� ����� ������ ��������:\n\n %d - ������\n %d - ��������\n %d - ��������\n %d - ������ �����������\n %d - �������� �����������\n %d - �������� �����������\n %d - ����� �� ���������\n\n", PreOrder, InOrder, PostOrder, PreOrderRec, InOrderRec, PostOrderRec, Exit);
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
            t->preorder_rec(elem);
            break;
         case InOrderRec:
            t->inorder_rec(elem);
            break;
         case PostOrderRec:
            t->postorder_rec(elem);
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