/* Create a program, have 2 child created from the parent
    process and establish pipe ipc between 2 childs. */

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
   int ret2,ret21,status2;
   int pfd[2],pfd1[2];

   //after the pipe is created, the r/w handles are passed
   //in pfd[0] and pfd[1], respectively
   ret = pipe(pfd);

   if(ret<0) {perror("error in pipe"); exit(2); }
   ret = fork();//the parent has the handles to the pipe
   if(ret<0) { };
   
   


   if(ret==0){ //child
           
       close(pfd[1]); //in this process, we are reading from the pipe

	   while( (ret1  = read(pfd[0],buf,512)) >0)
	   {
		   //printf("%s\n", buf);
                   write(STDOUT_FILENO,buf,ret1);
             
		   //fflush(stdout);
	   }  
	   
	   
	      close(pfd1[1]);
	      
	      while( (ret2 = read(pfd1[0],buf,512)) >0)
	   {
		   //printf("%s\n", buf);
                    write(STDOUT_FILENO,buf,ret2);
		   //fflush(stdout);
	   }  
	   
	   
	   if(ret1<0){ } 
	    if(ret21<0){ } 
	   close(pfd1[0]);
      
   }

   if(ret>0) //partent
   {
      
       //  printf("I'm in Child process 1 pid: %d, ppid:%d\n", getpid(),getppid());     
      close(pfd[0]);   //we are interested in writing only
      write(pfd[1],"1..this is a message 1 from parent\n",33);//no formatting 
      close(pfd[1]);
      
      
     if(ret2<0) { perror("error in pipe"); exit(2); } 
     ret2 = fork();
     ret2 = pipe(pfd1);
     if(ret2<0) { };
     
     // printf("I'm in Child process 2 pid: %d, ppid:%d\n", getpid(),getppid());
	
      close(pfd1[0]);   //we are interested in writing only
      write(pfd1[1],"1..this is a message 2 from parent\n",33);//no formatting 
      close(pfd1[1]);

   }
   
   exit(0);

} 	 








	
