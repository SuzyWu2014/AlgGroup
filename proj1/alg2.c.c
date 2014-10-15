


#include "stdio.h"
#include "stdlib.h"

int* GetVisibleLines(int* m,int* b, int n){
	
	int lines[n];
	for (int i = 0; i < n; ++i)
	{
		printf("%d   %d   \n",m[i],b[i] );
	}		
	for (int i = 0; i < n; ++i)
	{
		lines[i]=1;//assume line is visible
	}

	for (int i = 1; i < n-1; i++)
	{
		printf("i=%d\n",i );
		for (int j = 0; j < i ; j++)
		{
			//line j is visible
			if(lines[j]==1){

				printf("j=%d\n",j );
				for (int k = i+1; k < n; k++)
				{
					printf("k=%d\n",k );
					if(((b[j]-b[k])*m[i]+b[i]*(m[k]-m[j]))<(m[j]*(b[j]-b[k])+b[j]*(m[k]-m[j])))
					{
						lines[i]=0;//not visible
						printf("i=%d not visible\n",i );
						break;
					}
				}
				if(lines[i]==0)
				break;
			}
		}
	}

	return lines;
	 
}



int main(){
	//int lines[5][3];//lines[i][0]->mi, lines[1]->bi,lines[][2]=1/visible
	printf("How many lines?\n");
	int count;
	scanf("%d",&count);

	//int* m=m[count];
	//int* b=b[count];
	int m[count];
	int b[count];
	printf("Please enter integers value for m:\n");		
	for (int i = 0; i < count; ++i)
	{
		scanf("%d",&m[i]);
	}	



	printf("Please enter integers value for b:\n");		
	for (int i = 0; i < count; ++i)
	{
		scanf("%d",&b[i]);
	}	

	int*  l=GetVisibleLines(m,b,count);
	//GetVisibleLines(lines,count);
	printf("Those are visible lines:\n");
	for (int i = 0; i < count; ++i)
	{
		//if(lines[i]==1)
			printf("%d  \n", l[i]);
	}

	//FreeArray(lines,count);

}
