#include "/home/drl7x/re/LCLintDev/lib/ansi.h"

void anstrcpy( /*@unique@*/ char * a, char *b) /*@bufferConstraint MaxSet(a) >= MaxRead (b); @*/ {
strcpy (a,b);
}

