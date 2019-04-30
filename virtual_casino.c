#include <stdio.h>
#include <stdlib.h>

void main()
{
	char* c;
	int bal = 100;
	int bet = 0;
	int bet_card = 0;
	int random;

	printf("\n -------Virtual Casino------- \n");

	while(bal > 0)
	{
		c = (char*) malloc(sizeof(char));
		c[0] = 'J'; c[1] = 'Q'; c[2] = 'K';
		start:
		printf("\n Current balence :: %d ",bal);
		printf("\n Enter amount to bet :: ");
		scanf(" %d",&bet);
		if(bal < bet)
			{
				printf("\n You cannot bet more than balance ::");
				goto start;
			}
		else 
		{
		random = rand() % 2 + 0;
		printf("\n Enter Card to bet on \n 0 for J \n 1 for Q \n 2 for K \n :: ");
	
		scanf(" %d",&bet_card);
		if(bet_card == random)
		{
			bal = bal + (bet*2);
			printf("\n You win :");
		}
		else
		{
			bal = bal - bet;
			printf("\n You Loose :");
		}
		printf("---- Sequence was :: %d %d %d",
		free(c);
		}
	}
			
}
