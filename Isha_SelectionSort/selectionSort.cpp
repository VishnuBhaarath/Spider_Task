#include <stdio.h>
 
int main()
{
  int array[100], n, i, j, min, swap;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
 
  for (i = 0; i < (n - 1); i++)
  {
    min = i;
   
    for (j = i + 1; j < n; j++)
    {
      if (array[min] > array[j])
        min = j;
    }
    if (min != i)
    {
      swap = array[i];
      array[i] = array[min];
      array[min] = swap;
    }
  }
 
  printf("The Sorted Numbers in ascending order are \n");
 
  for (i = 0; i < n; i++)
    printf("%d\t", array[i]);
 
  return 0;
}

