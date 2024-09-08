// exAmain.cpp
// Lab 1 - Exercise A
// Author - M. Moussavi

#include <iostream>
using namespace std;
#include "mystring.h"

int main(void)
{
  Mystring *ar[3];
  Mystring c = 3;
  ar[2] = &c;
  ar[1] = ar[0] = nullptr;
    
  // A BLOCK OF CODE BEGINS HERE
  {
    Mystring x[2];

    x[0].set_str("ENEL");
    x[1].set_str("0");
    Mystring* z = new Mystring("4");
      
    x[0].append(*z).append(x[1]);
  
    Mystring mars = x[0];

    x[1] = x[0];
    
    Mystring jupiter("White");

      ar[0] = new Mystring ("Yellow");

  } // BLOCK ENDS HERE

  c.set_str("A");
  delete  ar [0];
 
  Mystring d = "Green";
  
  cout << "\nProgram terminated successfully." <<endl;
  return 0;
}

