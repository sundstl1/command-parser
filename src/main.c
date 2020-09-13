#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int commandIdentifier(const char* command)
{
    const int commandListLength = 3;
    const char* commandList[] = {
      "exit\0 1",
      "help\0 2",
      "test\0 43"
    };
    for (int i = 0; i < commandListLength; i++)
    {
      if (!strcmp(command, commandList[i]))
      {
        return atoi(&commandList[i][strlen(commandList[i])+1]);
      }
    }
    return -1;
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
     printf("command: %d, substrings: %d\n", command, parameters);
     if (command == 1)
     {
       printf("Exiting...\n");
       break;
     }
 }
   return 1;
}
