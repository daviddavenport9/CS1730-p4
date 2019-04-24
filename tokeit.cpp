#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <dirent.h>
#include <string>

using namespace std;

/**                                                                                                                                                                                                 
 * This tokenizes user input in a 2d array. Then, it executes using the input.                                                                                                                      
 * @return 0 on success                                                                                                                                                                             
 */
int main(){
  int numArgs = 0;
  char line[512];
  char* tokens[11];
  char* start;
  cin.getline(line, 512);
  start = strtok(line, " ");
  while(start != (char *) NULL){
    tokens[numArgs] = start;
    numArgs++;
    start = strtok((char *) NULL, " ");
  } // while                                                                                                                                                                                        
  tokens[numArgs + 1] = (char *) NULL;
  cout << "done parsing" << endl;
  cout << "num args: " << numArgs << endl;
  for(int i = 0; i < numArgs; i++){
    cout << tokens[i] << endl;
  } // for                                                                                                                                                                                          
  execvp(tokens[0], tokens);
  perror("error execvp");
  return 0;
} // main                                                                                                                                                                                           



