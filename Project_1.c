# include <stdio.h>
#include<string.h>// for stringlen()
#include<stdlib.h>
// Note: 65 - 90 = Captial letters a-z
// 97 - 122 = lower case letters a-z
// (c = c - 65) converts each letter of alphabet to a number
void encryptRotate(char* strAlpha, int key);
void decryptRotate(int x);
void encyrptSubstitute(int x);

int main () {
    int key = 1;
	char strAlpha[101];
	
	//Ask the user for the text to encrypt
	printf("Please enter the plain text you want to encrypt: ");
	
	//Get the users text input and stores it in plainText variable
	fgets(strAlpha, sizeof(strAlpha), stdin);
	
	//Prints the ciphered text
	printf("The ciphered text is: ");
	
	//Prints the ciphered text
	encryptRotate(strAlpha, key);
	
	system("pause");
    	
    	
}

	//------------------------encryption-----------------------------------------------
	void encyrptRotate(char* strAlpha, int key) {
	
	int i=0;
	int cypherValue;
	char cypher;
	
	while( strAlpha[i] != '\0' && strlen(strAlpha)-1 > i){
		cypherValue = ((int)strAlpha[i] -97 + key) % 26 + 97;
		cypher = (char)(cypherValue);
		
		printf("%c", cypher);
		i++;
//	
}
}

	
	



