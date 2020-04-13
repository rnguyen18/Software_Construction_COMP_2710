// Ryan Nguyen
// rmn0010
// hw5_rmn0010.cpp
// This program calculates a table that determines the amount of months taken to pay off a loan as well as printing out other attributes of the loan such as loan amount, loan payment, rate interest, and principal.
// I talked with someone who already took the course on how to structure and making a class.

# include <iostream>
# include <cstring>
# include <assert.h>
# include <cstdlib>
using namespace std;

//#define UNIT_TESTING

struct TriviaNode {
   string question;
   string answer;
   int points;
   TriviaNode *next;
};

class TriviaLine
  {
   public:
   int count;
   TriviaNode *head; 
   TriviaNode *root;
   TriviaLine()
   {
      count = 0;
      head = NULL;
      root = NULL;
   }
  };

/**
 * Sets up the hardcoded questions
 **/
void setupList(TriviaLine &questions) {
   TriviaNode *Question1 = new TriviaNode;
   TriviaNode *Question2 = new TriviaNode;
   TriviaNode *Question3 = new TriviaNode;

//Trivia Question 1
   Question1 -> question = "How long was the shortest war on record? (Hint: how many minutes)";
   Question1 -> answer = "38";
   Question1 -> points = 100;
   Question1 -> next = Question2;

//Trivia Question 2
   Question2 -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   Question2 -> answer = "Bank of Italy";
   Question2 -> points = 50;
   Question2 -> next = Question3;

//Trivia Question 3
   Question3 -> question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
   Question3 -> answer = "Tetris";
   Question3 -> points = 20;
   Question3 -> next = NULL;     

   questions.head = Question1;
   questions.root = Question3;
   questions.count += 3;
}

// Asks the question to the user depending on questionNumber and adds to points if correctly answered
int askQuestion(TriviaLine questions, int questionNumber, int &points) {
   TriviaNode *q = questions.head; 

   if (questionNumber < 1) {
      cout << "\nWarning - The number of trivia to be asked must equal to or be larger than 1.";
      return 1;
   }
   if (questionNumber > questions.count) {
      cout << "\nWarning - There are only " << questions.count << " trivia in the list";
      questionNumber = questions.count;
      return 1;
   }
   string ans;
   points = 0;

   for (int i = 0; i < questionNumber; i++) {
      cout << "\nQuestion: " << q -> question << "\nAnswer: ";
      getline(cin, ans);
   
      if (q -> answer == ans) {
         cout << "Your answer is correct. You receive " << q -> points << " points.";
         points += q -> points; 
      }    
      else {
         cout << "Your answer is wrong. The correct answer is: " << q -> answer;
      }
      cout << "\nYour total points: " << points << endl; 
      q = q -> next;
   }
   return 0; 
}

// This function adds user generated trivia questions 
void addQuestion(TriviaLine &questions){
   string Continue;
   do {
      questions.count++;
      TriviaNode *temp = new TriviaNode;
      
      cout << "Enter a question: ";
      getline(cin, temp -> question);
      
      cout << "Enter an answer: ";
      getline(cin, temp -> answer);
    
      cout << "Enter award points: ";
      cin >> temp -> points;
      cout << "Continue? (Yes/No): ";
      getline(cin.ignore(), Continue);
    
      questions.root -> next = temp;
      questions.root = temp;
        
   }
   while (Continue.find("Yes") != string :: npos);
}

/**
 * Tests askQuestion function
 **/
void test_askQuestion()
{
   TriviaLine questions;
   int points;
	
	// Setup Questions
   setupList(questions);

   cout << "\nFunction to test: int askQuestion(TriviaLine& questions, int i, int &points)\n";

   cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";
   assert(1 == askQuestion(questions, 0, points));
   cout << "\nCase 1 passed...\n";
	
	
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters the correct answer.\n";
   assert(0 == askQuestion(questions, 1, points));
   assert(100 == points);
   cout << "Case 2.1 passed...\n";

	cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
   assert(0 == askQuestion(questions, 1, points));
   assert(0 == points);
   cout << "Case 2.2 passed...\n";
	
   cout << "\nUnit Test Case 3.1: Ask all of the questions in the linked list. The tester enters the correct answers.\n";
   assert(0 == askQuestion(questions, 3, points));
   assert(170 == points);
   cout << "Case 3.1 passed...\n";

   cout << "\nUnit Test Case 3.2: Ask all of the questions in the linked list. The tester enters the incorrect answers.\n";
   assert(0 == askQuestion(questions, 3, points));
   assert(0 == points);
   cout << "Case 3.2 passed...\n";
   
   cout << "\nUnit Test Case 4: Attempt to ask 5 questions in the linked list. Program should give a warning message.\n";
   assert (1 == askQuestion(questions, 5, points));
   cout << "\nCase 4 passed...\n";
}

#ifdef UNIT_TESTING
	void test_askQuestion();
#endif

int main() {
   //Unit testing Code
     #ifdef UNIT_TESTING
	cout << "*** This is a debugging version ***\n";
	test_askQuestion();
	cout << "\n*** End of the debugging version ***\n";

 //Production Code   
    #else
   cout << "*** Welcome to Ryan's trivia quiz game ***" << endl;
   TriviaLine game;
   int points;
   setupList(game);
   addQuestion(game);
    
   cout << "\n..." << endl;
    
   askQuestion(game, game.count, points);
    
   cout << "\n..." << endl;    

   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    
    #endif
   return 0;
}
