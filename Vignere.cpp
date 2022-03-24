#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
using namespace std;

string message , key , repeat , output;
int x = 0, y = 0;

//Convert The message and the keyword into uppercase
int upper(){
  for (int i = 0; i < message.length(); i++)
     {
          message[i] = toupper(message[i]);

     }
   for (int i = 0; i < key.length(); i++)
   {
        key[i] = toupper(key[i]);
   } 
}
//Resize the keyword to fit the user message
int key_size(){
      for (int i = 0; i<=message.length(); i++){
          if (x  < key.length() )
          {
               repeat += key[x];
               x++;
          }
          else{
               x = 0;
          }   
     }
}
int encryption(){
     cout<<"Please enter the message you want to cipher:";
     cin.ignore();
     getline(cin,message);
     //Check the size of the message
     while (message.length()> 80)
     {
          cout<<"Too long message";
          cout<<"Please enter the message you want to cipher:";
          cin.ignore();
          getline(cin,message);
     }
     cout<<"Please enter the keyword you want to cipher with:";
     getline(cin,key);
     //Check the size of the keyword
     while (key.length() > 8)
     {
          cout<<"Too long keyword";
          cout<<"Please enter the keyword you want to cipher with:";
          cin>>key;
     }
     upper();
     key_size();

     for (int i = 0; i <message.length() ; i++)
     {    //Making sure that only alphabetic characters will be encoded
          if (message[i] !=' ' && ! isdigit(message[i]))
          {    //Calculation to cipher the message
               y = int(message[i])+int(repeat[i]);
               y = y%26;
               y = y + 65;
               output += char(y);               
          }
          else{
               output += message[i] ;     
          }
     }
     cout<<output;
}
int decryption(){
     cout<<"Please enter the message you want to decipher: ";
     cin.ignore();
     getline(cin,message);
     cout<<"Please enter the keyword you want to decipher with:";
     getline(cin,key);
     upper();
     key_size();
     for (int i = 0; i <message.length() ; i++)
     {
          if (message[i] !=' ' && ! isdigit(message[i]))
          {    //Calculation to decipher the message
               y = int(message[i])-int(repeat[i]);
               y = y+ 26;
               y = y%26;
               y = y + 65;
               output += char(y);
          }
          else{
               output += message[i];    
          }
     }
     cout<<output;
}
int main(){
     int desire;
     cout<<"Ahlan ya user ya habibi"<<endl<<"What do you like to do today?"<<endl;
     cout<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
     cin>>desire;
     if (desire == 1)
     {
          encryption();
     }
     else if (desire == 2)
     {
          decryption();
     }
     else{
          cout<<"Bye bye ya user ya habiby";
          exit;
     }
     
     
     



}