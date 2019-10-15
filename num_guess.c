#include <stdlib.h> 
 #include <stdio.h> 
 #include <time.h>
 int main( void ) 
 {
   
   int num; //answer
   int n ;   
   int times = 0;  //chance
   int high;   // range max
   int low;    // range min 
   low= 1;
   high= 100;
   srand(time(NULL));
   num = rand()%100+1;
   for(times=10;times>=1;times--)      // max chance is 10 
  {
            printf("Please input a number:\n");
            scanf("%d",&n);
       if(n==num)
      {
       printf("you are right\n");
       break;
       }
   
       if(n>num)
              {
              high=n;
              printf("range is %d to %d\n",low,high);
              }
       if(n<num)
             {
              low=n;
              printf("range is %d to %d\n",low,high);
             }
       printf("your chance are  %d\n",times);
      }
                
                 return 0;
   }
