#include <sys/types.h>
#include <limits.h>

#include <gtest/gtest.h>

#include "sort.h"

TEST (bubble_sort, no_change)
{
  int array[] = {0, 1, 2, 3, 4, 5, 6};
  size_t size = sizeof(array) / sizeof(array[0]);
  u_int i = 1;
  ASSERT_EQ (0, bubble_sort (array, size));
  for (i = 1; i < size; i++)
    ASSERT_LE (array[i-1], array[i]);
}

TEST (bubble_sort, reverse)
{
  int array[] = {6, 5, 4, 3, 2, 1, 0};
  size_t size = sizeof(array) / sizeof(array[0]);
  u_int i = 1;
  ASSERT_EQ (0, bubble_sort (array, size));
  for (i = 1; i < size; i++)
    ASSERT_LE (array[i-1], array[i]);
}

TEST (bubble_sort, random)
{
  int array[] = {-6, 5, -4, 3, -2, 1, 0};
  size_t size = sizeof(array) / sizeof(array[0]);
  u_int i = 1;
  ASSERT_EQ (0, bubble_sort (array, size));
  for (i = 1; i < size; i++)
    ASSERT_LE (array[i-1], array[i]);
}

TEST (sort, invalidArgument)
{
  int array[] = {0, 1, 2, 3, 4, 5, 6};
  size_t size = sizeof(array) / sizeof(array[0]);
  ASSERT_LT (bubble_sort (NULL, size), 0);
  ASSERT_LT (bubble_sort (array, 0), 0);
  ASSERT_LT (bubble_sort (NULL, 0), 0);
}
