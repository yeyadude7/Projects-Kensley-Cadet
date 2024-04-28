//Direct Mapping
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

  int access = 0;
  int hit = 0;
  int miss = 0;
  int x = 0;

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

    hash = hash % 31;
    hold = hit;

    if (cache[hash] == NULL)
    {
      cache[hash] = (char *) malloc(sizeof(char) * 15);
      strcpy(cache[hash], buffer);
      miss++;
    }
    else
    {
      cmp = strcmp(cache[hash], buffer);
      
      if (cmp == 0)
      {
        hit++;
      }
      else
      {
        miss++;
        strcpy(cache[hash], buffer);
      }
    }
  }

  printf("NUMBER OF HITS = %d\n", hit);
  printf("NUMBER OF ACCESSES = %d\n", access);
  printf("HIT RATE = %lf\n", (double) hit/ (double) access);
  fclose(ptr);
  return 0;
}