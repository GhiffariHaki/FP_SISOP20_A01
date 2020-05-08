#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

char buffer[512];

//FUNGSI CEK APAKAH PATH ADALAH DIRECTORY
int isDirectory(char *s) {
	struct stat st;

	int fd = open(s, O_RDONLY);
	fstat(fd, &st);
	int res;

	if (st.type == T_DIR) 
		res = 1;
	else
		res = 0;

	close(fd);
	return res;
}

int searchFile(char *s){
  int i, file=0, w=0, c=0, inword=0;
  int fd = open(s, O_RDONLY);
    while((n = read(fd, buffer, sizeof(buffer))) > 0){
    for(i=0; i<n; i++){
      c++;
      if(buffer[i] == '\n')
        l++;
      if(strchr(" \r\t\n\v", buffer[i]))
        inword = 0;
      else if(!inword){
        w++;
        inword = 1;
      }
    }
  }
  return file;
}

int main(int argc, char *argv[]){

   if(argc < 1){
	    printf(1, "Butuh Argument!!\n");
	    exit();
	}

   if(isDirectory(argv[1])){
  	 if((fd = open(argv[1], 0)) < 0){
            printf(2, "Open Error %s\n", argv[1]);
            exit();
         }
   	 if(fstat(fd, &st) < 0){
            printf(2, "Stat Error %s\n", argv[1]);
            close(fd);
            exit();
         }
	int file = searchFile(argv[1]);
	if(file == 0) unlink(argv[1]);
	else printf(1, "There's something inside\n");
	exit();
   }
   else {
	printf(1, "Hanya bisa delete Folder\n");
	return 0;
   }
}
