#include<iostream>
using namespace std;
#include<cstring>

#include "stack.h"

int main(int argc, char **argv){
   int i, j;
/*
  Exercise 2
  check the canvas discription
 printf("Checking the parentheses in argv arguments\n");

   */

    for(i = 1; i < argc; i++)
    {
          Stack s; //change node to char--->***
          bool balanced = true;
          char c;

      for(j = 0; j < strlen(argv[i]); j++)
      {
          c = (argv[i][j]);

        if(c =='[' || c == '{') //check opening
        s.push(c);

        else if(c ==']' || c == '}') //check closing
      {
        int topValue = s.pop(); //in case of lone } or ]
        if (topValue == -1)
        {
          balanced = false;
          break;
        }

          char topChar = (char)topValue;
        if (c == '}' && topChar != '{') balanced = false;
        if (c == ']' && topChar != '[') balanced = false;
        if (!balanced)
          break;
      }
    }
      
      int leftover = s.pop();
      if (leftover != -1)
    balanced = false;

    if (balanced)
      cout << argv[i] << ": Balanced" << endl << endl;
    else
      cout << argv[i] << ": Not Balanced" << endl << endl;
    
  }



   return 0;
}
