#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LF 10 /* ASCII code for LINE FEED character */

int scoresheet(int ai_score, int user_score)
{
	printf("\n\nOur scoresheet:\n");
	printf("===================================\n");
	printf("My score     Your score\n");
	printf("%d          %d\n", ai_score, user_score);
	
	return 0;
}

int roll_a_dice()
{
	int random = rand();
	return (1 + (random % 6));
}

int calculate_score(int dice1, int dice2, int dice3, int dice4, int dice5, int dice6)
{
	// initialize variables
	int score = 0;
	int counter_1 = 0;
	int counter_2 = 0;
	int counter_3 = 0;
	int counter_4 = 0;
	int counter_5 = 0;
	int counter_6 = 0;
	
	// count the dices
	if (dice1 == 1) counter_1++; if (dice2 == 1) counter_1++; if (dice3 == 1) counter_1++; if (dice4 == 1) counter_1++; if (dice5 == 1) counter_1++; if (dice6 == 1) counter_1++;
	if (dice1 == 2) counter_2++; if (dice2 == 2) counter_2++; if (dice3 == 2) counter_2++; if (dice4 == 2) counter_2++; if (dice5 == 2) counter_2++; if (dice6 == 2) counter_2++;
	if (dice1 == 3) counter_3++; if (dice2 == 3) counter_3++; if (dice3 == 3) counter_3++; if (dice4 == 3) counter_3++; if (dice5 == 3) counter_3++; if (dice6 == 3) counter_3++;
	if (dice1 == 4) counter_4++; if (dice2 == 4) counter_4++; if (dice3 == 4) counter_4++; if (dice4 == 4) counter_4++; if (dice5 == 4) counter_4++; if (dice6 == 4) counter_4++;
	if (dice1 == 5) counter_5++; if (dice2 == 5) counter_5++; if (dice3 == 5) counter_5++; if (dice4 == 5) counter_5++; if (dice5 == 5) counter_5++; if (dice6 == 5) counter_5++;
	if (dice1 == 6) counter_6++; if (dice2 == 6) counter_6++; if (dice3 == 6) counter_6++; if (dice4 == 6) counter_6++; if (dice5 == 6) counter_6++; if (dice6 == 6) counter_6++;
	
	// count the score
	if (counter_2 == 3) score += 200; if (counter_3 == 3) score += 300; if (counter_4 == 3) score += 400; if (counter_6 == 3) score += 600;
	if (counter_2 == 6) score += 1000; if (counter_3 == 6) score += 1000; if (counter_4 == 6) score += 1000; if (counter_5 == 6) score += 1000; if (counter_6 == 6) score += 1000;
	
	if ((counter_1 >= 3) && (counter_1 < 6))
	{
		score += 1000;
		counter_1 -= 3;
	}
	
	if ((counter_5 >= 3) && (counter_5 < 6))
	{
		score += 500;
		counter_5 -= 3;
	}
	
	if ((counter_1 == 1) && (counter_2 == 1) && (counter_3 == 1) && (counter_4 == 1) && (counter_5 == 1) && (counter_6 == 1)) score += 1500;
	
	score += (50 * counter_5) + (100 * counter_1);

	return score;
	
}

int play_user()
{
	int dice1 = roll_a_dice();
	int dice2 = roll_a_dice();
	int dice3 = roll_a_dice();
	int dice4 = roll_a_dice();
	int dice5 = roll_a_dice();
	int dice6 = roll_a_dice();
	int temp_dice1, temp_dice2, temp_dice3, temp_dice4, temp_dice5, temp_dice6;
	int roll_dice1, roll_dice2, roll_dice3, roll_dice4, roll_dice5, roll_dice6;
	int cant_roll_dice1 = 0;
	int cant_roll_dice2 = 0;
	int cant_roll_dice3 = 0;
	int cant_roll_dice4 = 0;
	int cant_roll_dice5 = 0;
	int cant_roll_dice6 = 0;
	int num_to_add, final_score;
	int reset_loop;
	char answer_continue, roll_dice;
	
	printf("\nYour Turn:\n");
	printf("===================================\n");
	printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d [Dice 4]: %d [Dice 5]: %d [Dice 6]: %d\n", dice1, dice2, dice3, dice4, dice5, dice6);
	
	if (!(calculate_score(dice1, dice2, dice3, dice4, dice5, dice6)))
	{
		printf("ZONK!\n");
		return 0;
	}
	
	while (1)
	{
		temp_dice1 = 0; temp_dice2 = 0; temp_dice3 = 0; temp_dice4 = 0; temp_dice5 = 0; temp_dice6 = 0;
		roll_dice1 = 0; roll_dice2 = 0; roll_dice3 = 0; roll_dice4 = 0; roll_dice5 = 0; roll_dice6 = 0;
		reset_loop = 0;
		printf("Do you want to continue? / Do you want to roll the dices again? (Y/N) ");
		scanf(" %c", &answer_continue);
		if (answer_continue == 121 || answer_continue == 89)
		{
			printf("Which ones you want to roll again? ");
			scanf(" %c", &roll_dice);
			while(roll_dice != LF)
			{
				if (roll_dice < 55 && roll_dice > 48) num_to_add = roll_dice - 48;
				else if (!(roll_dice == 32))
				{
					printf("%c is invalid!\n", roll_dice);
					system("pause");
					reset_loop = 1;
				}
				if (num_to_add == 1) roll_dice1 = 1;
				if (num_to_add == 2) roll_dice2 = 1;
				if (num_to_add == 3) roll_dice3 = 1;
				if (num_to_add == 4) roll_dice4 = 1;
				if (num_to_add == 5) roll_dice5 = 1;
				if (num_to_add == 6) roll_dice6 = 1;
				scanf("%c", &roll_dice);
			}
			
			if ((roll_dice1 && cant_roll_dice1) || (roll_dice2 && cant_roll_dice2) || (roll_dice3 && cant_roll_dice3) || (roll_dice4 && cant_roll_dice4) || (roll_dice5 && cant_roll_dice5) || (roll_dice6 && cant_roll_dice6))
			{
				printf("You choose a dice that you cant reroll!\n");
				reset_loop = 1;
			}
			
			if (roll_dice1 && roll_dice2 && roll_dice3 && roll_dice4 && roll_dice5 && roll_dice6)
			{
				printf("You cant reroll all dices!\n");
				reset_loop = 1;
			}
			
			if (reset_loop > 0) continue;
			
			if (roll_dice1) temp_dice1 = roll_a_dice();
			if (roll_dice2) temp_dice2 = roll_a_dice();
			if (roll_dice3) temp_dice3 = roll_a_dice();
			if (roll_dice4) temp_dice4 = roll_a_dice();
			if (roll_dice5) temp_dice5 = roll_a_dice();
			if (roll_dice6) temp_dice6 = roll_a_dice();
			
			if (!(roll_dice1)) cant_roll_dice1 = 1;
			if (!(roll_dice2)) cant_roll_dice2 = 1;
			if (!(roll_dice3)) cant_roll_dice3 = 1;
			if (!(roll_dice4)) cant_roll_dice4 = 1;
			if (!(roll_dice5)) cant_roll_dice5 = 1;
			if (!(roll_dice6)) cant_roll_dice6 = 1;
			
			printf("You got --> ");
			
			if (roll_dice1) printf("[Dice 1]: %d ", temp_dice1);
			if (roll_dice2) printf("[Dice 2]: %d ", temp_dice2);
			if (roll_dice3) printf("[Dice 3]: %d ", temp_dice3);
			if (roll_dice4) printf("[Dice 4]: %d ", temp_dice4);
			if (roll_dice5) printf("[Dice 5]: %d ", temp_dice5);
			if (roll_dice6) printf("[Dice 6]: %d ", temp_dice6);
			
			printf("\n");
			
			if (!(calculate_score(temp_dice1, temp_dice2, temp_dice3, temp_dice4, temp_dice5, temp_dice6)))
			{
				printf("ZONK!\n");
				return 0;
			}
			
			if (roll_dice1) dice1 = temp_dice1;
			if (roll_dice2) dice2 = temp_dice2;
			if (roll_dice3) dice3 = temp_dice3;
			if (roll_dice4) dice4 = temp_dice4;
			if (roll_dice5) dice5 = temp_dice5;
			if (roll_dice6) dice6 = temp_dice6;
		}
		else if (answer_continue == 110 || answer_continue == 78)
		{
			final_score = calculate_score(dice1, dice2, dice3, dice4, dice5, dice6);
			printf("Your score: %d\n", final_score);
			return final_score;
			break;
		}
		else
		{
			printf("Wrong choice!\n");
		}
	}
}

int computer_strategy_decider(int dice1, int dice2, int dice3, int dice4, int dice5, int dice6, int score)
{
	// initialize variables
	int counter_1 = 0;
	int counter_2 = 0;
	int counter_3 = 0;
	int counter_4 = 0;
	int counter_5 = 0;
	int counter_6 = 0;
	
	int reroll_dice1 = 0;
	int reroll_dice2 = 0;
	int reroll_dice3 = 0;
	int reroll_dice4 = 0;
	int reroll_dice5 = 0;
	int reroll_dice6 = 0;
	
	int zero_counter = 0;
	
	// count the dices
	if (dice1 == 1) counter_1++; if (dice2 == 1) counter_1++; if (dice3 == 1) counter_1++; if (dice4 == 1) counter_1++; if (dice5 == 1) counter_1++; if (dice6 == 1) counter_1++;
	if (dice1 == 2) counter_2++; if (dice2 == 2) counter_2++; if (dice3 == 2) counter_2++; if (dice4 == 2) counter_2++; if (dice5 == 2) counter_2++; if (dice6 == 2) counter_2++;
	if (dice1 == 3) counter_3++; if (dice2 == 3) counter_3++; if (dice3 == 3) counter_3++; if (dice4 == 3) counter_3++; if (dice5 == 3) counter_3++; if (dice6 == 3) counter_3++;
	if (dice1 == 4) counter_4++; if (dice2 == 4) counter_4++; if (dice3 == 4) counter_4++; if (dice4 == 4) counter_4++; if (dice5 == 4) counter_4++; if (dice6 == 4) counter_4++;
	if (dice1 == 5) counter_5++; if (dice2 == 5) counter_5++; if (dice3 == 5) counter_5++; if (dice4 == 5) counter_5++; if (dice5 == 5) counter_5++; if (dice6 == 5) counter_5++;
	if (dice1 == 6) counter_6++; if (dice2 == 6) counter_6++; if (dice3 == 6) counter_6++; if (dice4 == 6) counter_6++; if (dice5 == 6) counter_6++; if (dice6 == 6) counter_6++;
	
	if (dice1 == 0) zero_counter++; if (dice2 == 0) zero_counter++; if (dice3 == 0) zero_counter++; if (dice4 == 0) zero_counter++; if (dice5 == 0) zero_counter++; if (dice6 == 0) zero_counter++;
	
	if ((counter_1 == 1) && (counter_2 == 1) && (counter_3 == 1) && (counter_4 == 1) && (counter_5 == 1) && (counter_6 == 1)) return 0;
	if ((counter_1 == 6) || (counter_2 == 6) || (counter_3 == 6) || (counter_4 == 6) || (counter_5 == 6) || (counter_6 == 6)) return 0;
	if (zero_counter >= 2 && score >= 150) return 0;
	if (score >= 400) return 0;
	
	// begin 2
	if (counter_2 < 3)
	{
		if (dice1 == 2) reroll_dice1 = 1;
		if (dice2 == 2) reroll_dice2 = 1;
		if (dice3 == 2) reroll_dice3 = 1;
		if (dice4 == 2) reroll_dice4 = 1;
		if (dice5 == 2) reroll_dice5 = 1;
		if (dice6 == 2) reroll_dice6 = 1;
	}
	else if (counter_2 == 5)
	{
		if (dice1 == 2)
		{
			reroll_dice1 = 1;
			dice1 = 0;
		}
		else if (dice2 == 2)
		{
			reroll_dice2 = 1;
			dice2 = 0;
		}
		else if (dice3 == 2)
		{
			reroll_dice3 = 1;
			dice3 = 0;
		}
		else if (dice4 == 2)
		{
			reroll_dice4 = 1;
			dice4 = 0;
		}
		else if (dice5 == 2)
		{
			reroll_dice5 = 1;
			dice5 = 0;
		}
		else if (dice6 == 2)
		{
			reroll_dice6 = 1;
			dice6 = 0;
		}
		counter_2--;
	}
	else if (counter_2 == 4)
	{
		if (dice1 == 2) reroll_dice1 = 1;
		else if (dice2 == 2) reroll_dice2 = 1;
		else if (dice3 == 2) reroll_dice3 = 1;
		else if (dice4 == 2) reroll_dice4 = 1;
		else if (dice5 == 2) reroll_dice5 = 1;
		else if (dice6 == 2) reroll_dice6 = 1;
	}
	// end 2

	// begin 3
	if (counter_3 < 3)
	{
		if (dice1 == 3) reroll_dice1 = 1;
		if (dice2 == 3) reroll_dice2 = 1;
		if (dice3 == 3) reroll_dice3 = 1;
		if (dice4 == 3) reroll_dice4 = 1;
		if (dice5 == 3) reroll_dice5 = 1;
		if (dice6 == 3) reroll_dice6 = 1;
	}
	else if (counter_3 == 5)
	{
		if (dice1 == 3)
		{
			reroll_dice1 = 1;
			dice1 = 0;
		}
		else if (dice2 == 3)
		{
			reroll_dice2 = 1;
			dice2 = 0;
		}
		else if (dice3 == 3)
		{
			reroll_dice3 = 1;
			dice3 = 0;
		}
		else if (dice4 == 3)
		{
			reroll_dice4 = 1;
			dice4 = 0;
		}
		else if (dice5 == 3)
		{
			reroll_dice5 = 1;
			dice5 = 0;
		}
		else if (dice6 == 3)
		{
			reroll_dice6 = 1;
			dice6 = 0;
		}
		counter_3--;
	}
	else if (counter_3 == 4)
	{
		if (dice1 == 3) reroll_dice1 = 1;
		else if (dice2 == 3) reroll_dice2 = 1;
		else if (dice3 == 3) reroll_dice3 = 1;
		else if (dice4 == 3) reroll_dice4 = 1;
		else if (dice5 == 3) reroll_dice5 = 1;
		else if (dice6 == 3) reroll_dice6 = 1;
	}
	// end 3

	// begin 4
	if (counter_4 < 3)
	{
		if (dice1 == 4) reroll_dice1 = 1;
		if (dice2 == 4) reroll_dice2 = 1;
		if (dice3 == 4) reroll_dice3 = 1;
		if (dice4 == 4) reroll_dice4 = 1;
		if (dice5 == 4) reroll_dice5 = 1;
		if (dice6 == 4) reroll_dice6 = 1;
	}
	else if (counter_4 == 5)
	{
		if (dice1 == 4)
		{
			reroll_dice1 = 1;
			dice1 = 0;
		}
		else if (dice2 == 4)
		{
			reroll_dice2 = 1;
			dice2 = 0;
		}
		else if (dice3 == 4)
		{
			reroll_dice3 = 1;
			dice3 = 0;
		}
		else if (dice4 == 4)
		{
			reroll_dice4 = 1;
			dice4 = 0;
		}
		else if (dice5 == 4)
		{
			reroll_dice5 = 1;
			dice5 = 0;
		}
		else if (dice6 == 4)
		{
			reroll_dice6 = 1;
			dice6 = 0;
		}
		counter_4--;
	}
	else if (counter_4 == 4)
	{
		if (dice1 == 4) reroll_dice1 = 1;
		else if (dice2 == 4) reroll_dice2 = 1;
		else if (dice3 == 4) reroll_dice3 = 1;
		else if (dice4 == 4) reroll_dice4 = 1;
		else if (dice5 == 4) reroll_dice5 = 1;
		else if (dice6 == 4) reroll_dice6 = 1;
	}
	// end 4

	// begin 6
	if (counter_6 < 3)
	{
		if (dice1 == 6) reroll_dice1 = 1;
		if (dice2 == 6) reroll_dice2 = 1;
		if (dice3 == 6) reroll_dice3 = 1;
		if (dice4 == 6) reroll_dice4 = 1;
		if (dice5 == 6) reroll_dice5 = 1;
		if (dice6 == 6) reroll_dice6 = 1;
	}
	else if (counter_6 == 5)
	{
		if (dice1 == 6)
		{
			reroll_dice1 = 1;
			dice1 = 0;
		}
		else if (dice2 == 6)
		{
			reroll_dice2 = 1;
			dice2 = 0;
		}
		else if (dice3 == 6)
		{
			reroll_dice3 = 1;
			dice3 = 0;
		}
		else if (dice4 == 6)
		{
			reroll_dice4 = 1;
			dice4 = 0;
		}
		else if (dice5 == 6)
		{
			reroll_dice5 = 1;
			dice5 = 0;
		}
		else if (dice6 == 6)
		{
			reroll_dice6 = 1;
			dice6 = 0;
		}
		counter_6--;
	}
	else if (counter_6 == 4)
	{
		if (dice1 == 6) reroll_dice1 = 1;
		else if (dice2 == 6) reroll_dice2 = 1;
		else if (dice3 == 6) reroll_dice3 = 1;
		else if (dice4 == 6) reroll_dice4 = 1;
		else if (dice5 == 6) reroll_dice5 = 1;
		else if (dice6 == 6) reroll_dice6 = 1;
	}
	// end 6
	
	int reroll_counter = 0;
	
	int final = 1;
	final *= 10;
	if (reroll_dice1 == 1) 
	{
		reroll_counter++;
		final++;
	}
	final *= 10;
	if (reroll_dice2 == 1) 
	{
		reroll_counter++;
		final++;
	}
	final *= 10;
	if (reroll_dice3 == 1) 
	{
		reroll_counter++;
		final++;
	}
	final *= 10;
	if (reroll_dice4 == 1) 
	{
		reroll_counter++;
		final++;
	}
	final *= 10;
	if (reroll_dice5 == 1) 
	{
		reroll_counter++;
		final++;
	}
	final *= 10;
	if (reroll_dice6 == 1) 
	{
		reroll_counter++;
		final++;
	}
	
	if (reroll_counter <3) return 0;
	else return final;
}

int play_computer()
{
	int dice1 = roll_a_dice();
	int dice2 = roll_a_dice();
	int dice3 = roll_a_dice();
	int dice4 = roll_a_dice();
	int dice5 = roll_a_dice();
	int dice6 = roll_a_dice();
	int temp_dice1, temp_dice2, temp_dice3, temp_dice4, temp_dice5, temp_dice6;
	int roll_dice1, roll_dice2, roll_dice3, roll_dice4, roll_dice5, roll_dice6;
	int num_to_add, final_score, strategy;
	char answer_continue, roll_dice;
	
	printf("\nMy Turn:\n");
	printf("===================================\n");
	printf("I got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d [Dice 4]: %d [Dice 5]: %d [Dice 6]: %d\n", dice1, dice2, dice3, dice4, dice5, dice6);
	
	if (!(calculate_score(dice1, dice2, dice3, dice4, dice5, dice6)))
	{
		printf("ZONK!\n");
		return 0;
	}
	
	strategy = computer_strategy_decider(dice1, dice2, dice3, dice4, dice5, dice6, calculate_score(dice1, dice2, dice3, dice4, dice5, dice6));
	if (strategy == 1) strategy = 0;
	while (strategy != 0)
	{
		temp_dice1 = 0; temp_dice2 = 0; temp_dice3 = 0; temp_dice4 = 0; temp_dice5 = 0; temp_dice6 = 0;
		roll_dice1 = 0; roll_dice2 = 0; roll_dice3 = 0; roll_dice4 = 0; roll_dice5 = 0; roll_dice6 = 0;
	
		roll_dice6 = strategy % 10;
		strategy /= 10;
		roll_dice5 = strategy % 10;
		strategy /= 10;
		roll_dice4 = strategy % 10;
		strategy /= 10;
		roll_dice3 = strategy % 10;
		strategy /= 10;
		roll_dice2 = strategy % 10;
		strategy /= 10;
		roll_dice1 = strategy % 10;
		strategy /= 10;
			
		if (roll_dice1) temp_dice1 = roll_a_dice();
		if (roll_dice2) temp_dice2 = roll_a_dice();
		if (roll_dice3) temp_dice3 = roll_a_dice();
		if (roll_dice4) temp_dice4 = roll_a_dice();
		if (roll_dice5) temp_dice5 = roll_a_dice();
		if (roll_dice6) temp_dice6 = roll_a_dice();
		
		if (roll_dice1 || roll_dice2 || roll_dice3 || roll_dice4 || roll_dice5 || roll_dice6)
		{
			printf("Kept dice ");
			if (!(roll_dice1)) printf("1 ");
			if (!(roll_dice2)) printf("2 ");
			if (!(roll_dice3)) printf("3 ");
			if (!(roll_dice4)) printf("4 ");
			if (!(roll_dice5)) printf("5 ");
			if (!(roll_dice6)) printf("6 ");
			printf("and Rolled");
			if (roll_dice1) printf(" 1");
			if (roll_dice2) printf(" 2");
			if (roll_dice3) printf(" 3");
			if (roll_dice4) printf(" 4");
			if (roll_dice5) printf(" 5");
			if (roll_dice6) printf(" 6");
			printf("\n");
		}
		
		printf("I got --> ");
		
		if (roll_dice1) printf("[Dice 1]: %d ", temp_dice1);
		if (roll_dice2) printf("[Dice 2]: %d ", temp_dice2);
		if (roll_dice3) printf("[Dice 3]: %d ", temp_dice3);
		if (roll_dice4) printf("[Dice 4]: %d ", temp_dice4);
		if (roll_dice5) printf("[Dice 5]: %d ", temp_dice5);
		if (roll_dice6) printf("[Dice 6]: %d ", temp_dice6);
			
		printf("\n");
			
		if (!(calculate_score(temp_dice1, temp_dice2, temp_dice3, temp_dice4, temp_dice5, temp_dice6)))
		{
			printf("ZONK!\n");
			return 0;
		}
		
		if (roll_dice1) dice1 = temp_dice1;
		if (roll_dice2) dice2 = temp_dice2;
		if (roll_dice3) dice3 = temp_dice3;
		if (roll_dice4) dice4 = temp_dice4;
		if (roll_dice5) dice5 = temp_dice5;
		if (roll_dice6) dice6 = temp_dice6;
			
		strategy = computer_strategy_decider(temp_dice1, temp_dice2, temp_dice3, temp_dice4, temp_dice5, temp_dice6, calculate_score(dice1, dice2, dice3, dice4, dice5, dice6));
		if (strategy == 1) strategy = 0;
	}
	
	final_score = calculate_score(dice1, dice2, dice3, dice4, dice5, dice6);
	printf("My score: %d\n", final_score);
	return final_score;
}

int main()
{
	int rounds, first_dice_ai, first_dice_user, will_play_first;
	int ai_score = 0;
	int user_score = 0;
	char answer;
	printf("Welcome to the Zonk game!\n");
	printf("How many rounds would you like to play? ");
	scanf("%d", &rounds);
	printf("OK, lets get started!\n\n");
	
	srand(time(NULL)); // seed the rand() function
	
	first_dice_ai = roll_a_dice();
	printf("I have rolled the dice and got %d!\n", first_dice_ai);

// disabled due to needlessness
/*	while (1)
	{
		printf("Are you ready to Zonk! Shall I roll the dice for you (Y/N)? ");
		scanf(" %c", &answer);
	
		if (answer == 110 || answer == 78)
		{
			printf("I cant get the values from you, so I have to roll the dice!\n");
			break;
		}
		else if(!(answer == 121 || answer == 89))
		{
			printf("Wrong choice!\n");
			continue;
		} else break;
	}
*/
	
	first_dice_user = roll_a_dice();
	printf("I have rolled the dice for you and you got %d!\n", first_dice_user);
	
	if (first_dice_user < first_dice_ai)
		will_play_first = 1;
	else if (first_dice_user > first_dice_ai)
		will_play_first = 2;
	else
	{
		while (1)
		{
			printf("We need to roll the dices again!\n");
			
			first_dice_ai = roll_a_dice();
			printf("I have rolled the dice and got %d!\n", first_dice_ai);
			
			first_dice_user = roll_a_dice();
			printf("I have rolled the dice for you and you got %d!\n", first_dice_user);
			
			if (first_dice_user < first_dice_ai)
			{
				will_play_first = 1;
				break;
			}
			else if (first_dice_user > first_dice_ai)
			{
				will_play_first = 2;
				break;
			}
		}
	}

	int round_counter = 0;
	
	while (round_counter < (rounds * 2))
	{
		switch (will_play_first)
		{
			case 1:
				ai_score += play_computer();
				round_counter++;
				if (round_counter % 2 == 0) scoresheet(ai_score, user_score);
				if (round_counter >= (rounds * 2)) break;
			case 2:
				user_score += play_user();
				round_counter++;
				if (round_counter % 2 == 0) scoresheet(ai_score, user_score);
			default:
				will_play_first = 1; // reset the value
		}
	}
	
	if (ai_score > user_score) printf("\n\nI AM THE WINNER !\n");
	else if (ai_score < user_score) printf("\n\nYOU ARE THE WINNDER !\n");
	else printf("\n\nDRAW !\n");
	system("pause");
	
	return 0;
}
