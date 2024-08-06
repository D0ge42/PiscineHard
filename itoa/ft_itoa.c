#include <stdlib.h>
#include <stdio.h>

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

char rarray(char *str)
{
	int i = 0;
	while(str[i]!='\0')
		i++;
	int end = i - 1;
	if(str[0] == '-')
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
	num = malloc(sizeof(char) * (digit_count(nb) + 2));
	while(nb > 0 || nb < 0)
	{
		if(nb < 0)
		{
			num[0] = '-';
			nb *= -1;
			i++;
			continue;
		}
		num[i] = nb%10 + '0';
		nb/=10;
		i++;
	}
	rarray(num);
	num[i] = '\0';
	return num;
}

int main()
{
	printf("%s\n",ft_itoa(2147483648));
}




