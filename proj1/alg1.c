#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
#include <sys/un.h>


int main(){
 int i, j, k;
 int m[5] = {-2, -1, 0, 1, 2};
 int b[5] = {9, 27, 54, 95, 96};
 int v[5] = {1, 1, 1, 1, 1};

 for(i=1; i<5; i++){
     for(j=0; j<i; j++){
         for(k=i+1; k<6; k++){
             if(m[j]*(b[j]-b[k])+b[j]*(m[k]-m[j])>m[i]*(b[j]-b[k])+b[i]*(m[k]-m[j])){
                 //line is not visible
                 v[i] = 0;
             }
         }
     }
 }

 printf("Visible Lines:");
 for(i=0;i<5;i++){
     printf(" %d,", v[i]);
 }
printf("\n");
return(0);
}
