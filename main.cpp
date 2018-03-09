#include"TestListMyJosephus.h"
#include"TestVectorMyJosephus.h"
using namespace std;
/*
	Programmer: Derek Montgomery
	Class: cpts 223
	Project: MyJosephus Problem PA1/HW2
	Most Recently Modified on 2/5/2018

	Description: This program uses two implementations of the Josephus problem. Where M Players pass a ball N times before
	somebody is eliminated. They will then continue to pass the ball N more times until another person is eliminated, and will 
	repeat this process until there is only one person left who wins the game. This program uses both a list and a vector to 
	solve this problem, and it tracks time for both implementations allowing for a comparison of efficiency between the two 
	implementations.



*/
int main(void)
{
	runList();
	runVector();
	return 0;
}
