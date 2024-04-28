//2-Way Cache with Random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{

  FILE * ptr;

  
  ptr = fopen("traces.txt", "r");
  char buffer[15];
  char *** cache = (char ***) malloc(sizeof(char **) * 16);

  for (int i = 0; i < 16; i++)
  {
    cache[i] = (char **) malloc(sizeof(char *) * 2);

    for (int j = 0; j < 2; j++)
    {
      cache[i][j] = NULL;
    }
  }

  int hit = 0;
  int miss = 0;
  int x = 0;

  int access = 0;
  int cmp = 5;
  int size = 0;
  int hold = 3;
  int hash = 0;
  
  while (fgets(buffer, 15, ptr) != NULL)
  {
    access++;
    size = strlen(buffer);;
    for (int i = 0; i < size; i++)
    {
      hash += (int) buffer[i];
    }

    hash = hash % 16;
    
    hold = hit;

    for (int i = 0; i < 2; i++)
    {
      if (cache[hash][i] != NULL)
      {
        cmp = strcmp(cache[hash][i], buffer);
      }
      if (cmp == 0)
      {
        hit++;
        break;
      }
      
      if (cache[hash][i] == NULL)
      {
        cache[hash][i] = (char *) malloc(sizeof(char) * 15);
        strcpy(cache[hash][i], buffer);
        miss++;
        break;
      }
    }

    if (hit == miss)
    {
        miss++;

        //replacement algorithm

        //Random
        int mod = x % 2;
        strcpy(cache[hash][mod], buffer);
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