#define NOMINMAX
#include "Queue.h"

void Menue() {
	std::cout << "1-) Insert To Queue" << std::endl;
	std::cout << "2-) Delete From Queue" << std::endl;
	std::cout << "3-) Peek Front Of Queue" << std::endl;
	std::cout << "4-) Check Size Of Queue" << std::endl;
	std::cout << "5-) Display Queue" << std::endl;
	std::cout << "6-) Save" << std::endl;
	std::cout << "7-) Load" << std::endl;
	std::cout << "8-) Exit Program" << std::endl;
	std::cout << "\nEnter Choice: ";
}

void main() {
	int choice;
	char  insertNode;
	std::string message = "Size Of Queue Is: ";
	std::string messageTwo = "Deleting Node: ";
	std::string messageThree = "Node In Front Of Queue: ";
	Queue Q(8);
	MyRectangle R;
	R.showConsoleCursor(false);
	do {
		Menue();
		while (!(std::cin >> choice)) {
			Q.setColor(4);
			std::cout << "\nChoice Must Be A Number: \n";
			Q.setColor(15);
			std::cout << "\nEnter Choice Again: ";
			std::cin.clear();
			std::cin.ignore(10000000000000, '\n');
		}
		if (choice == 1) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
				std::cout << "\nInsert Node To Create List: ";
				std::cin >> insertNode;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				Q.Enqueue(insertNode);
				std::cout << "\n";
				Q.DisplayList();
			}
			else if (Q.IsFull()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Full ====\n";
				std::cout << "\n==== Please Delete Node ====\n";
				Q.setColor(15);
				std::cout << "\n";
			}
			else {
				system("cls");
				Q.DisplayList();
				std::cout << "\nInsert Node: ";
				std::cin >> insertNode;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				Q.Enqueue(insertNode);
				std::cout << "\n";
				Q.DisplayList();
			}
		}
		else if (choice == 2) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
			}
			else {
				system("cls");
				Q.DisplayList();
				R.DrawSkelaton(50, 0, 4 + messageTwo.length(), 2, messageTwo, 11, 5);
				std::cout << Q.Peek() << std::endl;
				Q.Dequeue();
				std::cout << "\n\n\n\n\n\n\n\n\n";
				Q.setColor(2);
				std::cout << "|UPDATING LIST|";
				for (int i = 0; i <= 10; i++) {
					Sleep(800);
					std::cout << ".";
				}
				Q.setColor(15);
				Q.DisplayList();
			}
		}
		else if (choice == 3) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
			}
			else {
				system("cls");
				Q.DisplayList();
				R.DrawSkelaton(50, 0, 3 + messageThree.length(), 2, messageThree, 11, 5);
				std::cout << Q.Peek() << std::endl;
				std::cout << "\n\n\n\n\n\n\n\n\n";
				Q.setColor(15);
			}
		}
		else if (choice == 4) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
			}
			else {
				system("cls");
				Q.DisplayList();
				R.DrawSkelaton(50, 0, 3 + message.length(), 2, message, 11, 5);
				std::cout << Q.Size() << std::endl;
				std::cout << "\n\n\n\n\n\n\n\n\n";
				Q.setColor(15);
			}
		}
		else if (choice == 5) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
			}
			else {
				system("cls");
				std::cout << "\n";
				Q.DisplayList();
			}
		}
		else if (choice == 6) {
			if (Q.IsEmpty()) {
				system("cls");
				Q.setColor(4);
				std::cout << "==== The List Is Empty ====\n\n";
				Q.setColor(15);
			}
			else {
				Q.Save("c:\\temp\\input.txt");
				system("cls");
				std::cout << "\n";
				Q.DisplayList();
			}
		}
		else if (choice == 7) {
			system("cls");
			Q.Load("c:\\temp\\input.txt");
			system("cls");
			std::cout << "\n";
			Q.DisplayList();
		}
		else if (choice == 8) {
			system("cls");
			Q.DisplayList();
			Q.gotoxy(50, 14);
			Q.setColor(240);
			std::cout << "==== GOOD BYE ====";
			break;
		}
	} while (choice != 8);
	while (1);
}