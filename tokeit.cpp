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
 *                                                                                                                                                                                                  
 */
int main(){
  int numArgs = 0;
  char line[512];
  /*  for(int i = 0; i < 10; i++){ // creating rows                                                                                                                                                 
    line[i] = new char[10];                                                                                                                                                                         
    } // for */
  char* start;
  cin >> line;
  start = strtok(line," ");
  numArgs++;
  while(start != NULL){
    cout << start << endl;
    numArgs++;
    start = strtok(NULL," ");
  } // while                                                                                                                                                                                        

  cout << "done parsing" << endl;
  cout << "num args: " << numArgs << endl;




} // main                                                                                                                                                                                           

