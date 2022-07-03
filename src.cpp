#include <iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int hash_func(string str)
{
  int ascii_sum=0;
  int length=str.size();
  int i= 0;
  while(i<length){
    ascii_sum=ascii_sum+str[i];
    i++;
  }
  
  return ascii_sum%20000;
}

int main() {
 
 vector<string> Hash_T_username[20000];
 vector<string> Hash_T_password[20000];
 string line,word;
 ifstream file("userInfo.csv");
 if(file.is_open())
 {
  cout<<"We opened the file\n";
	while(getline(file, line))
	{
		stringstream str(line);
		getline(str, word, ',');
    int key=hash_func(word);
    Hash_T_username[key].push_back(word);
    getline(str,word,'\r');
    Hash_T_password[key].push_back(word);
   }
	}
 else
 {	
   cout<<"We were not able to open the file\n";
 }
 string username;
 string password;
 cout<<"Please enter the username: ";
 cin>>username;
 int index=hash_func(username);
 for(int i=0;i<Hash_T_username[index].size();i++)
 {
   if(Hash_T_username[index][i]==username)
   {
     cout<<"Valid username, Please enter password!";
     cin>>password;
     if(Hash_T_password[index][i]==password)
     {
       cout<<"Succesfully logged in!";
       break;
     }
     else
     {
       cout<<"Incorrect Password! ";
       cout<<Hash_T_password[index][i]<<endl;
       break;
     }
   }
  }
 
 return 0;
  
}k
