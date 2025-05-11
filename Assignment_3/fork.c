	#include<stdio.h>
       #include <sys/types.h>
       #include <unistd.h>
       #include <stdlib.h>

int main(){
 
 int ret;
 int ret1;

   ret = fork();
   if(ret<0) {perror("error in pipe"); exit(2); } 
   
  if (ret == 0 ){
  
     printf("I'm in Child process pid: %d, ppid:%d\n", getpid(),getppid());
     while(1);
      
   
  
  }  
   
  
 else  if (ret > 0){
 
     printf("I'm in Parent procss pid: %d, ppid;%d\n",getpid(),getppid());
     while(1);
     
     
     ret1 = fork();
     
     if (ret1 == 0 ){
     if(ret1<0) {perror("error in pipe"); exit(2); } 
     printf("I'm in Child process pid: %d, ppid:%d\n", getpid(),getppid());
     while(1);
     
     }
     
   }
 
  printf("Failed to create child");
  return 0;
}
