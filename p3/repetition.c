#include <stdio.h>

void bubble_sort(int *tab, int size){
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1){
		j = 0;
		while (j < size - 1 - i){
			if (tab[j] > tab[j + 1]){
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int main(){
    int	tab[10] = {5, 2, 9, 1, 5, 6, 3, 7, 8, 4};
    int	i;

    bubble_sort(tab, 10);
    i = 0;
    while (i < 10){
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
    return (0);
}