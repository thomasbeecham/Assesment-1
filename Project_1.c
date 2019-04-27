 #include <stdio.h>
/* 
This c program is a basic code which prints a menu displaying the types of cyphers you can
use as well as a choice of decrypting or encrypting

*/
// Note: 65 - 90 = Captial letters a-z
// 97 - 122 = lower case letters a-z

// detting up function definitions BEFORE main
// these functions are called individually depending on which task is wanted
// each function performs a specific task (name indicative of task)
char encryptRotate(unsigned char* text, int key);
char decryptRotate(unsigned char* text, int key);
char encryptSubstitute(unsigned char* text, int key);
//char decryptSubstitute()
//char decryptRotateText()
//char decryptSubstituteText()

int main () {
    unsigned char text[100];     
    // each array is defined within main
    //so it doesnt have to be defined within each function.
    
    //char alphabet[100];
    //char rotateAlphabet[100];
    
    int key;
    // printing a simple menu for choosing which task to use
    printf("Please select an option: \n");
    printf("1) Encrypt using rotation cypher \n");
    printf("2) Decrypt using rotation cypher \n");
    printf("3) Encrypt using substitution cypher \n");
    printf("4) Decrypt using substitution cypher \n");    
    printf("5) Decrypt text only using rotation cypher \n");
    printf("6) Decrypt text only using substitution cypher \n");
    printf("Selection: ");
    int selection;
    scanf("%d", &selection); // this selection is stored for use in the switch statement below
    
    // switch statement simpler and 'tidier' in this case rather than an extensive IF / IF-ELSE statement
    switch (selection)  {
        case 1: encryptRotate(text, key); break;
        case 2: decryptRotate(text, key); break;
        case 3: encryptSubstitute(text, key); break;
//        case 4: decryptSubstitute(text, key); break;
    //  case 5: DecryptRotateText(); break;
    //  case 6: DecryptSubstituteText(); break; 
        default: printf("Uknown option %d\n Please enter 1, 2, 3 or 4", selection); // added to increase performance of menu
        // will print this message if the user selects a number outside of the selection (1-4)
    }
    return 0;
    }	
	

//alvndsv

	//==================================Rotate Encryption Function=======================================//
/* 
 The first function, which encrypts a message using the rotation cypher. 
 NOTE how this function had to be initialised before main at the start of the code.
 
 
 */

char encryptRotate(unsigned char* text, int key)    {
	unsigned char msg;
	int n;
	printf("Enter a message to encrypt: ");
	scanf(" %[^\n]*c", text); // stores whole message entered as a char

	printf("Enter Key: ");
	scanf("%d", &key); // stores key for use in cypher 
	
	for(n = 0; text[n] != '\0'; ++n){
	    msg = text[n]; 
	    
	    if (msg >= 'a' && msg <= 'z')   {
	        msg = msg + key;
// if msg is between range of a-z in ascii values it then applies the key to its value    	        
	        if(msg > 'z') {
	            msg = msg - 'z' + 'a' - 1;
// the line above subtracts the ASCII value of the character in the msg[n] (n is number of rotations)
//and to shift it in order to keep message in alphabets only and so that it doesn’t go in the special characters.	            
// in other words it keeps the output value between the ascii value of a-z or A-Z keeping letters as output.
	 }
	    text[n] = msg;	    
	}
	else if(msg >= 'A' && msg <= 'Z')   {
	    msg = msg + key;
	    
	    if (msg > 'Z')   {
	       msg = msg - 'Z' + 'A' - 1; 
	    }
	    text[n] = msg;
	}
    
}
    printf("Encrypted message is: %s\n", text);
    
    return 0;
}
/*=====================================Decrypt Rotate Function=================================*/

char decryptRotate(unsigned char* text, int key)    {
	unsigned char msg;
	int n;
	printf("Enter a message to decrypt: ");
	scanf(" %[^\n]*c", text);  
	printf("Enter Key: ");
	scanf("%d", &key);    
	
	for(n = 0; text[n] != '\0'; ++n){
	    msg = text[n];

	    if (msg >= 'a' && msg <= 'z')   {  
	        msg = msg - key;

	        if(msg < 'a') {
	            msg = msg + 'z' - 'a' + 1;
	    }
	    text[n] = msg;	    
	}
	else if(msg >= 'A' && msg <= 'Z')   {
	    msg = msg - key;
	    
	    if (msg < 'A')   {
	       msg = msg + 'Z' - 'A' +1; 
	    }
	    text[n] = msg;
	}
    
}
printf("Decrypted message is: %s\n", text);

return 0;
}

//=================================Substitution Encryption Function==============================

char encryptSubstitute(unsigned char* text, int key)
{

    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q', 'R','S','T','U','V','W','X','Y','Z'};
    char newAlpha[26];
    char character;
    int i, n;
    printf("Enter a message to encrypt: ");
    scanf(" %[^\n]*c", text);
    printf("Enter your substituted alphabet IN CAPITALS: ");
    scanf("%s", newAlpha);
    
    for(i = 0; text[i] != '\0'; i++) {
        character = text[i]; 
        
        if(character >= 'a' && character <= 'z')    {
            character = character -32;
        }
    
    for (n = 0; n <= 25; n++)   {
        if (character == alpha[n])  {
            character = newAlpha[n];
            text[i] = character;
            break;
        }
    }
}
    printf("Encrypted message is: %s\n", text);
    printf("End of program\n");
    return 0;
}


//=================================Substitution Decryption Function==============================

/*
Decryption of a previously unseen cipher text encrypted with a rotation cipher: 1.5 marks
Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher: 1 mark
 */
