#include<iostream>
using namespace std;
void search_array(float arr[],int no_elements,float element)
{    int flag=0;
    if(no_elements==0)
{        cout<<"Invalid, connot Search\n";
 exit;
}
 else
{ for(int i=0;i<no_elements;i++)
{ if(arr[i]==element)
{flag=1;
cout<<element<<" is found at "<<"position number: "<<(i+1)<<endl;
}
}
if(flag==0)
  {
cout<<"No element is here with value "<<element<<endl;
    }
    
}}
int main()
              {
    float arr[100];
    int i,f,s;
    cout<<"Enter the size of array : ";
    cin>>s;
    cout<<"Enter the elements of the array: "<<endl;
    for(i=0;i<s;i++)
    cin>>arr[i];
    cout<<"Enter the element you want to search : ";
    cin>>f;
    search_array(arr,s,f);
    cout<<endl;
    return 0;
                      }