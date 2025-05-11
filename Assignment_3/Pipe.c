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
   int pfd[2];
   int pfd2[2];

   //after the pipe is created, the r/w handles are passed
   //in pfd[0] and pfd[1], respectively
   ret = pipe(pfd);
   ret2 = pipe(pfd);
   

   if(ret<0) {perror("error in pipe"); exit(2); }

   ret = fork();//the parent has the handles to the pipe
                //the child also is given the handles

   if(ret<0) { };

   if(ret==0){
         
	   close(pfd[1]); //in this process, we are reading from the pipe
                          //close the write handle
   

	   while( (ret1 = read(pfd[0],buf,512)) >0)
	   {
		   //printf("%s\n", buf);
                   write(STDOUT_FILENO,buf,ret1);  
                   printf("Message Received Sucessfully \n"); 
		   //fflush(stdout);
	   }   
	   
	     while( (ret2 = read(pfd2[0],buf,512)) >0)
	   {
		   //printf("%s\n", buf);
                   write(STDOUT_FILENO,buf,ret2);  
                   printf("Message Received Sucessfully \n"); 
		   //fflush(stdout);
	   }   
	   
	   if(ret1<0){ } 
	   close(pfd[0]);
   }

   if(ret>0)
   {
      close(pfd[0]);   //we are interested in writing only
      write(pfd[1],"this is a message 1 from parent\n",33);//no formatting 
      close(pfd[1]);
      
      ret2 = fork();
      
      close(pfd2[0]);   //we are interested in writing only
      write(pfd2[1],"this is a message 2 from parent\n",33);//no formatting 
     
      close(pfd2[1]);
      
   }
   
   
   
   exit(0);

} 	 








	
