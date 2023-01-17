#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n,pl_s=0,cmp_s=0,tie_count=0,i=1;
	char pl,r='r',s='s',p='p';
	
	printf("enter the number of times you want to play:");
	scanf("%d",&n);
	
	while(i<=n)
	{
		printf("enter the your choice from the ROCK SCISSORS PAPER : ");
		scanf(" %c",&pl);
		
		srand(time(NULL));
		char comp=rand()%3;
		
		if(comp=='r')
		{
			if(pl=='r')
			{
				tie_count++;
				printf("it is the tie\n");
				printf("the computer had also choosen the same so it is tie\n");
			}
			else if(pl=='s')
			{
				printf("***you are the winner****\n");
				pl_s++;
				printf("the computer has choosen the rock\n");
				printf("since the scissors can break the rock so there is no more rock\n");
			}
			else
			{
				printf("**the computer is the winner**\n");
				printf("since the computer has chosen the ***rock**so:\n");
				printf("the rock can cover the paper then there is no paper can seen\n");
				cmp_s++;
			}
		}
		else if(comp=='s')
		{
			if(pl=='s')
			{
				tie_count++;
				printf("it is the tie\n");
				printf("the computer had also choosen the same so it is tie\n");
			}
			else if(pl=='p')
			{
				printf("***you are the winner****\n");
				pl_s++;
				printf("the computer has choosen the scissors\n");
				printf("since the paper can cover the scissors so there is no more scissors\n");
			}
			else
			{
				printf("**the computer is the winner **\n");
				printf("**since computer has choosen **scissors** so:\n");
				printf("** the rock can break the scissors so there is no more scissors** \n");
				cmp_s++;
			}
		}
		else
		{
			if(pl=='p')
			{
				tie_count++;
				printf("it is the tie\n");
				printf("the computer had also choosen the same so it is tie\n");
			}
			else if(pl=='r')
			{
				printf("***you are the winner****\n");
				pl_s++;
				printf("the computer has choosen the paper\n");
				printf("since the rock can break the paper then there is no paper can seen  \n");
			}
			else
			{
				printf("**the computer is the winner **\n");
				printf("****the computer choosen ***paper*** so:\n");
				printf("*** the scissors can cut the paper then there is no paper** \n");
				cmp_s++;
			}
		}
		i++;
	}
	
	if(n<i)
	{
		printf("the user score is %d\n",pl_s);
		printf("the computer score is %d\n",cmp_s);
		printf("the tie count is %d \n",tie_count);
		
		if(pl_s>cmp_s)
			printf("the winner is user\n");
		else if(cmp_s==pl_s)
			printf("equal scores\n");
		else
			printf("the computer is the winner\n");
	}
	return 0;
}