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
 * @return 0 on success, nonzero on error                                                                                                                                                           
 */
int main(){
  int numArgs = 0;
  char line[512];
  char* tokens[10];
  char* start;
  cin.getline(line, 512);
  cout << line << endl;
  start = strtok(line, " ");
  tokens[numArgs] = start;
  while(start != nullptr){
    tokens[numArgs] = start;
    numArgs++;
    start = strtok(nullptr, " ");
  } // while                                                                                                                                                                                        

  cout << "done parsing" << endl;
  cout << "num args: " << numArgs << endl;
  for(int i = 0; i < numArgs; i++){
    cout << tokens[i] << endl;
  } // for                                                                                                                                                                                          
  execvp(tokens[0], tokens);
  return 0;
} // main                                                                                                                                                                                           

