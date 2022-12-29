#include <iostream>
#include <cmath>
using namespace std;


void windchill(){
  int solution=0;
  int t=0;
  int v=0;

  
  for (int i=45;i>=-45;i-=5){
    if (i==45){
      cout<<"Ca ";

    }else{ 
    cout<<i<<" ";
    }
    
  }
  cout<<'\n';
  for(int k=5;k<=60;k+=5){
    if(k==5){
      cout << k << "  ";
    }else{
    cout<<k<<" ";}
    for(int z=40;z>=-45;z-=5){
      t=z;
      v=k;
      solution = 35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) +(.4275 * t * pow(v, 0.16));
      cout<<solution<<" ";
    }

   

      
    

  cout<<'\n';
    
  }


}
int main() {
  // question 9: --------------------------------------------------------
  windchill();
  
  return 0;
}