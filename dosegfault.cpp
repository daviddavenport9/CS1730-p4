/**                                                                                                                                                                                                 
 * This does a segmentation fault automatically to test launcher.cpp                                                                                                                                
 * @returns 0 on success                                                                                                                                                                            
 */
using namespace std;
int main(){
  int* ptr = nullptr;

  *ptr = 5;

  return 0;
} // main                                                                                                                                                                                           



