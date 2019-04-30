#include <stdio.h>

struct subjects
{
	char name_sub[10];
	float credit;
	int marks;
};

int main()
{
	struct subjects s[6];
	float spi = 0;
	int i;
	int credit_sum=0;
	for(i=0;i<6;i++)
	{
		printf("\n Enter info of subject %d \n",(i+1));		
		printf("Enter subject name \n");
		scanf(" %s",s[i].name_sub);
		printf("Enter credits given to subject \n");
		scanf(" %f",&s[i].credit);
		printf("Enter marks scored in subject (out of 10) \n");
		scanf(" %d",&s[i].marks);
		
	}
	for(i=0;i<6;i++)
	{
		
		credit_sum = (credit_sum + s[i].credit);
	}
	for(i=0;i<6;i++)
	{
		
		spi = spi + (s[i].credit * s[i].marks);
	}
	printf("SPI Scored is %f",(spi/credit_sum));
	return 0;
}


	
