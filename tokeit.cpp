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
 * @return 0 if exec doesn't work                                                                                                                                                                   
 */
int main(){
  int numArgs = 0;
  char line[512]; //array to store input                                                                                                                                                            
  char* start;
  cin.getline(line, 512);
  char* argv[11]; //array to store each token                                                                                                                                                       
  start = strtok(line," "); //gets the first token                                                                                                                                                  
  char* cmd = start;
  argv[numArgs] = cmd; //sets the first index in the array to the command                                                                                                                           
  while(start != NULL){
    numArgs++;
    start = strtok(NULL," "); //gets each subsequent token                                                                                                                                          
    argv[numArgs] = start; //populates the arg array with the rest of the arguments                                                                                                                 
  } // while                                                                                                                                                                                        
  argv[numArgs+1] = (char*) NULL; //manually terminates the arguments                                                                                                                               
  cout << "done parsing" << endl;
  cout << "num args: " << numArgs << endl;
  for (int j = 0; j < numArgs; j++){
   cout << argv[j] << endl;
  } // for                                                                                                                                                                                          
  execvp(cmd, argv);
  perror("error exec'ing");
  return 0;
} // main                                   
