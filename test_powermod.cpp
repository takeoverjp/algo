#include <limits.h>

#include <gtest/gtest.h>

#include "powermod.h"

TEST (powermod, positive)
{
  ASSERT_EQ (1, powermod(1, 1, 3));
  ASSERT_EQ (2, powermod(2, 3, 3));
  ASSERT_EQ (3, powermod(3, 5, 4));
  ASSERT_EQ (0, powermod(3, 5, 3));
  ASSERT_EQ (0, powermod(3, 1024, 3));
}

TEST (powermod, border)
{
  ASSERT_EQ (1, powermod(3, INT_MAX, 2));
  ASSERT_EQ (0, powermod(INT_MAX, INT_MAX, INT_MAX));
  ASSERT_EQ (3, powermod(3, INT_MAX, INT_MAX));
  ASSERT_EQ (-1, powermod(INT_MIN, 3, 3));
  ASSERT_EQ (-1, powermod(3, INT_MIN, 3));
  ASSERT_EQ (-1, powermod(3, 3, INT_MIN));
  ASSERT_EQ (-1, powermod(INT_MIN, INT_MIN, 3));
  ASSERT_EQ (-1, powermod(3, INT_MIN, INT_MIN));
  ASSERT_EQ (-1, powermod(INT_MIN, 3, INT_MIN));
  ASSERT_EQ (-1, powermod(INT_MIN, INT_MIN, INT_MIN));
}

TEST (powermod, invalid)
{
  ASSERT_EQ (-1, powermod(-1, 3, 3));
  ASSERT_EQ (-1, powermod(3, -1, 3));
  ASSERT_EQ (-1, powermod(3, 3, -1));
  ASSERT_EQ (-1, powermod(3, 3, 0));
  ASSERT_EQ (-1, powermod(-1, -1, 3));
  ASSERT_EQ (-1, powermod(3, -1, -1));
  ASSERT_EQ (-1, powermod(-1, 3, -1));
  ASSERT_EQ (-1, powermod(3, -1, 0));
  ASSERT_EQ (-1, powermod(-1, 3, 0));
  ASSERT_EQ (-1, powermod(-1, -1, -1));
  ASSERT_EQ (-1, powermod(-1, -1, -1));
}
