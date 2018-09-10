# dumper

Dumper is a simple C utility for dumping the contents of objects in memory.  

## Purpose

The dumper utility allows you to see the binary contents of objects in memory, given
an object's address and size.  You can also specify the name of the objects.  Output
is a formatted table of object contents.  You can specify the output stream, so 
output can be written to a file.

## Example

The best way to explain what dumper does is with an example.  Here's a typical use:

	#include <stdio.h>
	#include "dumper.h"

	int main( void )
	{
	  int x = 10;
	  double y = 3.14159;
	  char str[] = "This is not a test";
	  int *p = &x;

	  char *names[] = {"x", "y", "str", "p"};
	  void *addrs[] = {&x, &y, str, &p};
	  size_t sizes[] = { sizeof x, sizeof y, sizeof str, sizeof p};

	  dumper( names, addrs, sizes, 4, stdout );

	  return 0;
	}

This code is built as follows:

    gcc -o test_dumper -std=c11 -pedantic -Wall -Werror test_dumper -L. -ldumper
    
When run, the output is:

           Item         Address   00   01   02   03
           ----         -------   --   --   --   --
              x  0x7ffee1e74a48   0a   00   00   00    ....

              y  0x7ffee1e74a40   6e   86   1b   f0    n...
                 0x7ffee1e74a44   f9   21   09   40    .!.@

            str  0x7ffee1e74ab0   54   68   69   73    This
                 0x7ffee1e74ab4   20   69   73   20    .is.
                 0x7ffee1e74ab8   6e   6f   74   20    not.
                 0x7ffee1e74abc   61   20   74   65    a.te
                 0x7ffee1e74ac0   73   74   00   00    st..

              p  0x7ffee1e74a38   48   4a   e7   e1    HJ..
                 0x7ffee1e74a3c   fe   7f   00   00    ....

