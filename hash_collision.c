#include <stdio.h>
#include "hash_collision.h"
#include "hash_tables.h"

/**
 * djb2_hash - Calculates the djb2 hash of a string.
 *
 * @param string: The string to hash.
 * Return: hash value.
 */
unsigned int djb2_hash(const char *string)
{
  unsigned int hash = 5381;
  while (*string != '\0')
  {
    hash = ((hash << 5) + hash) + *string;
    string++;
  }
  return hash;
}

/**
 * test_collisions - Tests for collisions in the djb2 hash function.
 *
 * @param strings: An array of strings to hash.
 * @param n: The number of strings in the array.
 * Return: void
 */
void test_collisions(const char *strings[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++) {
      unsigned int hash_i = djb2_hash(strings[i]);
      unsigned int hash_j = djb2_hash(strings[j]);
      if (hash_i == hash_j)
      {
        printf("Collision detected: %s and %s have the same hash value (%u).\n", strings[i], strings[j], hash_i);
      }
    }
  }
}

/**
 * main - programme entry point
 *
 * Return: success (0), fail (non-zero value)
 */
int main()
{
  const char *strings[] = {
    "hetairas",
    "mentioner",
    "heliotropes",
    "neurospora",
    "depravement",
    "serafins",
    "stylist",
    "subgenera",
    "joyful",
    "synaphea",
    "redescribed",
    "urites",
    "dram",
    "vivency"
  };
  int n = sizeof(strings) / sizeof(strings[0]);

  test_collisions(strings, n);

  return 0;
}
