 #include <stdio.h>

// Note: 65 - 90 = Captial letters a-z
// 97 - 122 = lower case letters a-z
// (c = c - 65) converts each letter of alphabet to a number

// each function performs a specific task (name indicative of task)
char encryptRotate(char* text, int key);
char decryptRotate(char* text, int key);
char encryptSubstitute(char* text, int key);
//char decryptSubstitute()
//char decryptRotateText()
//char decryptSubstituteText()

int main () {
    char text[100];
    //char alphabet[100];
    //char rotateAlphabet[100];
    
    int key;
    // menu for choosing which task to use
    printf("Please select an option: \n");
    printf("1) Encrypt using rotation cypher \n");
    printf("2) Decrypt using rotation cypher \n");
    printf("3) Encrypt using substitution cypher \n");
    printf("4) Decrypt using substitution cypher \n");    
    printf("5) Decrypt text only using rotation cypher \n");
    printf("6) Decrypt text only using substitution cypher \n");
    printf("Selection: ");
    int selection;
    scanf("%d", &selection);
    
    switch (selection)  {
        case 1: encryptRotate(text, key); break;
        case 2: decryptRotate(text, key); break;
        case 3: encryptSubstitute(text, key); break;
//        case 4: decryptSubstitute(text, key); break;
    //  case 5: DecryptRotateText(); break;
    //  case 6: DecryptSubstituteText(); break; 
        default: printf("Uknown option %d\n Please enter a, b, c or d", selection);
    }
    return 0;
    }	
	

//alvndsv

	//==================================Rotate Encryption Function=======================================//
char encryptRotate(char* text, int key)    {
	char msg;
	int n;
	printf("Enter a message to encrypt: ");
	scanf(" %[^\n]*c", text); // gets whole message entered 
	// e.g "Hello world" scanf would only get "Hello"
	printf("Enter Key: ");
	scanf("%d", &key);
	
	for(n = 0; text[n] != '\0'; ++n){
	    msg = text[n]; 
	    
	    if (msg >= 'a' && msg <= 'z')   {
	        msg = msg + key;
	        
	        if(msg > 'z') {
	            msg = msg - 'z' + 'a' - 1;
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

char decryptRotate(char* text, int key)    {
	char msg;
	int n;
	printf("Enter a message to decrypt: ");
	// NEED TO FIX **************************
	scanf(" %[^\n]*c", text); // gets whole message entered 
	// e.g "Hello world" scanf would only get "Hello"
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

char encryptSubstitute(char* text, int key)
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

