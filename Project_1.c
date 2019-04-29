 #include <stdio.h>
/* 
This c program is a basic code which prints a menu displaying a choice of ciphers you can
use as well as a choice of decrypting or encrypting a message using that method.
After your selection 

*/
// Note:ASCII values 65 - 90 = Captial letters a-z
//ASCII values 97 - 122 = lower case letters a-z

// setting up function definitions BEFORE main
// these functions are called individually depending on which task is wanted
// each function performs a specific task (name indicative of task)
int encryptRotate(char* text, int key);
int decryptRotate(char* text, int key);
int encryptSubstitute(char* text, int key);
int decryptSubstitute(char* text, int key);
int decryptRotateBrute(char* text, int key);
//char decryptSubstituteText()

int main () 
{
     char text[100];     
    //array is defined within main
    //so it doesnt have to be defined within each function.
    
    int key;
    // printing a simple menu for the user to choose which task to use
    printf("Select an option by entering the corresponding number then pressing ENTER: \n");
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
        case 4: decryptSubstitute(text, key); break;
        case 5: decryptRotateBrute(text, key); break;
    //  case 6: decryptSubstituteText(); break; 
        default: printf("Uknown option %d\n Please enter 1, 2, 3, 4 or 5.\n", selection); // added to increase performance of menu
        // will print this message if the user selects a number outside of the selection (1-4)
    }
    }	

//====================================Rotate Encryption Function=========================================//

/* 
 The first function, which encrypts a message using the rotation cypher. 
 NOTE how this function had to be initialised before main at the start of the code.
 */

int encryptRotate(char* text, int key) 
{
	unsigned char msg; 
	/* needs to be unsigned char as char has data values from -128 to 127 
	and unsigned char from 0 to 255 which enables user to use a higher key like 20+.
	otherwise program fails and there is no ouput if value exceeds 127. 	*/
	int n;
	printf("Enter a message to encrypt: ");
	scanf(" %[^\n]*c", text); // stores whole message entered as a char. 
	//NOTE: had great trouble with this scanf as the code would skip the section.
	//Adding a space before the % rectified this problem and allowed us to enter the message

	printf("Enter Key: "); // key used for amount of 'rotation' in alphabet
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
// Performs the same task as in line 84. Just allows for encrypting of capital letter input
// as well as lower case making the program more practical.
	    }
	    text[n] = msg;
	}
    
}
    printf("Encrypted message is: %s\n", text); 
        printf("End of program\n");
    
    return 0;
}
/*=====================================Decrypt Rotate Function=================================*/
/*
 This function is essentially the same as the encrypting function above in terms of coding 
 and equations apart from having the OPPOSITE signs. E.g a + sign becomes a - sign, etc.
 I have left comments for this function as it is similar to the one above.
 */
int decryptRotate(char* text, int key)    {
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
    printf("End of program\n");

return 0;
}

//=================================Substitution Encryption Function==============================

int encryptSubstitute(char* text, int key)
{

    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q', 'R','S','T','U','V','W','X','Y','Z'};
    char newAlpha[26];
    char character;
    int i, n;   // i stands for index in this case
    printf("Enter a message to encrypt: ");
    scanf(" %[^\n]*c", text);   
    printf("Enter your substituted alphabet IN CAPITALS: ");    // this function requires caps input
    //
    scanf("%s", newAlpha);  // reads new string and stores it in terminal
    
    for(i = 0; text[i] != '\0'; i++) {
        character = text[i]; //each character is assigned a value in the text array
        
        if(character >= 'a' && character <= 'z')    {
            character = character -32; //this changes the output to upper case letters regardless if the user
            //inputs lower case letters
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
int decryptSubstitute(char* text, int key)
{
    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q', 'R','S','T','U','V','W','X','Y','Z'};
    char newAlpha[26];
    char character;
    int i, n;
    printf("Enter a message to decrypt: ");
    scanf(" %[^\n]*c", text);
    printf("Enter the substituted alphabet IN CAPITALS: ");
    scanf("%s", newAlpha);
    
    for(i = 0; text[i] != '\0'; i++) {
        character = text[i]; 
        
        if(character >= 'a' && character <= 'z')    {
            character = character - 32; //
        }
    
    for (n = 0; n <= 25; n++)   {
        if (character == newAlpha[n])  {
            character = alpha[n];
            text[i] = character;
            break;
        }
    }
}
    printf("Decrypted message is: %s\n", text);
    printf("End of program\n");

    return 0;
}



 
 int decryptRotateBrute(char* text, int key)    {

	unsigned char msg;
	int n;
	printf("Enter a message to decrypt: ");
	scanf(" %[^\n]*c", text);  

	for(key = 1; key < 27; key ++)   {
	    // added this for loop to 'brute force' a random 
	for(n = 0; text[n] != '\0'; ++n){
	    msg = text[n];

	    if (msg >= 'a' && msg <= 'z')   {  
	        msg = msg - 1;

	        if(msg < 'a') {
	            msg = msg + 'z' - 'a' + 1;
	    }
	    text[n] = msg - 32;	    
	}
	else if(msg >= 'A' && msg <= 'Z')   {
	    msg = msg - 1;
	    
	    if (msg < 'A')   {
	       msg = msg + 'Z' - 'A' +1; 
	    }
	    text[n] = msg;
	}
	} 
	printf("Decrypted message with key %d:/n %s\n",   key, text);
}


return 0;
}

 /*
Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher: 1 mark
*/
