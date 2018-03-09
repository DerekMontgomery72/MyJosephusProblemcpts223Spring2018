#include"TestVectorMyJosephus.h"

void runVector()
{
	int N = 0, M = 0, choice = 0;
	cout << "What M value would you like to use for the vector: ";
	cin >> M;
	cout << "What N value would you like to use for the vector: ";
	cin >> N;
	VectorMyJosephus mainVector(M, N);
	while (choice != 1) {
		cout << "The size of the vector is " << mainVector.currentSize() << endl;

		clock_t j = clock();
		clock_t startVector;
		do {
			startVector = clock();
		} while (startVector == j);
		mainVector.runGame();
		clock_t endVector = clock();

		cout << "CPU elapsed time in seconds for vector: " << (double(endVector - startVector) / CLOCKS_PER_SEC) << endl;



		mainVector.clear();
		do {
			cout << "Would you like to play again with the list:  0 for yes 1 for No " << endl;
			cin >> choice;
		} while (choice < 0 || choice > 1);
		if (choice == 0) {
			cout << "What new M value would you like to use: ";
			cin >> M;
			cout << "What new N value would you like to use: ";
			cin >> N;
			mainVector.init(N, M);
		}
	}
}
