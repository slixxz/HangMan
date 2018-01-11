// File : Proj2
// Project : CS 115 Project 2 - Hangman
// Author : David Smith
// Date : Fall 2010
// Description : Hangman 

#include <iostream>
using namespace std;

const int MAX_MISSES = 9;  // constant to hold maximum number of misses
string GetSecretWord ();   // Prototype for function to get a secret word
void Display (int misses); // Prototype for function to display the gallows
string ToUpper (string s);
string makeblanks (int num);

int main ()
{
  string blanks;  
  int misses;
  cout << " Welcome to my Hangman program. " << endl;
  cout << "To play Hangman you must guess letters for an unkown word." <<endl
  << "The goal of the game is to figure out what the secret word is." << endl
       << "Guess letters to the word, If you guess wrong your closer to becoming a dead man, watch out!!!! " << endl;
  cout << " Are you ready? enter yes or no " << endl; 
  string YorN; 
  cin >> YorN;
  while (ToUpper(YorN)== "YES")
    {
      misses = 0;
      string bad;
      char guess;
      string word = GetSecretWord();
      int good = word.size();
      blanks = makeblanks (word.size());        
      cout<< endl;
      /*missing code*/
      bool found;
      while (good > 0 && misses < MAX_MISSES)
	{ 
	  found=false;
	  Display (misses);
	  for (int i=0; i<blanks.size();i++){
	    cout<<blanks[i]<<' ';
	  }  
	  cout<<endl;
	  cout<< "These guesses are wrong: " << bad <<endl;
	  cout<< "Enter a letter ";
	  cout<< endl; 
	  cin>> guess;
	  guess=toupper (guess);
	
	  for(int i=0;i<word.size();i++ ) 
	    {
	      if (word[i] == toupper(guess))
		{
		  good--;
		  blanks[i]=guess; /*replace blank with secrete word letter*/
		  found=true;

		}
	    }
	     

	  if (found==false){
	    misses++;
	    bad+=guess;
	  }
	}
    
      if (misses == MAX_MISSES){
    	cout<<" Sorry you died. "<< endl;
      }
      else{ 
	cout<<"You are the winner! "<<endl;
      }      
      Display (misses);       
    
/*check to see if misses equals MAX_MISSES and if so the then sorry they lost else say the won
then ask if they want to play again
      */ 
      cout<< "the secrete word was: " << word << endl;
      cout<< "Do you want to play again? "<<endl;
      cout<< "Enter yes or no. "<<endl;
      
      cin>>  YorN;
    }
  return 0;
}

#include <ctime>
#include <fstream>
#include <cstdlib>

string ToUpper(string s){
  string r=s;
  for (int i=0; i<s.size(); i++) 
    r[i]= toupper(s[i]);
  return r;  
}

string makeblanks (int num)
{ string b;
  for (int i=0; i<num;i++)
    {      
      b+='_';
    } 
  return b;
}



string GetSecretWord ()
// This function will get a word from the secret word file
{
  // Declare and open the file of secret words
  ifstream file ("/home/faculty/tiawatts/cs115pickup/p2words.txt");
  // Declare a varaible to hold the number of words
  int numwords = 1;
  // Declare a varaible to hold a random number
  int whichword = 0;
  // Declare a variable to hold the selected word
  string word = "RANDOM";
  // Initialize the random number generator
  srand (time (NULL));
  // Read in the number of words
  file >> numwords;
  // Calculate a random number >= 0 amd < the number of words
  whichword = rand() % numwords;
  // Loop to read the file
  do
    {
      // Read a word from the file
      file >> word;
      // Decrement the counter
      whichword--;
      // Stop reading when the counter hits 0
    } while (whichword > 0);
  // Close the file
  file.close();
  // Return the selected word
  return word;
}

void Display (int misses)
// This function will print the hangman gallows
{
  // Declare and initialize the display
  string display [] = {"       |------|       ",
		       "       |      |       ",
		       "       O      |       ",
		       "      /|\\     |       ",
		       "       |      |       ",
		       "      / \\     |       ",
		       "     /   \\    |       ",
		       "              |       ",
		       "            -----     ",
		       "            |   |     ",
		       "          ---------   ",
		       "          |       |   "};

  // Block out the parts of the display that are not needed
  if (misses < 1)
    display [2][7] = ' ';
  if (misses < 2)
    display [3][7] = ' ';
  if (misses < 3)
    display [3][6] = ' ';
  if (misses < 4)
    display [3][8] = ' ';
  if (misses < 5)
    display [4][7] = ' ';
  if (misses < 6)
    display [5][6] = ' ';
  if (misses < 7)
    display [5][8] = ' ';
  if (misses < 8)
    display [6][5] = ' ';
  if (misses < 9)
    display [6][9] = ' ';
  // Print the lines of the display
  for (int i = 0; i < 12; i++)
    cout << display[i] << endl;
}
