#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
pid_t A,B,C;

printf("P0\n"); //travail de p�re

A=fork();
if(A==-1)
printf("erreur de cr�ation.");//afficher message d'echouer le cr�ation
else if(A==0)              //cr�ation de fils 1
   {
   printf("P1\n");         //task P1
   B=fork();             //cr�ation le sous fils 1 de P1 
  if(B==-1)
    printf("erreur de creation.");//afficher message d'echouer le cr�ation
     else if(B==0)                    //cr�ation de sous fils pour P4
      {
      printf("P4\n");          //task P4
      exit(0); 
	  }
   else             // le fils P1 travail et faire task P5
      {  
        printf("P5\n");        //task P5
     waitpid(B,NULL,0);    //le sous fils P5 attend de terminer le fils P1
     exit(0); 
	 }
    
   }
else                          //travail de processus p�re
   {
   C=fork();
    if(C==-1)
    printf("erreur de creation."); //afficher message d'echouer le cr�ation
   else if(C==0)                    //cr�ation un fils 3 pour faire task P2 et P6
      {
      printf("P2\n");              //task p2
      printf("P6\n");             //task p6
    exit(0); 
	}
   else                             // le p�re fair task p3
      {
        printf("P3\n");            //task p3
        waitpid(C,NULL,0);  //le processus p�re  attend la termine de fils 3
         waitpid(A,NULL,0);  //le processus p�re attend la termine de fils 1
       printf("P7\n");             //task P7
  
       
      }



   }
 
return 0;
}
