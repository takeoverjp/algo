#include <stdio.h>
#include <sys/types.h>
#include "sort.h"

int
bubble_sort (int array[], size_t array_size)
{
  u_int i = 0, j = 0;
  if (array == NULL || array_size <= 0)
    {
      //fprintf (stderr, "Invalid argument\n");
      return -1;
    }

  for (j = 1; j < array_size; j++)
    {
      for (i = 0; i < array_size-j; i++)
        {
          if (array[i] > array[i+1])
            {
              int tmp = array[i];
              array[i] = array[i+1];
              array[i+1] = tmp;
            }
        }
    }

  return 0;
}
