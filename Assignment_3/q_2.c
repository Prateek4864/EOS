
/* In the above question extend the program to have pipe to 
    have bi-directional communication.  */
    
    
    
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char *argv[])
{

   char buf[512],wr_buf[512];	
   int ret,ret1,status;
   int ret2;
   int fd1,fd2,fd3,pfd[2];
   	   
     //in pfd[0] and pfd[1], respectively 	   
   if(ret<0) {perror("error in pipe"); exit(2); }
   ret = fork();//the parent has the handles to the pipe
   if(ret<0) { };


   if(ret==0){  //CHILD
     
     // printf("I'm in Child 2 process pid: %d, ppid:%d \n", getpid(),getppid());   
      close(pfd[0]);   //we are interested in writing only
      write(pfd[1],"1..this is a message 2 from Parent Child",33);//no formatting 
      close(pfd[1]);
   }

   if(ret > 0)  //PARENT
   {
      
   
   if(ret2==0){  //CHILD
    
   ret2 = pipe(pfd);
   if(ret2<0) {perror("error in pipe"); exit(2); } 
   ret2 = fork();
   if(ret2<0) { };
      
           close(pfd[1]); 
	   
	   while( (ret2 = read(pfd[0],buf,512)) > 0)
	   {
                   write(STDOUT_FILENO,buf,ret2);
	   }  
	   if(ret2<0){ } 
	   close(pfd[0]);
   }
   
   
   }
   
   exit(0);

} 	 








	
