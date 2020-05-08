#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buffer[1000];

void fold(int batas){
   int i = 0,counter = 0;
   for(int i=0; i<strlen(buffer);i++){
      if(counter == batas){
         printf(1, "\n");
         batas = 0;
      }
     printf(1,"%c",buffer[i]);
     batas += 1;
   }
}

int main(int argc, char *argv[]){
  int fd, batas;

  if(argc == 3){
     if ((fd = open(argv[2], O_RDWR)) < 0){
       printf(1, "Cant open file\n");
       exit();
     }
     batas = atoi(argv[1]+2);
     read(fd, buffer, sizeof(buffer));
     fold(batas);
  }
  else{
    printf(1, "Masukan Argumen dengan benar ARG 1 = Angka ARG 2 = Path\n");
    exit();
  }
  close(fd0);
  exit();
}
