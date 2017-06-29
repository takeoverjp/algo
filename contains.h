#if !defined(__CONTAINS_H__)
#define __CONTAINS_H__

#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

  /* array must be sorted! */
  bool contains (int a, int array[], size_t array_size);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __CONTAINS_H__ */
