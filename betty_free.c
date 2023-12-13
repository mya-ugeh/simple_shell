#include <stdio.h>

/**
 * bmi_check - Entry point
 * Description: calculate bmi of an individual
 *
 * Return: always 0(success)
 */

int bmi_check(void)
{
	char name[30];
	float weight, height;
	float height_squared, bmi;

	printf("What is your name: ");
	scanf("%s", name);

	printf("Enter weight(in kg): ");
	scanf("%f", &weight);

	printf("Enter height(in m): ");
	scanf("%f", &height);

	height_squared = height * height;
	bmi = weight / height_squared;

	printf("%s, your BMI is : %.1f\n", name, bmi);

	if (bmi < 18.5)
		printf("You are underweight\n");
	else if (bmi >= 18.5 && bmi <= 24.9)
		printf("You are healthy\n");
	else if (bmi >= 25.0 && bmi <= 29.9)
		printf("You are overweight\n");
	else
		printf("You are obese\n");

	return (0);
}
