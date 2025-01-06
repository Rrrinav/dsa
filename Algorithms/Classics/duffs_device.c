#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Copies size bits from src[] to dest[]
void silly_copy(bool src[], bool dest[], int size)
{
  printf("Starting silly_copy with size = %d\n", size);

  // Do copy in rounds of size 8.
  int rounds = size / 8;
  printf("Rounds to process = %d\n", rounds);

  int i = 0;
  switch (size % 8)
  {
    case 0:
      printf("Entering switch case 0\n");
      while (!(rounds == 0))
      {
        printf("Round: %d, i = %d\n", rounds, i);
        rounds = rounds - 1;
        dest[i] = src[i];
        printf("Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
        i = i + 1;

        // An important point is, the switch
        // control can directly reach below labels
        case 7:
          dest[i] = src[i];
          printf("Case 7: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 6:
          dest[i] = src[i];
          printf("Case 6: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 5:
          dest[i] = src[i];
          printf("Case 5: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 4:
          dest[i] = src[i];
          printf("Case 4: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 3:
          dest[i] = src[i];
          printf("Case 3: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 2:
          dest[i] = src[i];
          printf("Case 2: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
        case 1:
          dest[i] = src[i];
          printf("Case 1: Copied src[%d] = %d to dest[%d]\n", i, src[i], i);
          i = i + 1;
      };
      printf("Finished processing rounds.\n");
  }
}

// Driver code
int main()
{
  int size = 20;
  bool dest[size], src[size];

  // Assign some random values to src[]
  printf("Initializing src array with random values...\n");
  int i;
  for (i = 0; i < size; i++)
  {
    src[i] = rand() % 2;
    printf("src[%d] = %d\n", i, src[i]);
  }

  printf("Calling silly_copy...\n");
  silly_copy(src, dest, size);

  printf("Result after silly_copy:\n");
  for (i = 0; i < size; i++)
    printf("src[%d] = %d -> dest[%d] = %d\n", i, src[i], i, dest[i]);

  return 0;
}
