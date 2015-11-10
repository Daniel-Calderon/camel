// Name: Jesus Perez
// Name: Daniel Calderon
// Date: November 6, 2015
/*Camel Game Program: The goal of this games is t travel 200 hundred miles with natives following you. If they catch you, you lose the  game. Throughout the game you will face many dangers. Also you will have the ability to get to an oasis. Have fun playing the  game.
*/
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<cstdlib>
using namespace std;


void printWelcome();
char printChoice();
void choiceB(int& milesTraveled,int& thirst,int& nativeDistance,int& camelTiredness);
void choiceA(int& canteen, int& thirst);
int camelT();
int fullSpeed();
void meterorite( bool& done,int& storm);
void oasis(int& canteen,int& thirst,int& camelTiredness,int randCanteen,int numOasis);

int main()
{
    srand(time(0));
    printWelcome();
    int numOasis = rand () % 20 + 1;
    int storm = rand ( )% 1000000 + 1;
  
    int thirst = 0;
    int camelTiredness = 0;
    int milesTraveled = 0;
    int miles = 0;
    int distance = 0;
    int totalMiles = 0;
    int canteen = 0, randCanteen = 0;
    randCanteen = rand() % 10 + 1;
    canteen = randCanteen;
    int nativeDistance = -20;
  
    char choice;
    char upper;
    bool done = false;
  
    while(done == false)
    {
        choice = printChoice();
        upper = toupper(choice);

    switch(upper)
    {
        case 'A': 
                    meterorite( done,storm);
                    oasis(canteen,thirst,camelTiredness,randCanteen,numOasis);
                    choiceA(canteen,thirst);
        break;
        case 'B':
                    meterorite(done,storm);
                    oasis(canteen,thirst,camelTiredness,randCanteen,numOasis);
                    choiceB( milesTraveled, thirst, nativeDistance, camelTiredness);
        break;
              
        case 'C':
                    meterorite( done,storm);   
                    oasis(canteen,thirst,camelTiredness,randCanteen,numOasis);
                    cout <<" You chose to go full speed" << endl;
                    miles = fullSpeed();
                    totalMiles = miles + totalMiles;
                    thirst = thirst+1;
                    srand(time(0));
                    camelTiredness = rand()% 3 + 1;
                    distance = camelT();
                    nativeDistance = nativeDistance + distance;     
                    cout <<"The natives are " << abs(nativeDistance)<< " miles away!!"<< endl;
     break;
     case 'D':
                    meterorite( done,storm);      
                    oasis(canteen,thirst,camelTiredness,randCanteen,numOasis); 
                    cout <<" You chose to stop for the night" << endl;
                   distance = camelT();
                   nativeDistance = nativeDistance + distance;
                   cout << nativeDistance << endl;
                   camelTiredness = 0;
                   cout <<"The camel is happy because he got rest " << camelTiredness
                        << "the level of exhaustion that the camel has" << endl;
                        
        case 'E':   oasis(canteen,thirst,camelTiredness,randCanteen,numOasis);
                    cout << "You have traveled: " << milesTraveled<< endl;
                    cout << "You have a thirst of: " << thirst << endl;
                    cout << "You have " << canteen <<" drinks in your canteen " << endl;
                    cout << "Your camel is stage: " << camelTiredness <<" of tiredness" <<  endl;
         
        break;
        case 'Q': done = true;
        break;
        default: cout  <<" please enter valid characters" << endl;
        break;
    }
       if(thirst > 4)
        {
            cout << "You are thirsty" << endl;
        }
        if(thirst > 6)
        {
            cout << "You died of thirst" << endl;
            done =true;
            continue;
        }
        if(camelTiredness > 5)
        {
            cout << "Your camel is getting tired" << endl;
        } 
        if( camelTiredness > 8)
        {
            cout << "Your camel is dead" << endl;
            done= true;
            continue;
        }             
        if(nativeDistance == milesTraveled || nativeDistance > milesTraveled)
        {
            cout <<  "a" << nativeDistance << endl;
            cout << "b" << milesTraveled << endl;
            cout << "The natives caught you" << endl;
            done = true;
            //continue;
        }
        if((milesTraveled - abs(nativeDistance)) < 15  &&  (milesTraveled - abs(nativeDistance)) >=0 )
        {
            cout << "The natives are getting close!" << endl;
        }
        if(milesTraveled >= 200)
        {
            cout << "You won the game" << endl;
            done = true;
            
        }       
                
      if(milesTraveled ==  199)
        {
            cout << "You got bit by a snake just before you could escape!" << endl;
            done = true;
            
        }       
           cout <<"Total miles traveled: "<<totalMiles << endl;
             
 
    
    
  }
    return 0;
}
//*******************************************************************************************
void printWelcome()
{
    cout << "*******************************************************************" <<endl; 
    cout << "Welcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
    cout << "desert trek and out run the natives." << endl;
    cout << "*******************************************************************" << endl;
}
//*******************************************************************************************
char printChoice()
{
     char choice;
     
     cout << "These are your choices" << endl;
     cout << "A. Drink from your canteen." << endl;
     cout << "B. Ahead moderate speed." << endl;
     cout << "C. Ahead full speed." << endl;
     cout << "D. Stop for the night." << endl;
     cout << "E. Status check." << endl;
     cout << "Q. Quit." << endl;
     cout << "Pick Your Choice " ;
     cin >> choice;
     cout << "*******************************************************************"<< endl;
    return choice;
}
//*******************************************************************************************
void choiceB(int& milesTraveled,int& thirst,int& nativeDistance,int& camelTiredness)
{
    srand(time(0));
    int randNum=0,randNumB =0;
    randNum = rand( ) % 8 + 5;
    randNumB = rand( ) % 8 + 7;
    milesTraveled += randNum;
    thirst+=1;
    camelTiredness+=1;
    nativeDistance += randNumB;
    
}
//*******************************************************************************************
void choiceA(int& canteen, int& thirst)
{
    if(canteen <= 0)
    {
        cout << "error no more drink" << endl;
    }
    canteen -= 1;
    thirst = 0;
}
//*******************************************************************************************
void oasis(int& canteen,int& thirst,int& camelTiredness,int randCanteen,int numOasis )
{
    srand(time(0));
    int randNum;
    randNum = rand ()% 21 +1;
    if(numOasis == randNum)
    {
    canteen = randCanteen;
    thirst = 0;
    camelTiredness = 0;
    }
}
//*******************************************************************************************
int camelT()
{
     srand(time(0));
 
    int natives = 0;
    natives = rand() % 8 + 7;
    
    //cout <<" natives are " << natives <<  " miles away" << endl;
    return natives;
 
}
//********************************************************************************************
int fullSpeed()
{
     srand(time(0));
 
    int speed = 0;
    speed = rand() % 11 + 10;
    
    
    return speed;
}
//********************************************************************************************
void meterorite( bool& done,int& storm)
{
    srand(time(0));
    int randNum = rand() % 10000000 + 1;
    if( storm == randNum)
    {
        done = false;
    }

}




