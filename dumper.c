#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dumper.h"

#define INITIAL_NAME_COLUMN_WIDTH 15
#define MAX_NAME_COLUMN_WIDTH 50
#define INITIAL_ADDRESS_WIDTH 16

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
void dumper(char **names, void **addrs, size_t *lengths, size_t count, FILE *stream)
{
  int name_column_width = INITIAL_NAME_COLUMN_WIDTH;
  int address_column_width = INITIAL_ADDRESS_WIDTH;

  /**
   * Set the name column width to fit the largest name, up to MAX_NAME_COLUMN_WIDTH characters
   */
  for ( size_t j = 0; j < count; j++ )
  {
    if (strlen(names[j]) > name_column_width && strlen(names[j]) < MAX_NAME_COLUMN_WIDTH )
    {
      name_column_width = strlen(names[j]);
    }
    else if ( strlen(names[j]) >= MAX_NAME_COLUMN_WIDTH )
    {
      name_column_width = MAX_NAME_COLUMN_WIDTH;
      break;
    }
  }

  fprintf( stream,"%*s%*s%5s%5s%5s%5s\n", name_column_width, "Item", 
                                          address_column_width, "Address", "00", "01", "02", "03" );
  fprintf( stream,"%*s%*s%5s%5s%5s%5s\n", name_column_width, "----", 
                                          address_column_width, "-------", "--", "--", "--", "--" );
  
  for ( size_t i = 0; i < count; i++ )
  {
    char *namefield = names[i];
    unsigned char *p = (unsigned char *) addrs[i];
    for ( size_t j = 0; j < lengths[i]; j+=4 )
    {
      size_t k;

      fprintf( stream,"%*.*s", name_column_width, name_column_width, namefield );
      fprintf( stream,"%*p", address_column_width, (void *) p );
      for ( k = 0; k < 4; k++ )
      {
        fprintf( stream,"%3s%02x", " ", p[k] );
      }
      fprintf( stream, "    " );
      for ( k = 0; k < 4; k++ )
      {
        if ( isgraph( p[k] ) )
          fprintf( stream,"%c", p[k] );
        else
          fprintf( stream, "." );
      }
      fputc( '\n', stream );
      namefield = " ";
      p += 4;
    }
    fputc( '\n', stream );
  }
}
