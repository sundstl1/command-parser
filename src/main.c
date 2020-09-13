#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "help.h"

int spaceToNull(char* string)
{
  int subStrings = 0;
  int length =strlen(string);
  for (int i = 0; i < length; i++)
  {
    if (string[i] == ' '){
      string[i] = '\0';
      subStrings++;
    }
  }
  return subStrings;
}

void readUserInput(char * buffer, int bufferSize)
{
  fgets(buffer, bufferSize, stdin);

  //Clear trailing whitespace
  int i = strlen(buffer)-1;
  while(i > 0)
  {
    if (isspace(buffer[i]))
    {

      buffer[i--] = '\0';
    }
    else
    {
      break;
    }
  }
}

int main() {
   const int BUFFERSIZE = 256;
   char readBuffer[BUFFERSIZE];
   int parameters;
   while (1)
   {
     printf("Enter command\n");
     readUserInput(readBuffer, BUFFERSIZE);
     parameters = spaceToNull(readBuffer);
     int command = commandIdentifier(readBuffer);
     if (command == 2)
     {
       help(&readBuffer[strlen(readBuffer)+1], parameters);
     }
     if (command == 1)
     {
       printf("Exiting...\n");
       break;
     }
 }
   return 1;
}
