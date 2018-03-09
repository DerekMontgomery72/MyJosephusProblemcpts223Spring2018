#include"person.h"

/*This file will contain definitions for the member functions of the person class*/

// The default constructor for a person. It sets their position as -1 as this is impossible to be in the vector, or list
// as all entries have a positive position. The position is set to the proper position later in the functions that this is used.
Person::Person(){
	this->position = -1;
}//default constructor

/*
	This is the constructor most commonly used in the program. It is used in both the initialization of the vector and list. It sets
	the person's position as it is being entered into the list or vector.

*/
Person::Person(int &Position){
	this->position = Position;
}// constructor to be called. Will initialize the person, and assign them
 // a position

/*
The destructor does not need to be populated
*/
Person::~Person(){
	
}// No need to have any code in here

//Prints out the position of the person
void Person::print(){
	std::cout<<"This person is in postion "<<this->position<< std::endl;
}

/*
The GetPosition function is a getter for the member position in the person Class.
it was not necessary to create a setter for person as after the person is initialized their position remains
constan. The getter is used for printing the winner, or their position when they are eliminated from the game.

*/
int Person::getPosition(){
	return this->position;
}
// This is the overloaded operator for =. It simply sets the postion of the Person on the lhs of the = operator to that of the
// one on the rhs of the = operator.
void Person::operator= (Person &copy){
	this->position = copy.getPosition();
	
}