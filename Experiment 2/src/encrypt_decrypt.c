#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int mainkey, key;


int main() {

printf("Positive interger makes the left shift and negative integer will make right shift.\n");
printf("The key value has the range -26 to 26.\n");

printf("Please enter the key:\n");

scanf("%d", &mainkey);



//printf("The key is  ==  %d\n",key);
char plain_text[100];
char cypher[100];
printf("The plain text should contain only capital letters\n");
printf("Please give the plain text \n");
scanf("%100s", plain_text);

//printf("%s\n", plain_text);
char x[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int pp= strlen(x);
char y[26];
//printf("%d\n", pp);
int m;
for(m=0; m<strlen(x); m++){

  int temp = x[m];

  if(mainkey>=0){

    key=mainkey;
  } else {
    key= 26-(-mainkey);
  }


  if(temp==32|| temp == 46|| temp == 44 || temp ==59){    //considering empty space, dot comma and semicolon
    temp= temp;
  }
  else if(temp<=90 && (temp+key)>90){      //considering capital alphabets when overflows
    temp = 65+(temp+key-1)-90;
  }
  else if(temp<=122 && (temp+key)>122){     //considering small alphabets when overflows
    temp = 97+(temp+key-1)-122;
  } else{
    temp = temp+key;                        // applying the shifting after that
  }



  y[m] = temp;


  //printf("%d\n", temp);
  //printf("%c", cypher);
}

//printf("%s\n", y);
int i,j, position,k;
int length;

length = strlen(plain_text);
//printf("%d\n", length);
for(i = 0; i <length;i++){
  char p = plain_text[i];
  for (j = 0; j< 26; j++){
    if(p==x[j]) position = j;
  }
  cypher[i] = y[position];
}
printf("The cypher text:\n");
printf("%s\n", cypher);

return 0;
}
