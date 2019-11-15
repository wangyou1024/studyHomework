#include<stdio.h>
#include<ctype.h>
//#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	char another_game='Y';
	const unsigned int DELAY=1;
	//bool correct=ture;
	int flag=1;
	unsigned int tries=0;
	unsigned int digits=0;
	time_t seed=0;
	unsigned int number=0;
	time_t wait_start=0;
	clock_t start_time=0;
	unsigned int score=0;
	unsigned int total_digits=0;
	unsigned int game_time=0;
	unsigned int i;
	printf("\nTo play Simple Simon,  ");
	printf("watch the screen for a sequence of digits.");
	printf("\nWatch carefully, as the digits are only displayed"
		"for %u second%s",DELAY,DELAY>1?"%s":"!");
	printf("\nThe computer will remove them, and then prompt you");
	printf("to enter the same sequence.");
	printf("\nWhen you do, you must put spaces between the digits.\n");
	printf("\nGood Luck!\nPress Enter to play\n");
	scanf("%c",&another_game);
	do
	{ 
		//correct=ture;
		flag=1;
		tries=0;
		digits=2;
		start_time=clock();
		while(flag)
		{
			++tries;
			wait_start=clock();
			srand(time(&seed));
			for(i=1;i<=digits;++i)
				printf("%u ",rand()%10);
			for(;clock()-wait_start < DELAY*CLOCKS_PER_SEC;);
			printf("\r");
			for(i=1;i<=digits;++i)
				printf("  ");
			if(tries==1)
				printf("\nNow you enter the sequence-don't forget"
				" the spaces\n");
			else
				printf("\r");
			srand(seed);
			for(i=1;i<=digits;++i)
			{
				scanf("%u",&number);
				if(number != rand()%10)
				{
					//correct=false;
					flag=0;
					break;
				}
			}
			if(flag && ((tries%3)==0))
				++digits;
			printf("%s\n",flag?"Correct!":"Wrong!");
		}
	score=10*(digits-((tries%3)==1));
	total_digits=digits*(((tries%3)==0)?3:tries%3);
	if(digits>2)
		total_digits+=3*((digits-1)*(digits-2)/2-1);
	game_time=(clock()-start_time)/CLOCKS_PER_SEC-tries*DELAY;
	if(total_digits>game_time)
		score+=10*(game_time-total_digits);
	printf("\n\nGame time was %u seconds. Your score is %u",game_time,score);
	fflush(stdin);
	printf("\nDo you want to play again (y/n)?");
	scanf("%c",another_game);
	}while(toupper(another_game)=='Y');
	return 0;
}