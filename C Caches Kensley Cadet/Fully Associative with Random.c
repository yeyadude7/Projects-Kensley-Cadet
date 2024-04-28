//Fully Associative with Random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{

  FILE * ptr;

  
  ptr = fopen("traces.txt", "r");
  char buffer[15];
  char ** cache = (char **) malloc(sizeof(char *) * 32);

  for (int i = 0; i < 32; i++)
  {
    cache[i] = NULL;
  }

  int hit = 0;
  int miss = 0;
  int x = 0;

  int access = 0;
  int cmp = 5;
  int size;
  int hold = 3;
  int tim;
  while (fgets(buffer, 15, ptr) != NULL)
  {
    size = strlen(buffer);
    access++;

    hold = hit;
    for (int i = 0; i < 32; i++)
    {
      if (cache[i] != NULL)
      {
        cmp = strcmp(cache[i], buffer);
      }
      if (cmp == 0)
      {
        hit++;
        break;
      }
      
      if (cache[i] == NULL)
      {
        cache[i] = (char *) malloc(sizeof(char) * 15);
        strcpy(cache[i], buffer);
        miss++;
        
        break;
      }
    }

    if (hold == hit)
      {
        miss++;

        //replacement algorithm

        //Random
        int mod = x % 32;
        strcpy(cache[mod], buffer);
        x *= access;
        x -= access;
        x += access;
        x /= access;
      }
  }

  printf("NUMBER OF HITS = %d\n", hit);
  printf("NUMBER OF ACCESSES = %d\n", access);
  printf("HIT RATE = %lf\n", (double) hit/ (double) access);
  fclose(ptr);
  return 0;
}