#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void all_low(char *string){
	int i;
	for (i=0;i<strlen(string);i++){
		if (string[i] < 'a'){
			string[i] += ('a' - 'A');
		}
	}
}

int palindromo(char *string, int start, int end){
	if (start == end)
    return 1;
 
    if (string[start] != string[end])
    return 0;

    if (start < end + 1)
    return palindromo(string, start + 1, end - 1);
 
    return 1;
}

int main() {
   char* str = malloc(100*sizeof(char));
	scanf("%[^\n]s",str);
	all_low(str);
	if (palindromo(str, 0, strlen(str)-1)){
		printf("sim");
	}
	else{
		printf("nao");
	}
   return 0;
}