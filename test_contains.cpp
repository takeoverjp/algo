#include <limits.h>

#include <gtest/gtest.h>

#include "contains.h"

TEST (contains, positive)
{
  int array[] = {0, 1, 2, 3, 4, 5, 6};
  size_t size = sizeof(array);
  ASSERT_TRUE (contains (0, array, size));
  ASSERT_TRUE (contains (1, array, size));
  ASSERT_TRUE (contains (2, array, size));
  ASSERT_TRUE (contains (3, array, size));
  ASSERT_TRUE (contains (4, array, size));
  ASSERT_TRUE (contains (5, array, size));
  ASSERT_TRUE (contains (6, array, size));
  ASSERT_FALSE (contains (-1, array, size));
  ASSERT_FALSE (contains (7, array, size));
  ASSERT_FALSE (contains (INT_MIN, array, size));
  ASSERT_FALSE (contains (INT_MAX, array, size));
}

TEST (contains, negative)
{
  int array[] = {-100, -80, -50, -30, -5, -4, -2, -1, 0};
  size_t size = sizeof(array);
  ASSERT_TRUE (contains (-100, array, size));
  ASSERT_TRUE (contains (-80, array, size));
  ASSERT_TRUE (contains (-50, array, size));
  ASSERT_TRUE (contains (-30, array, size));
  ASSERT_TRUE (contains (-5, array, size));
  ASSERT_TRUE (contains (-4, array, size));
  ASSERT_TRUE (contains (-2, array, size));
  ASSERT_TRUE (contains (-1, array, size));
  ASSERT_TRUE (contains (0, array, size));
  ASSERT_FALSE (contains (-3, array, size));
  ASSERT_FALSE (contains (7, array, size));
  ASSERT_FALSE (contains (INT_MIN, array, size));
  ASSERT_FALSE (contains (INT_MAX, array, size));
}

TEST (contains, mix)
{
  int array[] = {-100, -80, -50, -30, -5, -4, -2, -1, 0,
		 1, 2, 3, 4, 5, 6};
  size_t size = sizeof(array);
  ASSERT_TRUE (contains (-100, array, size));
  ASSERT_TRUE (contains (-80, array, size));
  ASSERT_TRUE (contains (-50, array, size));
  ASSERT_TRUE (contains (-30, array, size));
  ASSERT_TRUE (contains (-5, array, size));
  ASSERT_TRUE (contains (-4, array, size));
  ASSERT_TRUE (contains (-2, array, size));
  ASSERT_TRUE (contains (-1, array, size));
  ASSERT_TRUE (contains (0, array, size));
  ASSERT_TRUE (contains (1, array, size));
  ASSERT_TRUE (contains (2, array, size));
  ASSERT_TRUE (contains (3, array, size));
  ASSERT_TRUE (contains (4, array, size));
  ASSERT_TRUE (contains (5, array, size));
  ASSERT_TRUE (contains (6, array, size));
  ASSERT_FALSE (contains (-3, array, size));
  ASSERT_FALSE (contains (7, array, size));
  ASSERT_FALSE (contains (INT_MIN, array, size));
  ASSERT_FALSE (contains (INT_MAX, array, size));
}

TEST (contains, invalidArgument)
{
  int array[] = {0, 1, 2, 3, 4, 5, 6};
  size_t size = sizeof(array);
  ASSERT_FALSE (contains (0, NULL, 0));
  ASSERT_FALSE (contains (0, array, 0));
  ASSERT_FALSE (contains (0, NULL, size));
}
