#include "Queue.h"

void Queue::Enqueue(char value) {
	if (IsFull()) {
		return;
	}
	else
		myQueueArray[++tail] = value;
}
char Queue::Dequeue() {
	if (IsEmpty()) {
		std::cout << "Queue Is Empty" << std::endl;
		return 0;
	}
	else
		return myQueueArray[head++];
}
char Queue::Peek() {
	if (IsEmpty()) {
		std::cout << "Queue Is Empty" << std::endl;
		return 0;
	}
	return
		myQueueArray[head];
}
int Queue::Size() {
	return
		tail - head + 1;
}
bool Queue::IsFull() {
	return
		tail == capacity - 1;
}
bool Queue::IsEmpty() {
	return
		head > tail;
}
void Queue::DisplayList() {
	if (IsEmpty()) {
		system("cls");
		setColor(4);
		std::cout << "==== All Nodes Have Been Deleted ====\n\n";
		setColor(15);
		return;
	}
	else {
		system("cls");
		MyRectangle R;
		int i = 0;
		std::string message = "Your Queue List Is:";
		R.DrawSkelaton(0, 0, 3 + message.length(), 2, message, 11, 5);
		setColor(7);
		std::cout << "\n\n<-----------------------------------------------------------------------------------------------------------------------";
		setColor(112);
		std::cout << "\n==START==\n";
		for (int i = head; i <= tail; i++) {
			setColor(13);
			std::cout << "+--------+   ";
		}
		setColor(4);
		std::cout << "+----+";
		std::cout << std::endl;

		for (int i = head; i <= tail; i++) {
			setColor(13);
			std::cout << "|   "; setColor(11); std::cout << myQueueArray[i];  setColor(13); std::cout << "    |"; setColor(7); std::cout << "<--";
		}
		setColor(4);
		std::cout << "|NULL|";
		std::cout << std::endl;

		for (int i = head; i <= tail; i++) {
			setColor(13);
			std::cout << "+--------+   ";
		}
		setColor(4);
		std::cout << "+----+";
		std::cout << std::endl;
	}
	setColor(7);
	std::cout << "<-----------------------------------------------------------------------------------------------------------------------\n";
	setColor(15);
	std::cout << std::endl;
}
void Queue::Save(const std::string& filename) {
	std::ofstream file(filename);
	for (int i = head; i <= tail; i++) {
		file << myQueueArray[i];
	}
	file.close();
}
void Queue::Load(const std::string& filename) {
	std::ifstream file(filename);
	if (Size() == 0) {
		char value;
		while (file >> value) {
			Enqueue(value);
		}
	}
	else if (Size() > 0) {
		file.close();
		for (int i = head; i <= tail; i++) {
			myQueueArray[head++];
		}
		char value;
		while (file >> value) {
			Enqueue(value);
		}
	}
}