#include <stdlib.h>
#include <stdio.h>

//Function to count digits.
int digit_count(int nb)
{
	int count = 0;
	if(nb == 0) count = 1;
	while(nb > 0 || nb < 0)
	{
		nb/=10;
		count++;
	}
}

//Function to reverse an array.
char rarray(char *str)
{
	int i = 0;
	while(str[i]!='\0')
		i++;
	int end = i - 1;
	if(str[0] == '-') //If number is negative we skip one index so the sign stays at its place.
		i = 1;
	else
		i = 0;
	while(i < end)
	{
		char temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
}
char *ft_itoa(int nb)
{
	char *num;
	int i = 0;
	if(nb == 0)  //Handle special cases
	{
		num = "0";
		return num;
	}
	if(nb == 2147483648 || nb == -2147483648)
	{
		num = "-2147483648";
		return num;
	}
	num = malloc(sizeof(char) * (digit_count(nb) + 2)); //Malloc is plus 2 to handle both sign and null terminator.
	if(num == NULL)
		return NULL;
	while(nb > 0 || nb < 0)
	{
		if(nb < 0)
		{
			num[0] = '-';
			nb *= -1; 
			i++;
			continue;
		}
		num[i] = nb%10 + '0'; //We get every digit by doing mod 10 and then add '0' to do ascii conversion.
		nb/=10;
		i++;
	}
	rarray(num);
	num[i] = '\0'; //Add null terminator only after changing digits order.
	return num;
}

/*
int main()
{
	printf("%s\n",ft_itoa(12399));
}*/




