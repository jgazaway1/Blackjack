/* 
 * File:   main.cpp
 * Author: John Gazaway
 * Created on December 7 2018, 3:37 PM
 * Purpose:  Blackjack 2 version 1
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cstdlib>  //Random number generator
#include <ctime>   //Random seed
#include <cstring> //String Library
#include <fstream> //Files
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

void makedeck(int []);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed
    
    srand(static_cast<unsigned int>(time(0)));
    
    //Arrays for deck
    
    string suit[] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };
    string rank[] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
                      "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN",
                      "KING" };
    int *phand;
    phand = new int[10];
    int *dhand;
    dhand = new int[10];
    
    //Declare Variables
    
    string name;
    fstream in;
    float ptot, dtot;
    bool val;
    
    ptot=dtot=0;
    //Initial Variables
    
    cout<<"Welcome to Blackjack!\n";
    cout<<"Enter your name.\n";
    getline(cin, name);
    
    in.open ("name.dat");
    in<<name<<endl;
    
    //Make deck
    
    int deck[52];
    int topdeck = 51;
    
    //Check for Blackjack
    
    if ((pcard1 == 1) && (pcard2 == 11 || pcard2 == 12 ||
         pcard2 == 13 || pcard2 == 10))
    {   cout<<"Winner winner chicken dinner! You got Blackjack!\n"; in<<"has won!"; in.close(); return 0; }
    if ((pcard2 == 1) && (pcard1 == 11 || pcard1 == 12 ||
         pcard1 == 13 || pcard1 == 10))
    {   cout<<"Winner winner chicken dinner! You got Blackjack!\n";in<<"has won!"; in.close(); return 0; }
    if ((dcard1 == 1) && (dcard2 == 11 || dcard2 == 12 ||
         dcard2 == 13 || dcard2 == 10))
    {   cout<<"Dealer has Blackjack! You lost\n"; in.close();in<<"has lost."; return 0; }
    if ((dcard2 == 1) && (dcard1 == 11 || dcard1 == 12 ||
         dcard1 == 13 || dcard1 == 10))
    {   cout<<"Dealer has Blackjack! You lost.\n"; in.close(); in<<"has lost."; return 0; }
    
    //Calculate value of player hand
    
    if (pcard1 == 11 || pcard1 == 12 || pcard1 == 13)
    { ptot = pcard2 + 10; }
    else if (pcard2 == 11 || pcard2 == 12 || pcard2 == 13)
    { ptot = pcard1 + 10; }
    else if ((pcard1 == 11 || pcard1 == 12 || pcard1 == 13) &&
        (pcard2 == 11 || pcard2 == 12 || pcard2 == 13))
    { ptot = 20; }
    else { ptot = pcard1 + pcard2; }
    
    //Seeing if player wants ace to be 1 or 11
    if ( pcard1 == 1 || pcard2 == 1)
    { cout<<"Your current total is "<<setw(1)<<ptot<<endl;
      cout<<"Do you want your ace to equal 11?\n";
      cout<<"Enter 'Y' for yes or 'N' for no.\n";
      cin>>ace;
      if ( ace == 'Y')
      {   ptot += 10;
          cout<<"Your total is "<<setw(1)<<ptot<<endl;
      }
      if ( ace == 'N' )
      {   cout<<"Your total is "<<setw(1)<<static_cast<int>(ptot)<<endl; }
    }
    
    cout<<endl;
    
    //Calculate value of dealer hand
    
    if (dcard1 == 11 || dcard1 == 12 || dcard1 == 13)
    { dtot = dcard2 + 10; }
    else if (dcard2 == 11 || dcard2 == 12 || dcard2 == 13)
    { dtot = dcard1 + 10; }
    else if ((dcard1 == 11 || dcard1 == 12 || dcard1 == 13) &&
        (dcard2 == 11 || dcard2 == 12 || dcard2 == 13))
    { dtot = 20; }
    else { dtot = dcard1 + dcard2; }
    
    //Dealer always treats ace as 11
    if (dcard1 == 1 || dcard2 == 1)
    { dtot += 10; }
    
    //Player hit mechanics
    
    do
    {  cout<<"Your total is "<<setw(1)<<static_cast<int>(ptot)<<endl;
       do
       {  cout<<"Do you want to hit or stand?\n";
          cout<<"Enter 'H' or 'S' respectively.\n";
           cin>>hit;

            if ( hit == 'H' || hit == 'S')
            { val = true; }
            else
            { cout<<"That is not a valid input.\n"; 
              val = false; 
            }
        }while ( val != true);
       if (hit == 'H')
       {  hitcard = rand() % 13 + 1;
            switch (hitcard)
            {  case 1 : ptot += 1; break;
               case 2 : ptot += 2; break;
               case 3 : ptot += 3; break;
               case 4 : ptot += 4; break;
               case 5 : ptot += 5; break;
               case 6 : ptot += 6; break;
               case 7 : ptot += 7; break;
               case 8 : ptot += 8; break;
               case 9 : ptot += 9; break;
               case 10 : ptot += 10; break;
               case 11 : ptot += 10; break;
               case 12 : ptot += 10; break;
               case 13 : ptot += 10; break;
            }
        }
    } while ( hit == 'H' && ptot < 21);
    
    cout<<"You have "<<setw(1)<<static_cast<int>(ptot)<<endl;
    
    if ( ptot > 21 )
    {  cout<<"You bust, dealer wins.\n";
       cout<<"Better luck next time.\n";
       in<<"has lost.";
        return 0;
    }
    
    //Dealer hit mechanics 
    
    while ( dtot < 17 )
    { hitcard = rand() % 13 + 1;
            switch (hitcard)
            {  case 1 : dtot += 1; break;
               case 2 : dtot += 2; break;
               case 3 : dtot += 3; break;
               case 4 : dtot += 4; break;
               case 5 : dtot += 5; break;
               case 6 : dtot += 6; break;
               case 7 : dtot += 7; break;
               case 8 : dtot += 8; break;
               case 9 : dtot += 9; break;
               case 10 : dtot += 10; break;
               case 11 : dtot += 10; break;
               case 12 : dtot += 10; break;
               case 13 : dtot += 10; break;
            }
            cout<<"Dealer hit.\n";
    }
      
    cout<<"Dealer has "<<setw(1)<<dtot<<endl;
    if ( dtot > 21)
    {  cout<<"Dealer busts, you win!\n";in<<"has won!"; in.close(); return 0; }
    
    //Ending game, winning / losing
    
    if ( ptot > dtot )
    {  cout<<name<<" wins! Congratulations!\n"; in<<"has won!"; }
    if ( dtot > ptot )
    {  cout<<"Dealer wins, better luck next time.\n";in<<"has lost."; }
      
    if ( ptot == dtot)
    {  cout<<"Push, no winner.\n"; }
    
    in.close();
    //Exit program!
    return 0;
}

void makedeck(int deck[])
{   for( int i = 0; i < 52; i++)
    deck[i] = i;
}

void shuffle(int deck[])
{   for(int i = 0; i < 100; i++)
    {int index1 = rand () % 52;
     int index2 = rand () % 52;
    
     int temp = deck[index1];
     deck[index1] = deck[index2];
     deck[index2] = temp;
    }
}

string draw(int deck[], int &decktop)
{   
    
}