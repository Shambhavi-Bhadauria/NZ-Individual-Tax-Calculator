#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include<stdio.h>
#include <stdlib.h>


int main(void)
{
	char response[5];
	char name[50];
	float annual_income, another_income, take_home, secondary_tax;
	float cojoint_income;

	/*user's name input & income*/
	printf("Please enter your name: ");
	scanf("%s", &name);
	printf("Please enter your annual income before tax: ");
	scanf("%f", &annual_income);

	float amount[5] = { 0, 0, 0, 0, 0 };
	float brackets[5] = { 14000, 48000, 70000, 180000 };
	float tax[5] = { 0.0,0,0,0,0 };
	

	/*loop for income*/
	for (int i = 0; i < annual_income; i++)
	{
		if (i < brackets[0])
		{
			amount[0] += 1;
		}
		else if (i < brackets[1])
		{
			amount[1] += 1;
		}
		else if (i < brackets[2])
		{
			amount[2] += 1;
		}
		else if (i < brackets[3])
		{
			amount[3] += 1;
		}
		else
		{
			amount[4] += 1;
		}
	}

	/*Calculating tax*/
	tax[0] = (amount[0] * 0.105f);
	tax[1] = (amount[1] * 0.175f);
	tax[2] = (amount[2] * 0.3f);
	tax[3] = (amount[3] * 0.33f);
	tax[4] = (amount[4] * 0.33f);

	/*Calculate total tax*/
	float total_tax = tax[0] + tax[01] + tax[2] + tax[3] + tax[4];

	/*Take home pay & percentage*/
	take_home = annual_income - total_tax;
	float take_home_percentage = take_home / annual_income * 100;



	printf("Do you have the secondary income, %s", name);
	printf("? ");
	scanf("%s", response);
	if (strcmp(response, "y") == 0) {
		printf("What is your total annual income from other source, %s", name);
		printf("? ");
		scanf("%f", &another_income);

		if (another_income < 14000)
			secondary_tax = another_income * 0.105f;
		else if
			(another_income < 48000)
			secondary_tax = another_income * 0.175f;
		else if
			(another_income < 70000)
			secondary_tax = another_income * 0.30f;
		else if
			(another_income < 180000)
			secondary_tax = another_income * 0.33f;
		else
			(another_income > 180000);
		secondary_tax = another_income * 0.39f;

		cojoint_income = annual_income + another_income;
		float tax_join = total_tax + secondary_tax;
		float take_joined_home = cojoint_income - tax_join;
		float take_home_percentage_join = take_joined_home / cojoint_income * 100;

		printf("\n\nHi %s, this is your annually tax summary:", name);
		printf("\n\nIncome tax rate                                                       income          tax");
		printf("\nIncome tax up to $14000,taxed at 10.5%%                                %.2f        %.2f ", amount[0], tax[0]);
		printf("\nIncome tax up to $14000 and up to $48000, taxed at 17.5%%              %.2f        %.2f ", amount[1], tax[1]);
		printf("\nIncome tax up to $48000 and up to $70000, taxed at 30%%                %.2f        %.2f   ", amount[2], tax[2]);
		printf("\nIncome tax up to $70000 and up to $180000, taxed at 33%%               %.2f        %.2f ", amount[3], tax[3]);
		printf("\nRemaining income over $180000, tax at 39%%                             %.2f            %.2f ", amount[4], tax[4]);
		printf("\nIncome from the secondary source                                       %.2f      %.2f", another_income, secondary_tax);
		printf("\nTotal                                                                 %.2f       %.2f  ", cojoint_income, tax_join);
		printf("\n\nAnnualy take home pay is %.2f ", take_joined_home);
		printf("(%.2f%%)", take_home_percentage_join);
	}
	else {
		printf("\n\nHi %s, this is your annually tax summary:", name);
		printf("\n\nIncome tax rate                                                       income          tax");
		printf("\nIncome tax up to $14000,taxed at 10.5%%                                %.2f        %.2f ", amount[0], tax[0]);
		printf("\nIncome tax up to $48000 and up to $48000, taxed at 17.5%%              %.2f        %.2f ", amount[1], tax[1]);
		printf("\nIncome tax up to $48000 and up to $70000, taxed at 30%%                %.2f        %.2f   ", amount[2], tax[2]);
		printf("\nIncome tax up to $70000 and up to $180000, taxed at 33%%               %.2f        %.2f ", amount[3], tax[3]);
		printf("\nRemaining income over $180000, tax at 39%%                             %.2f            %.2f ", amount[4], tax[4]);
		printf("\nTotal                                                                 %.2f       %.2f  ", annual_income, total_tax);
		printf("\n\nAnnualy take home pay is %.2f ", take_home);
		printf("(%.2f%%)", take_home_percentage);
	}
}
