#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include"queue.h"


//function for the encryption

void encrypt(circularQueue *q,char *text,int key){                    
    for(int i=0;text[i]!='\0';i++){
        if(isalpha(text[i])){
            int isLower = islower(text[i]);  //To check the lowercase 

            text[i] = toupper(text[i]);
            int index = getindex(q, text[i]);
            int shiftindex = (index + key + queue_size) % queue_size;  
            text[i] = getinchar(q, shiftindex);

            if (isLower) {
                text[i] = tolower(text[i]);  //convert to lowercase if original is lowercase
            }
        }
    }
}


//function for the decryption

void decrypt(circularQueue *q,char *text,int key){      
    for(int i=0;text[i]!='\0';i++){
        if(isalpha(text[i])){
            int isLower = islower(text[i]);  

            text[i] = toupper(text[i]);
            int index = getindex(q, text[i]);
            int shiftindex = (index - key + queue_size) % queue_size;  //can handle negative values
            text[i] = getinchar(q, shiftindex);

            if (isLower) {
                text[i] = tolower(text[i]);  
            }
        }
    }
}



int main() {
    circularQueue alphabet;
    char text[100];
    int key;
    char option;

    createqueue(&alphabet);

    printf("Encryption (E) or Decryption (D)?:");
    scanf("%c",&option);

    if(option=='E'||option=='e'){
    while ((getchar()) != '\n');

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);
    printf("*********************\n");

    encrypt(&alphabet, text, key);
    printf("Encrypted Message: %s\n", text);


} else if(option=='D'||option=='d'){
    while ((getchar()) != '\n');

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);
    printf("*********************\n");

    decrypt(&alphabet, text, key);
    printf("Decrypted Message: %s\n", text);

}   

    else{
        printf("wrong choice");
    }

    return 0;
}