#include "tree.h"
#include "stack.h"
#include <stdio.h>

tree::tree(char _elem, tree *_left, tree *_right) : elem(_elem), left(_left), right(_right) {};
void tree::input(FILE *fp)
{
   tree *current = this;
   stack *s = new stack;

   errno_t err = fopen_s(&fp, "input.txt", "r");
   printf_s("Открытие файла\n");

   if (fp)
   {
      for (char elem = fgetc(fp); elem != EOF; elem = fgetc(fp))
      {
         switch (elem)
         {
         case '(':
            elem = fgetc(fp);
            if (elem == ',')
            {
               elem = fgetc(fp);
               s->push(current);
               current = current->right = new tree(elem);
            }
            else
            {
               s->push(current);
               current = current->left = new tree(elem);
            }
            break;
         case ',':
            elem = fgetc(fp);
            if (elem == ')')
               s->pop(&current);
            else
            {
               current = s->peek();
               current = current->right = new tree(elem);
            }
            break;
         case ')':
            s->pop(&current);
            break;
         default:
            current->elem = elem;
            break;
         }
      }
      fclose(fp);
   }
   else perror("Не удалось открыть файл\n");
};

void tree::preorder(char find)
{
   tree *current = this;
   stack *s = new stack;
   bool completed = false;
   s->push(current);
   while (!completed)
   {
      s->pop(&current);
      if (current->elem != find)
      {
         printf("%c -> ", current->elem);
         if (current->right != NULL)
            s->push(current->right);
         if (current->left != NULL)
            s->push(current->left);
      }
      else
      {
         printf("%c\n", current->elem);
         completed = true;
      }
   }
};

void tree::inorder(char find)
{
   tree *current = this;
   stack *s = new stack;
   bool completed = false;
   while (!completed)
   {
      if (current != NULL)
      {
         s->push(current);
         current = current->left;
      }
      else
      {
         if (!s->empty())
         {
            s->pop(&current);
            if (current->elem == find)
            {
               printf("%c\n", current->elem);
               completed = true;
            }
            else
            {
               printf("%c -> ", current->elem);
               current = current->right;
            }
         }
         else
            completed = true;
      }
   }
};

void tree::postorder(char find)
{
   tree *current = this, *previous = NULL;
   stack *s = new stack;
   bool completed = false;
   while (!completed)
   {
      if (current != NULL)
      {
         s->push(current);
         current = current->left;
      }
      else
      {
         current = s->peek();
         if (current->right == NULL || current->right == previous)
         {
            if (current->elem != find)
            {
            printf("%c -> ", current->elem);
            s->pop(&current);
            previous = current;
            current = NULL;
            }
            else
            {
               printf("%c", current->elem);
               completed = true;
            }
         }
         else
            current = current->right;
      }
   }
}