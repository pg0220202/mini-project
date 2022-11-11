#include<stdio.h>
#include<conio.h>
 void main()
 {
 	int a[5];
 	int i,j,temp;
 	for(i=0;i<5;i++)
 	{
 		scanf("%d\n",&a[i]);
	 }
 	for(i=0;i<5;i++)
 	{
 		for(j=i+1;j<5;j++)
 		{
 			if (a[j]>a[i])
 			{
 				temp=a[i];
 				a[i]=a[j];
 				a[j]=temp;
 				
			 }
		 }
	 }
 	printf("sorted element list: \n");
 	for(i=0;i<6;i++)
 	{
 		printf("%d\n",a[i]);
	 }
 	
 }
