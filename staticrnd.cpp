#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sstream>

class Something
{
private:
  static int s_nValue;
  static std::string s_str;
public:
	static std::string generator(){
	
  /* initialize random seed: */
  srand (time(NULL));

	unsigned long long most = rand(), least = rand();
	unsigned long long haha = (most << 32ULL) + least;

	std::string number;
	std::stringstream strstream;
	strstream << haha;
	strstream >> number;

	return number.c_str();
	}	

  static int GetValue() { return s_nValue = 2; }
	static std::string getStr() {return s_str=generator();}
};
 
int Something::s_nValue = 1; // initializer
std::string Something::s_str; 

int main ()
{

  for ( int i =0; i < 5; i++)
  {
    std::cout << Something::GetValue() << std::endl;
    std::cout << Something::getStr() << std::endl;
  }

  std::cout << "hej" << std::endl;

return 0;
}

