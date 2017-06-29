#include <stdio.h>
#include <sys/types.h>
#include "contains.h"

bool
contains (int a, int array[], size_t array_size)
{
  if (array == NULL || array_size <= 0)
    {
      //fprintf (stderr, "Invalid argument\n");
      return false;
    }

  if (array_size == 1)
    return (a == array[0]) ? true : false;

  size_t l_size = array_size / 2;
  size_t r_size = array_size - l_size;
  if (a == array[l_size])
    return true;
  else if (a < array[l_size])
    return contains (a, array, l_size);
  else
    return contains (a, array + l_size, r_size);
}
