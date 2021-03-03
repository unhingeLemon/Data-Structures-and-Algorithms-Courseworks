#include <iostream>
using namespace std;

bool isMember(int indx, int container[], int search);

int main()
{
  int index = 0;
  int serch;
  bool membcontainer = false;
  
  //asks the user to input how many integers wanted
  cout<<"Enter how many integers to input: ";
  cin>>index;
  int cont[index];
  
  //asks the user to input the integers
  for(int i=0; i<index; i++){
    cout<<"Enter the integers ["<<i+1<<"]: ";
    cin>>cont[i];
  }
  
   //displays the contents of the array cont[]
  cout<<"\nEntered integers: ";
  for(int i=0; i<index; i++){
    cout<< cont[i] << " ";
  }
  
 //asks the user what to be searched for
  cout<<"\nEnter the integer to be searched for: ";
  cin>>serch;
  
  membcontainer = isMember(0, cont, serch);
  
  //conditions if the searched integer is in the array
  if(membcontainer == true){
    cout<<"\nThe integer to be searched is: "<<serch;
    cout<<"\nThis integer CAN be found in the pool of integers.{|_/}";
    cout<<"\n                                                  (*-*)";
    cout<<"\n                                                   / >T^T\n";
  }else{
    cout<<"\nThe entered number to be searched "<<serch<<" CANNOT be found in the pool.";
  }
 return 0;
  
}

//method for recursive search
bool isMember(int indx, int container[], int search)
{
  if(container[indx] == '\0')
    return false; //returns false if the iteration is finished and if the array is empty
  else
  {
    if(container[indx] == search)
      return true; //returns true if the current integer is what to be searched for
    else
      return isMember(indx+1, container, search); //repeats the process if the current integer isn't what to be searched
  }
}
