//count words, lines and chars in a file by breaking into chuncks
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


void * wordCount(void *arg)
{
    FILE *fp=(FILE *) arg;
    int fd=fileno(fp);
    printf("File descriptor:%d\n",fd);
}

int main(void)
{
 char fileName[]="myFile.txt";
 FILE *fp=fopen(fileName,"r");
 struct stat st;
 int size;
 int fd;
 int displacement=0;
 pthread_t pids[];
 if(fp==NULL)
 {
   printf("Error in opening the file\n");
   return 1;
 }
 fd=fileno(fp);
 fstat(fd, &st);
 size=st.st_size;


 int chuncks=size/1024; //breaking into 1kb chuncks.
 fclose(fp);

 FILE *fps[]=(FILE)(MALLOC)malloc((FILE *)sizeof(FILE*));
  printf("file size:%d\n",size);


 for(int i=0;i<chuncks;i++){
   fps[i]=fopen(fileName,"r"); 
   fseek(fps[i],displacement,SEEK_BEG);
   displacement+=1024;
 }

 for(int i=0;i<chuncks;i++)
   pthread_create(pids[i],&wordCount,(void *)fps[i]);

 pthread_join(pids[chuncks-1]);    

}
