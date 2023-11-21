#ifndef _HASH_COLLISION_H_
#define _HASH_COLLISION_H_

#include <stdio.h>
#include "hash_tables.h"

unsigned int djb2_hash(const char *string);
void test_collisions(const char *strings[], int n);
int main();

#endif /* end of _HASH_COLLISION_H_ file */
