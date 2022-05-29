#include "list.h"
#include <stdio.h>

list::list(tree *_elem, list *_next) : elem(_elem), next(_next) {}