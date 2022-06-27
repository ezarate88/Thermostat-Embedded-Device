/* Encryption code provided by Vivek Kumar Jaiswal and can be found using the following link:
* https://www.codespeedy.com/c-program-to-encrypt-and-decrypt-a-string/
* Decryption: This code will take a string and decode the string so that is can be decoded with the function later. 
* This will be used for encrypting the username and password within the project to help hide the informaiton from being 
* seen in the binary code so it is not easily given away. 
*/

#include<iostream>
#include<string.h>

using namespace std;


string encryptyfunc(string text, int auth) // Simple algorithm for encryption. 
   {
     char temp;
  int i, key;
  key = auth; // Authentication "Badge ID" will be used as key for this program. 
  
  cout <<"Enter a message to encrypt: " <<endl;
  cin >>text;
  cout <<"Enter key: " <<endl;
  cin >> key;
  for(i = 0; text[i] != '\0'; ++i){
    temp = text[i];
    //If the message to be encypted is in lower case
    if(temp >= 'a' && temp <= 'z'){
      temp = temp + key;
      
      if(temp > 'z'){
        temp = temp - 'z' + 'a' - 1;
      }
      
      text[i] = temp;
    }
    //If the message to be encypted is in upper case
    else if(temp >= 'A' && temp <= 'Z'){
      temp = temp + key;
      
      if(temp > 'Z'){
        temp = temp - 'Z' + 'A' - 1;
      }
      
      text[i] = temp;
    }
    
  }
  
  return text;
}

string decryptfunc(string text, int auth)
{
    char temp;
  int i, key;
  key = auth;
  for(i = 0; text[i] != '\0'; ++i){
    temp = text[i];
    //If the message to be decypted is in lower case.
    if(temp >= 'a' && temp <= 'z'){
      temp = temp - key;
      
      if(temp < 'a'){
        temp = temp + 'z' - 'a' + 1;
      }
      
      text[i] = temp;
    }
    //If the message to be decypted is in upper case.
    else if(temp >= 'A' && temp <= 'Z'){
      temp = temp - key;
      
      if(temp < 'A'){
        temp = temp + 'Z' - 'A' + 1;
      }
      
      text[i] = temp;
    }
  }
  
  return text;
  
}
 
