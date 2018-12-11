/* 
 * File:   main.cpp
 * Author: John Gazaway
 * Created on May 29th, 2018, 11:20 AM
 * Purpose:  CPP Template
 *           To be copied for each project
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes

void makedeck(int []);
void shuffle(int []);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    string suit[] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };
    string rank[] = { "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
                      "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN",
                      "KING" };
    
    //Make deck
    
    int deck[52];
    int topdeck = 51;
    makedeck(deck);
    
    //Shuffle Deck
    
    shuffle(deck);
    
    for(int i = 0; i < 52; i++)
    {   cout<<deck[i]<<endl;
        
    }
    
    return 0;
}

void makedeck(int deck[])
{   for( int i = 0; i < 52; i++)
    deck[i] = i;
}

void shuffle(int deck[])
{   for(int i = 0; i < 100; i++)
    {int num1 = rand () % 52;
     int num2 = rand () % 52;
    
     int temp = deck[num1];
     deck[num1] = deck[num2];
     deck[num2] = temp;
    }
} 