#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>


//Funzione per aumentare le cifre.
//Se io ho 012 -> 013 -> 014 .. 019 --> 023
//Funzione per determinare lo start.
//012 -> 0123 --> 01234 etc
 
		
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putstr(char *str)
{
	int i = 0;
	int j = 0;
	while(str[i]!='\0')
		i++;

	while(i >= j)
		write(1,&str[i--],1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i]!='\0')
	{
		i++;
	}
	return i;
}

void putnbr(int nb)
{
	if(nb > 9)
		putnbr(nb/10);
	ft_putchar(nb%10 + '0');
}

int count_digits(int a)
{
	int digits = 1;
	while(a > 9 || a < -9)
	{
		a/=10;
		digits++;
	}
	return digits;
}

int are_digits_unique(char *numarray)
{
	int i = 0;
	while(numarray[i]!='\0')
	{
		int k = i + 1;
		while(numarray[k])
		{
			if(numarray[i] == numarray[k])
				return 0;
			k++;
		}
		i++;
	}
	return 1;
}

char *ft_strcpy(char *dest, char *str)
{
	char *orig_dest = dest;
	while(*str)
		*dest++= *str++;
	*dest = '\0';
	return orig_dest;
}

int check_combinations(char *base, char *to_check)
{
	int i = 0;
	int count[10] = {0};

	if(ft_strlen(base) != ft_strlen(to_check))
		return 0;
	//Scorro la base e per ogni suo valore aumento l'index di base i - '0' di 1.
	//Se il numero è 3 count sarà count[base[i] - '0'] o count 3. E count [3] sarà flaggato ad 1. 
	while(base[i] !='\0')
	{
		count[base[i]-'0']++;
		i++;
	}
	i = 0;
	//Dopo aver flaggato tutti i valori di base ad 1 andrò a sottrarre 1 ad ogni valore di count
	//Basandomi sugli index che trovo grazie sottraendo i valori di count[to_check[i] - '0']
	//Se la base  è 123 e to_check è 321 in corrispondenza dell'index 1 2 e 3 troverò 1 e togliendo -1 avrò tutti 0.
	//Se il valore della sottrazione sarà negativo significa che ho trovato un numero che non è stato settato in primis a 1.
	//Quindi il primo numero non è una permutazione del secondo.
	while(to_check[i]!='\0')
	{
		count[to_check[i] - '0']--;
		if(count[to_check[i] - '0'] < 0)
			return 0;
		i++;
	}
	return 1;
}

void ft_print_combn(int n)
{
	//Transform num into char array.
	char numarray[11] = {0};
	char arrays[100000][11] = {{0}};
	int num = 1;
	int zeros = 0;
	int s_digits = count_digits(num);
	int i = 0;
	int j = 0;

	int  k = 0;

	if(n == 1)
	{
		while(k < 10)
		{
			ft_putchar(k + '0');
			if(k < 9)
			{
				ft_putchar(' ');
			}
			k++;
		}
		return;
	}

	while(s_digits > 0 && s_digits <= n && j < 100000)
	{
		int c_digits = count_digits(num);
		if(c_digits > s_digits)
			s_digits++;
			zeros = n - c_digits;

		i = 0;
		int temp_n = num;
		while(temp_n)
		{
			numarray[i] = temp_n%10 + '0';
			temp_n/=10;
			i++;
		}
			while(zeros--)
			{
				if(c_digits < n)
				{
					numarray[i++] = '0';
				}
			}
		numarray[i] = '\0';
		if(are_digits_unique(numarray))
		{
			ft_strcpy(arrays[j],numarray);
			j++;
		}
		num++;
	}
	arrays[j][0] = '-';
	i = 0;
	int u = 0;
	while(arrays[i][0] != '-')
	{
		int print_flag = 1;
		u = 0;
		while(u < i)
		{
			if(check_combinations(arrays[i],arrays[u]))
			{
				print_flag = 0;
				break;
			}
			u++;
		}

		if(print_flag)
		{
			putstr(arrays[i]);
			ft_putchar(' ');
		}
		i++;
	}
}


int main()
{
	ft_print_combn(9);
}
