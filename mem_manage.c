#include <stdio.h>
#include <stdlib.h>

int var1 = 10;
int var2 = 20;
int var3 = 30;

int func(int n)
{
  if (n == 0)
    return 0;
  int *local = (int *)malloc(sizeof(int));

  printf("local%i: %p | &local%i: %p \n", n, local, n, &local);

  func(n - 1);
}

int main()
{
  int *ptr1, *ptr2, *ptr3;

  ptr1 = (int *)malloc(var1 * sizeof(int));
  ptr2 = (int *)malloc(var2 * sizeof(int));
  ptr3 = (int *)malloc(var3 * sizeof(int));

  printf("These pointer are stored in stack.\n");
  printf("&ptr1: %p \n", &ptr1);
  printf("&ptr2: %p \n", &ptr2);
  printf("&ptr3: %p \n", &ptr3);
  printf("=================================.\n");
  printf("While their value points to the memory address allocated on the heap.\n");
  printf("ptr1: %p \n", ptr1);
  printf("ptr2: %p \n", ptr2);
  printf("ptr3: %p \n", ptr3);
  printf("=================================.\n");

  printf("Global vars are not related to heap or stack growth.\n");
  printf("var1: %p \n", var1);
  printf("var2: %p \n", var2);
  printf("var3: %p \n", var3);
  printf("=================================.\n");

  printf("start function stack\n");
  func(5);
}