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
void shuffle(int []);
int draw(int [], int &);
int getrank(int);
int getsuit(int);


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
    char hit;
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
    makedeck(deck);
    
    //Shuffle Deck
    shuffle(deck);
    
    //Draw and display cards
    for(int i = 0; i < 11; i++)
    { phand[i] = 0;
      dhand[i] = 0;
    }
    
    int pcard = 0;
    phand[pcard] = draw(deck, topdeck); pcard++;
    phand[pcard] = draw(deck, topdeck); pcard++;
    
    int dcard = 0;
    dhand[dcard] = draw(deck, topdeck); dcard++;
    dhand[dcard] = draw(deck, topdeck); dcard++;
    
    cout<<"You have a "<<rank[getrank(phand[0])]<<" of "<<suit[getsuit(phand[0])]<<endl;
    cout<<"and a "<<rank[getrank(phand[1])]<<" of "<<suit[getsuit(phand[1])]<<endl;
    
    phand[0] = getrank(phand[0]);
    phand[1] = getrank(phand[1]);
    
    //Display total
    phand[0]++; phand[1]++;
    if( phand[0] > 10)
    {   phand[0] = 10;  }
    if( phand[1] > 10)
    {   phand[1] = 10;  }
    ptot = phand[0] + phand[1];
    
    cout<<"Your total is "<<ptot<<endl;
    if(phand[0] == 1)  //If user has an ace
    {   cout<<"or "<<ptot + 10<<endl;   }
    if(phand[1] == 1)
    {   cout<<"or "<<ptot + 10<<endl;   }
    cout<<endl;
    //Display one dealer card
    
    cout<<"Dealer has "<<rank[getrank(dhand[0])]<<" of "<<suit[getsuit(dhand[0])]<<endl;
    
    cout<<endl;
    //Dealer total
    dhand[0] = getrank(dhand[0]);
    dhand[1] = getrank(dhand[1]);
    dhand[0]++; dhand[1]++;
    
    if( dhand[0] > 10)
    {   dhand[0] = 10;  }
    if( dhand[1] > 10)
    {   dhand[1] = 10;  }
    dtot = dhand[0] + dhand[1];
    
    //Check for Blackjack
    cout<<endl;
    if ((phand[0] == 1) && (phand[1] == 10))
    {   cout<<"Winner winner chicken dinner! You got Blackjack!\n"; in<<"has won!"; in.close(); return 0; }
    if ((phand[1] == 1) && (phand[0] == 10))
    {   cout<<"Winner winner chicken dinner! You got Blackjack!\n";in<<"has won!"; in.close(); return 0; }
    if ((dhand[1] == 1) && (dhand[0] == 10))
    {   cout<<"Dealer has Blackjack! You lost\n"; in.close();in<<"has lost."; return 0; }
    if ((dhand[0] == 1) && (dhand[1] == 10))
    {   cout<<"Dealer has Blackjack! You lost.\n"; in.close(); in<<"has lost."; return 0; }
    
    //Player hit mechanics
    
    do
    {  cout<<"Your total is "<<setw(1)<<static_cast<int>(ptot)<<endl;
       do
       {   cout<<"Do you want to hit or stand?\n";
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
       {  phand[pcard] = draw(deck, topdeck);
          cout<<"You drew a "<<rank[getrank(phand[pcard])]
              <<" of "<<suit[getsuit(phand[pcard])]<<endl;
          
          phand[pcard] = getrank(phand[pcard]);
          phand[pcard]++;
          if (phand[pcard] > 10)
          { phand[pcard] = 10; }
          
          ptot += phand[pcard];  //New player total
          cout<<"Your new total is "<<ptot<<endl;
          pcard++;
       }
    } while ( hit == 'H' && ptot < 21);
    
    cout<<"You have "<<setw(1)<<static_cast<int>(ptot)<<endl;
    
    if ( ptot > 21 )
    {  cout<<"You bust, dealer wins.\n";
       cout<<"Better luck next time.\n";
       in<<"has lost.";
        return 0;
    }
    /*
    //Dealer hit mechanics 
    
    while ( dtot < 17 )
    {   cout<<"dealer hits\n";
        dhand[dcard] = draw(deck, topdeck);
        phand
    }
      
    cout<<"Dealer has "<<setw(1)<<dtot<<endl;
    if ( dtot > 21)
    {  cout<<"Dealer busts, you win!\n";in<<"has won!"; in.close(); return 0; }
    /*
    //Ending game, winning / losing
    
    if ( ptot > dtot )
    {  cout<<name<<" wins! Congratulations!\n"; in<<"has won!"; }
    if ( dtot > ptot )
    {  cout<<"Dealer wins, better luck next time.\n";in<<"has lost."; }
      
    if ( ptot == dtot)
    {  cout<<"Push, no winner.\n"; }
    
    in.close();
    //Delete Data
    */
    delete[] phand;
    delete[] dhand;
    
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

int draw(int deck[], int &decktop)
{   return deck[decktop--];  }

int getrank(int card)
{   return card % 13;   }

int getsuit(int card)
{   return card / 13;   }

