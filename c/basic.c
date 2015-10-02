#include <stdio.h>
#ifndef SIZE
#define SIZE 5
#endif
int main()
{
int array[SIZE] = {1,2,3,4,5};
int* array_p = &array[0];
int i = 0;
loop:
	if(i < SIZE)
	{
	i++;
	printf("%d",*(array_p++));
	goto loop;
	}
	scanf("%d",&i); /// only to pause the cmd(Im using windows...)
}
#undef SIZE