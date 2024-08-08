
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(int nb, int *tab, int pos)
{
	int i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < nb)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_print_combn_increment(int nb, int *tab)
{
	int i;
	int max;

	i = nb - 1;  //Indice ultima cifra
	max = 9; //Massimo numero raggiungibile.
	//Se tab corrente è {0,7,9} -> si fermerà al secondo ciclo dove i = 1. Perchè 7 non sarà uguale a 8,ovvero max -1. 
	while (tab[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	//Quindi aumentiamo tab[i] di 1 che farà diventare {0,8,9}.
	tab[i] += 1;
	//Tuttavia ora ci sono da rivedere tutte le cifre a destra rispetto ad i per assicurarci che siano in ordine crescente.
	//Se la combinazione è {1,8,9}, troverà la prima cifra a sinistra aumentabile per poi aggiornare tutto il resto --> da {1,8,9} a {2,3,4}. da {2,8,9} a {3,4,5}. etc.
	while (i < nb)
	{
		tab[i + 1] = tab[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int nb)
{
	int tab[10]; //Inizializza un array di numeri composto da 10 elementi. (Possibile 1 per null terminator).
	int i;

	i = 0;
	while (i < nb) //Esempio con nb = 3. I = 0, i = 1, i = 2. quindi tab[i] = 0,1,2. <-- Combinazione iniziale.
	{
		tab[i] = i; 
		i++;
	}
	ft_putout(nb, tab, 0); //Stampa la prima combinazione, con flag a 0 per non metterci davanti virgola e spazio.
	//Esempio con nb = 3. Quindi numero a 3 cifre. 
	while (tab[0] != 10 - nb || tab[nb - 1] != 9) //tab[0] != 10 - 3 = 7. || tab[2] != 9. --> Finchè la prima cifra è diversa da 7 e l'ultima è diversa da 9.
	{
		if (tab[nb - 1] != 9) //Se tab[2] != 9 lo aumento di 1.
		{
			tab[nb - 1] += 1;
		}
		else
		{
			ft_print_combn_increment(nb, tab); //Altrimenti aumento tutte le altre cifre finchè max è uguale a 9.
		}
		ft_putout(nb, tab, 1); //Stampo la combinazione.
	}
}

int main()
{
	ft_print_combn(9);
}
