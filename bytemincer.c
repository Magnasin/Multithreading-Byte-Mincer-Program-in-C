#include "ringbuf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
  FILE *file;
  FILE *copy;
  
  int option;
  int i = 1;
  int rm;
  void *data;
  struct ringbuf_t* buffer = rb_init(255);

  if (argc < 4)
  {
      printf("Enough arguments required!\n");
      exit(1);
  }
  
  while ((option = getopt(argc, argv, ":o")) != -1){
      switch (option)
      {
      case 'o':
        while(i< argc-2){
            file = fopen(argv[i],"r");

            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            fseek(file,0, SEEK_SET);

            data = malloc(file_size);
            memset(data, 0,file_size);
            fread(data,1, file_size, file);
            fclose(file);
            
            copy = fopen(argv[optind],"a");
            fwrite(data, 1, file_size, copy);
            fclose(copy);
            i++;
        }
          break;
      
      default:
          printf("Invalid option\n");
          break;
      }
  }

  return 0;
}
