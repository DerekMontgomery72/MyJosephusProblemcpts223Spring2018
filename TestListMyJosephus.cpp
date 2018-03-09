#include"TestListMyJosephus.h"

void runList()
{

	int M = 0, N = 0, choice = 0;
	cout << "What M value would you like to use for the list : ";
	cin >> M;
	cout << "What N value would you like to use for the list: ";
	cin >> N;
	
	ListMyJosephus mainList(M, N);
		while(choice != 1){
			cout << "The size of the list is " << mainList.currentSize() << endl;

			clock_t k = clock();
			clock_t startlist;
			do {
				startlist = clock();
			} while (startlist == k);
			mainList.runGame();
			clock_t endList = clock();
			clock_t j = clock();
			clock_t startVector;

			cout << "CPU elaped time in seconds for list: " << (double(endList - startlist) / CLOCKS_PER_SEC) << endl;
			mainList.clear();
			do {
				cout << "Would you like to play again with the list:  0 for yes 1 for No " << endl;
				cin >> choice;
			} while (choice < 0 || choice > 1);
			if (choice == 0) {
				cout << "What new M value would you like to use: ";
				cin >> M;
				cout << "What new N value would you like to use: ";
				cin >> N;
				mainList.init(N, M);
			}
		}


}
