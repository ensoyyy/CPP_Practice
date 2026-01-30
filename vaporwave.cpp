#include <iostream>
#include <cctype>

std::string vaporcode(const std::string &str) {
  std::string VAPORWAVE = "";
  
  for( auto i : str ){
    if( i != ' ' ){
      VAPORWAVE += toupper( i );
      VAPORWAVE += "  ";
    }
  }
  
  return VAPORWAVE.substr(0,VAPORWAVE.length()-2);

}

int main(){

    std::string str = "\"M O E V - F Q\"";

    std ::cout << vaporcode(str) << "\n";
    
    return 0;
}