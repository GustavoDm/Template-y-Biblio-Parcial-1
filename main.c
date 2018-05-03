#include <stdio.h>
#include <stdlib.h>
#include "getsValids.h"

int main()
{

  char pepe[40];
  int juan;
  get_String("mensaje: ", pepe);
  juan=val_flotante(pepe);
  printf("%d", juan);
    return 0;
}
