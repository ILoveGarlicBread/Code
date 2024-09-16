#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
  FILE *source, *des;
  int c;
  char filename[100];
  printf("Input source file: ");
  scanf("%s", filename);
  source = fopen(filename, "r");
  if (source == NULL)
  {
      printf("Cannot open file %s\n", filename);
      exit(1);
  }

  printf("Input destination file: ");
  scanf("%s", filename);

  des = fopen(filename, "w");
  if (des == NULL)
  {
      printf("Cannot open file %s\n", filename);
      exit(1);
  }

  while ((c = fgetc(source)) != EOF)
  {
      fputc(c, des);
  }

  printf("Contents copied to %s\n", filename);

  fclose(source);
  fclose(des);


  return 0;
}
