/* This is where all member function of ListMyJosephus will be defined.*/

#include "ListMyJosephus.h" //Include header file for class ListMyJosephus


/*Default constructor for ListMyJosephus. If no m or n values are 
 * passed in the values will automatically be assigned a value of 0.
 * There is no need to edit the list as its default constructor should
 * be implicitly called when the object is created. Making an empty list.
 */
ListMyJosephus::ListMyJosephus(){
	this->M = 0;
	this->N = 0;
	//this->circ();
}
/*Main constructor for list my Josuphus. Assigns passed in M and N
 * Values to the private members, and constructs the list circ with 
 * lists default constructor. Creating an empty list to be used within the
 * program */
ListMyJosephus::ListMyJosephus(int M, int N){
	this->M = M;
	this->N = N;
	this->size = M;
	//this->circ();
	
	Person *temp = NULL;
	int counter = M -1;
	while(counter >= 0){
		temp = new Person(counter);
		this->circ.push_front(*temp);
		
		counter--;
	}
}
/*
The destructor for the list implamentation. It will clear the list and set the other members to 0.
*/
ListMyJosephus::~ListMyJosephus(){
	this->clear();
	this->M = 0;
	this->N = 0;
	this->size = 0;
}

/*
This function is used to initialize the list if the default constructor was used. It will populate the list and set the other members to
their proper values.
*/
void ListMyJosephus::init(int N, int M)
{
	this->M = M;
	this->N = N;
	this->size = M;
	//this->circ();

	Person *temp = NULL;
	int counter = M - 1;
	while (counter >= 0) {
		temp = new Person(counter);
		this->circ.push_front(*temp);

		counter--;
	}
}
/*
Clear function is used to empty the list
*/
void ListMyJosephus::clear(){
	circ.clear();
}
/*
Used to find the current size of the list
*/
int ListMyJosephus::currentSize(){
	return circ.size();
}
/*

*/
bool ListMyJosephus:: isEmpty(){
	if(!circ.empty()){
		return false;
	}
	else{
		return true;
	}
}

list<Person>::iterator ListMyJosephus::eliminateNext( list<Person>::iterator &pos){
	Person NextToBeEliminated;
	std::list<Person>::iterator it = pos;
	int itCount = 0;
	while(itCount != N){
		it++;
	if(it == circ.end()){
		it = circ.begin(); //Set the iterator back to the beginning of the list
	}
	itCount++;
	}
	
	NextToBeEliminated = *it;
	it = circ.erase(it);
	//cout << "The person at position " << NextToBeEliminated.getPosition() << " was eliminated" << endl;
	if (it == circ.end()) {
		it = circ.begin();
	}
	this->size--;
	
	return it;
}


void ListMyJosephus::printAll(){
			for(std::list<Person>::iterator it = circ.begin();it != circ.end(); ++it)
		{
			it->print();
		}
}

void ListMyJosephus::runGame() {
	bool gameDone = false;
	list<Person>::iterator it = circ.begin();
	double totalTime = 0.0, averageTime = 0.0;
	clock_t k = clock();
	clock_t start;
	while (gameDone != true) {
		do {
			start = clock();
		} while (start == k);
		it = eliminateNext(it);
		clock_t end = clock();
		totalTime = double(end - start) + totalTime;
		gameDone = this->isWinner();
	}
	averageTime = totalTime / (M - 1);
	cout << "Average time for elimination for List is " << double((averageTime / CLOCKS_PER_SEC)) << " seconds." << endl;
}

bool ListMyJosephus::isWinner() {
	if (circ.size() == 1) {
		cout << "The Winner of this round is " << circ.begin()->getPosition() << "." << endl;
		return true;
	}
	else {
		return false;
	}
}