//  mystring.cpp
// Lab 1 - Exercise A
// Author - M. Moussavi

#include "mystring.h"
#include <string.h>
#include <iostream>
using namespace std;

Mystring::Mystring()
{ 
  charsM = new char[1];
  charsM[0] = '\0';
  lengthM = 0;
  cout << "\ndefault constructor is called. ";
}

Mystring::Mystring(const char *s)
  : lengthM((int)strlen(s))
{
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
  cout << "\nconstructor with char* argument is called. ";
}

Mystring::Mystring(int n): lengthM(0), charsM(new char[n])
{
    charsM[0] = '\0';
	cout << "\nconstructor with int argument is called. ";
    
    // POINT ONE
}

Mystring::Mystring(const Mystring& source):
  lengthM(source.lengthM), charsM(new char[source.lengthM+1])
{
    strcpy (charsM, source.charsM);
	cout << "\ncopy constructor is called. ";
}

Mystring::~Mystring()
{
    delete [] charsM;
	cout << "\ndestructor is called. ";
}

int Mystring::length() const
{
  return lengthM;
}

char Mystring::get_char(int pos) const
{
  if(pos < 0 && pos >= length()){
    cerr << "\nERROR: get_char: the position is out of boundary."; 
  }

  return charsM[pos];
}

const char * Mystring::c_str() const
{
  return charsM;
}

void Mystring::set_char(int pos, char c)
{
  if(pos < 0 && pos >= length()){
    cerr << "\nset_char: the position is out of boundary."
	 << " Nothing was changed.";
    return;
  } 

  if (c != '\0'){
    cerr << "\nset_char: char c is empty."
	 << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

Mystring& Mystring::operator =(const Mystring& S)
{
  if(this == &S)
    return *this;
  delete [] charsM;
  lengthM = (int)strlen(S.charsM);
  charsM = new char [lengthM+1];
  strcpy(charsM,S.charsM);

  cout << "\nassignment operator called. ";
  return *this;
}

Mystring& Mystring::append(const Mystring other)
{
  char *tmp = new char [lengthM + other.lengthM + 1];
  lengthM += other.lengthM;
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);
  delete []charsM;
  charsM = tmp;
    
  // POINT TWO
    cout << "append terminited...\n";
  return *this;
}

 void Mystring::set_str(const char* s)
{
    delete []charsM;
    lengthM = (int)strlen(s);
    charsM=new char[lengthM+1];
    strcpy(charsM, s);
}

int Mystring::isNotEqual (const Mystring& s)const
{

  return (strcmp(charsM, s.charsM)!= 0);
}

int Mystring::isEqual (const Mystring& s)const
{

  return (strcmp(charsM, s.charsM)== 0);
}

int Mystring::isGreater (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)> 0);
}

int Mystring::isLessThan (const Mystring& s)const
{
  return (strcmp(charsM, s.charsM)< 0);
}













