/*
 * Person:
 * This class encapsulates a person within the Josephus circle.
 */

#pragma once

#include <iostream>

class Person {

	public: 
		// Constructor:
		// Note: A person object should be created only if there is a position available for that person to occupy. 
		//		And of course, no two people can occupy the same position, and 
		//		no person can occupy more than one position at any given time.
		// ...
		Person();
		Person(int &postion);

		// Destructor
		// ...
		~Person();
		
		// print the position
		void print();

		void operator=(Person &copy);
		
		int getPosition();

	private:
		int position;// position occupied by the person at any point of the game
						// Note: Because each position occupies a unique position initially, 
						// 		that initial position can also be treated as the identifier (id)
						//		or name for that person.
						//		And as the potato is passed around and people are eliminated,
						//			that id can be retained.
};
 