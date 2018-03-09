#include "VectorMyJosephus.h"

/* The default constructor. It will initialize the VectorMyJosephus
 * Class. It will set the members of M,N, and size to 0. The vector
 * default constructor should implicitly be called.
 * Precondition: 
 * Postcondition: An object of VectorMyJosephus will be created*/
VectorMyJosephus::VectorMyJosephus(){
	this->M = 0;
	this->N = 0;
	this->size = 0;
}

/* The constructor that will mostly be called. It will have M players,
 * and N passed until next elimination. It will initalize the vector
 * with all of the players in the vector at the beginning. It will 
 * create a new object of Person for each entry using a pointer to 
 * a Person object.
 * Precondition: M and N need to be passed in and declared in the scope
 * outside of the class. 
 * Postcondition: An object of VectorMyJosephus will be created with
 * a fully filled vector.
 */
VectorMyJosephus::VectorMyJosephus(int M, int N){
	this->M = M;
	this->N = N;
	this->size = M;
	Person *temp = NULL;
	for(int it = 0; it < size; it++ ){
		temp = new Person(it);
		circ.push_back(*temp);
	}
}
/*
	The destructor which is implicitly called when the vector goes out of scope. It uses the clear function to eliminate
	all elements inside of the vector, and then sets M, N, and size to 0.
	Precondition: A fully filled VectorMyJosephus object exists in the scope.
	Postcondition: The object will be destroyed

*/
VectorMyJosephus::~VectorMyJosephus(){
	this->clear();
	this->M = 0;
	this->N = 0;
	this->size = 0;
}
/*
	The initializer for if a vector is created without M and N being passed in. This function is used to 
	create the circ vector assign M, N, and size with the correct values so that the object can be used 
	to run the game.
	precondition: An object of VectorMyJosephus exists but does not have correct M, N or circ values yet

	Postcondition: The object will be filled with the correct values needed in the vector and other members.
*/
void VectorMyJosephus::init( int N, int M){
	this->M =M;
	this->N = N;
	this->size = M;
		Person *temp = NULL; // declare a null pointer to a person so that many can be created when they are needed
	for(int it = 0; it < size; it++ ){
		temp = new Person(it); // creating a new person and allocating memory for that person in memory
		circ.push_back(*temp); // placing the new person into the vector
	}
}
/*
The clear function will use vector's member function clear to erase all contents from circ
It will only be used in the destructor. Although it could be implemented to allow for multiple runs
of the program, allowing a person to run the program clear the contents of the vector, and then set a new M, and N value to run it again.
Precondition: The object is fully initialized with a full circ vector. 
PostCondition: The circ vector within the object will be empty.
*/
void VectorMyJosephus::clear(){
	circ.clear(); //Using vector's member clear to empty the vector
}

/*
Will use vector's member function size to return the size of the current vector.
Is important for checking if the game is complete. 
Precondition: A VectorMyJosephus object must already exist.
Postcondition: Will return the size of the circ vector.
*/
int VectorMyJosephus::currentSize(){
	return circ.size();
}

/*
Uses the empty member function of Vector to check if the circ vector is empty
Precondition: An object of VectorMyJosephus must be declared.
Postcondition: The function will return a bool. True if the vector is empty, and false if the vector is not empty

This function could be useful for error analasis, but currently is not called anywhere in the program.

*/
bool VectorMyJosephus::isEmpty(){
	return circ.empty();
}
/*This function will find and erase the next person that will be
 * eliminated. It uses an integer counter to move through the vector
 * and move to the next N. It will need to have the position of the
 * previous person that was eliminated passed in so that it can find the
 * correct position.
 * Precondition: The vector needs to be initialized
 * Postcondition: A person in the vector will be removed
 * complexity: O(N). If the person being removed is at the front
 * of the vector it will have to shift all other items to the right using
 * vector's member funtion remove()*/
int VectorMyJosephus::eliminateNext(int &lastEliminated){
	int count = 0, pos = lastEliminated;
	Person eliminateNext;
	while(count != this->N)
	{
		pos++;
		if(pos >= size){
			pos = 0;
		}
		count++;
		
	}
 	eliminateNext = circ[pos];
	//cout<<"The Person at position "<<eliminateNext.getPosition()<<" was eliminated"<< endl;
	circ.erase(circ.begin() + pos);
	this->size--;
	if (pos >= size) {
		pos = 0;
	}
	return pos;
	
	
}
/*
	The printAll function prints all items within the circ vector using a counter, and a while loop.
	Precondition: The circ vector must be initialized, and the member size must be the same as the actual size of the vector.
	Otherwise it will go too far out of range and break.
	Postcondition: Will print all items within the vector.

	Useful for debugging and initial tests
*/
void VectorMyJosephus::printAll(){
	int it = 0;
	
	while(it < size){
		circ[it].print();
		it++;
		
	}
}
/*
	The runGame function is used as a container for the vector implementation
	of the Josephus problem game. It keeps track of the average time for each deletion, and 
	calls the deletion as well. Each time the program moves through the loop within the function
	it will track total time for deletions, delete the next person in the vector, and then check if the
	game is over. It will then calculate and print the average time for the deletions.
	Precondition: The Object must first be initialized
	Postcondition: The game will run, and at the end only one item will remain in the circ vector. That item will be the 
	winner of the game.

	Efficient for a lower number of entries, and high number of passes before elimination, but as more entries are in the vector
	it slows. Due to the time it takes to erase objects from the front of the list. With a lower number of passes the function will
	have to delete more items closer to the front of the vector. Making it slightly inefficient. 

*/
void VectorMyJosephus::runGame(){
	bool gameDone = false;
	int pos = 0;
	double totalTime = 0.0, averageTime = 0.0;
	clock_t k = clock();
	clock_t start;
	while(gameDone != true){
		do {
			start = clock();
		} while (start == k);
		pos = eliminateNext( pos );
		clock_t end = clock();
		totalTime = double(end - start) + totalTime;
		gameDone = this->isWinner();
	}
	averageTime = totalTime / (M - 1);
	cout << "Average time for elimination for List is " << double((averageTime / CLOCKS_PER_SEC)) << " seconds." << endl;
}

/*
	The isWinner function is used to check if the game is over yet. It checks to see if there is one or more entries in the vevtor.
	If there are more than one entry in the vector than the game is not yet over, and will continue. If there is only one Person left in the
	Vector however the function will print out their position as they are the winner of the game.
	Precondition: The object must be initialized, and the game ready to be played.
	Postcondition: Will print out the winner, and will return true. Allowing the game to end.
*/
bool VectorMyJosephus::isWinner(){
	if(circ.size() == 1){
		//circ[0].print();
		cout << "The person at position "<<circ[0].getPosition()<<" wins the game" << endl;
		return true;
	}
	else{
		return false;
	}
}

