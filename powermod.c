#include <stdio.h>
#include "powermod.h"

#if defined(DEBUG)
#else  /* DEBUG */
#endif /* DEBUG */

static int
powermod_normal (int a, int k, int m)
{
  int i = 0;
  long work = 1;

  for (i = 0; i < k; i++)
    {
      work = work * a % m;
      // printf ("work[%d] = %d\n", i, work);
    }
  return work;
}

static int
powermod_recursive (int a, int k, int m)
{
  long long work = 1;

  if (k == 0)
    return 1 % m;
  if (k == 1)
    return a % m;

  work = powermod (a, k/2, m);
  work = work * work % m;
  if (k % 2 == 1)
    work = work * a % m;

  return work;
}

int
powermod (int a, int k, int m)
{
  if (a < 0 || k < 0 || m <= 0)
    {
      //fprintf (stderr, "Invalid argument\n");
      return -1;
    }

  //  return powermod_normal (a, k, m);
  return powermod_recursive (a, k, m);
}
