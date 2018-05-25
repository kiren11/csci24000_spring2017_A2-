#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <ctime>   // to seed a random number
#include <iomanip> //library to put spaces between A and B
#include <unistd.h> //library to use sleep function to make it look cooler

//“Honor Pledge: I pledge that I have neither given nor received any help on this assignment"

#define RACE_LENGTH 50 //static variable, race length

void advanceRacerA(int *);
void advanceRacerB(int *);
void printPosition(int *, int *);

//Player A function
void advanceRacerA(int* ptrRacerA) {

    //num1 will store the random number generated
    int num1 = rand() % 50 + 1;

    //Moves pointer for each player according to probability
    //Probability calculated by dividing the percentage by 50
    //Values of pointers are then changed to symbolize the direction they are moving

    if (num1 <= 14 && num1 >= 0) {
        (*ptrRacerA += 4);       //run elements
    }

    else if (num1 >= 15 && num1 <= 19) {
        (*ptrRacerA += 5);       //sprint elements
    }

    else if (num1 >= 20 && num1 <= 34) {
        (*ptrRacerA -= 2);       //fall in mud elements
    }

    else if (num1 >= 35 && num1 <= 45) {
        (*ptrRacerA -= 3);       //fall off rope
    }

    else {
        (*ptrRacerA -= 4);      //fall off monkey bars
    }

    //If the pointer for player A ever goes negative, it'll start from 1 again
    //And if the pointer tries to go past 50, it'll simply end at 50
    if (*ptrRacerA < 1) {
       *ptrRacerA = 1;
    } else if (*ptrRacerA > RACE_LENGTH) {
      *ptrRacerA = RACE_LENGTH;
    }
}

//Player B function
void advanceRacerB(int* ptrRacerB) {

    //num2 is used to store the random number generated
    int num2 = rand() % 50 + 1;

    if (num2 <= 20 && num2 >= 0) {
        (*ptrRacerB += 5);       //run elements
    }

    else if (num2 >= 21 && num2 <= 25) {
        (*ptrRacerB += 6);       //sprint elements
    }

    else if (num2 >= 26 && num2 <= 35) {
        (*ptrRacerB -= 1);       //fall in mud elements
    }

    else if (num2 >= 36 && num2 <= 45) {
        (*ptrRacerB -= 2);       //fall off rope elements
    }

    else {
        (*ptrRacerB -= 4);       //fall off monkey bars elements
    }

    //same as player A
    if (*ptrRacerB < 1) {
       *ptrRacerB = 1;
    } else if (*ptrRacerB > RACE_LENGTH) {
       *ptrRacerB = RACE_LENGTH;
    }
}


//function to print player's positions
void printPosition(int* ptrRacerA, int* ptrRacerB) {

      //If both Player A and Player B land on the same spot, player A will move back a spot
      if (*ptrRacerA == *ptrRacerB) {
        (*ptrRacerA -= 1);
        std::cout<<std::setw(*ptrRacerA)<<"A";            //setw used to put in the spaces
        std::cout<<std::setw(*ptrRacerB - *ptrRacerA)<<"B";
        std::cout<<std::setw((RACE_LENGTH + 1) - *ptrRacerB)<<"|"; //used to print finish line ( + 1 added so when B "touches" the finish line, it symbolizes the end of the race)

      } else if (*ptrRacerA < *ptrRacerB) {                 //If A's position is less than B, A will print
        std::cout<<std::setw(*ptrRacerA)<<"A";       //setw used to put in the spaces
        std::cout<<std::setw(*ptrRacerB - *ptrRacerA)<<"B"; //B's spot is ahead so it will be A's spot subtracted
        std::cout<<std::setw((RACE_LENGTH + 1) - *ptrRacerB)<<"|";
      } else {
        std::cout<<std::setw(*ptrRacerB)<<"B";
        std::cout<<std::setw(*ptrRacerA - *ptrRacerB)<<"A";
        std::cout<<std::setw((RACE_LENGTH + 1) - *ptrRacerA)<<"|";
      }
        std::cout<<" \n"<<std::endl; //goes to next line
}



int main() {
      std::cout<<"Welcome to Kiren's Racer Program!"<<std::endl;
      std::cout<<"READY...SET...GO!"<<std::endl;

      //initializes the pointers to the value of zero for start
      int A = 0;
      int B = 0;
      int counter = 0;

      //seed random number
      srand(time(NULL));

    //while loop that will keep running til the end of race length
    while (A != RACE_LENGTH && B != RACE_LENGTH) {
      //passes in the address into both of the functions
      advanceRacerA(&A);
      advanceRacerB(&B);
      printPosition(&A, &B);
      usleep(100000); //in microseconds, used to sleep between each line of output
      counter++;
      }

      //To see who won
      //If Player A reaches 50 first, the following will print, otherwise the latter
      if (A > B) {
        std::cout<<"You won!! Training does really pay off."<<std::endl;
      }
      else {
        std::cout<<"Your friend won, looks like you have to train harder for next time."<<std::endl;
      }

}
