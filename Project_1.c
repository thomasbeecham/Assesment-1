 #include <stdio.h>

// Note: 65 - 90 = Captial letters a-z
// 97 - 122 = lower case letters a-z
// (c = c - 65) converts each letter of alphabet to a number

// each function performs a specific task (name indicative of task)
char encryptRotate(char* text, int key);
char decryptRotate(char* text, int key);
//char encyrptSubstitute();
//char decryptSubstitute()
//char decryptRotateText()
//char decryptSubstituteText()

int main () {
    char text[100];
    char alphabet[100];
    char rotateAlphabet[100];
    int key;
    // menu for choosing which task to use
    printf("Please select an option: \n");
    printf("a) Encrypt using rotation cypher \n");
    printf("b) Decrypt using rotation cypher \n");
    printf("c) Encrypt using substitution cypher \n");
    printf("d) Decrypt using substitution cypher \n");    
    printf("e) Decrypt text only using rotation cypher \n");
    printf("f) Decrypt text only using substitution cypher \n");
    printf("Selection: ");
    char selection;
    scanf("%c", &selection);
    
    switch (selection)  {
        case 'a': encryptRotate(text, key); break;
        case 'b': decryptRotate(text, key); break;
//        case 'c': encryptSubstitute(text, key); break;
//        case 'd': decryptSubstitute(text, key); break;
    //  case 'e': DecryptRotateText(); break;
    //  case 'e': DecryptSubstituteText(); break; 
        default: printf("Uknown option %c/n Please enter a, b, c or d/n");
    }
    return 0;
    }	
	

//alvndsv

	//==================================Rotate Encryption Function=======================================//
char encryptRotate(char* text, int key)    {
	char msg;
	int n;
	printf("Enter a message to encrypt: ");
	scanf("%[^\n]*c", text); // gets whole message entered 
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
    printf("Encrypted message is: %s", text);
    
    return 0;
}
/*=====================================Decrypt Rotate Function=================================*/

char decryptRotate(char* text, int key)    {
	char msg;
	int n;
	printf("Enter a message to decrypt: ");
	// NEED TO FIX **************************
	scanf("%s", text); // gets whole message entered 
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
printf("Decrypted message is: %s", text);

return 0;
}
