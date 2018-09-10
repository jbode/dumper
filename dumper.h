#ifndef DUMPER_H
#define DUMPER_H

#include <stdio.h>

/**
 * Dumps a memory map to the specified output stream
 *
 * Inputs:
 *
 *   names     - list of item names
 *   addrs     - list of addresses to different items
 *   lengths   - length of each item
 *   count     - number of items being dumped
 *   stream    - output destination
 *
 * Outputs: none
 * Returns: none
 */
#ifdef __cplusplus
extern "C" 
{
#endif

  void dumper(char **names, void **addrs, size_t *lengths, size_t count, FILE *stream);

#ifdef __cplusplus
}
#endif


#endif
