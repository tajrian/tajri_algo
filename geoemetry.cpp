//comparing two floating point number


//returns 1 if true and 0 if false
int compare_float(float f1, float f2)
 {
  float precision = 0.00001;
  /*
  You can set the precision of the comparison between the 
  floating point numbers by changing the "precision" variable.
  */
  
  if (((f1 - precision) < f2) && 
      ((f1 + precision) > f2))
   {
    return 1;
   }
  else
   {
    return 0;
   }
 }
 
 //return 1 if true, 0 if false
bool fequal(float a, float b)
{
 float epsilon=0.0000001;
 return fabs(a-b) < epsilon;
}
 
 
 //cos , sin , acos , asin
 
 #include <iostream>
#include <cmath>

using namespace std;

int main(){
    double degree,radian,rsin,rcos,isin,icos;
    cin>>degree;
    radian = degree*3.1416/180;
    rsin= sin(radian);
    isin= asin(rsin);
    rcos= cos(radian);
    icos= acos(rcos);//returns radian value;

    cout<<rsin<<endl;

    cout<<rcos<<endl;
    cout<<isin<<" "<<icos<<endl;
    degree = (isin*180)/3.1416;
    cout<<degree<<endl;


    return 0;

}




 
