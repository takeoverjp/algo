#include <stdio.h>
#include <sys/types.h>
#include "contains.h"

bool
contains (int a, int array[], size_t array_size)
{
  u_int i = 0;

  if (array == NULL || array_size <= 0)
    {
      //fprintf (stderr, "Invalid argument\n");
      return false;
    }

  for (i = 0; i < array_size; i++)
    {
      if (a == array[i])
	return true;
    }
  return false;
}
