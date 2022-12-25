#pragma once
#include "Coordinates.h"
#include "MyRectangle.h"
#include "Windows.h"
#include <iostream>
#include <fstream>

class Queue :public Coordinates {

public:
	char* myQueueArray;
	char tail, head, capacity;

	Queue(int capacity) : capacity(capacity) {
		myQueueArray = new char[capacity];
		head = 0;
		tail = -1;
	}
	int Max();
	void Enqueue(char value);
	void DisplayList();
	void Save(const std::string& filename);
	void Load(const std::string& filename);
	char Dequeue();
	char Peek();
	int Size();
	bool IsFull();
	bool IsEmpty();
};
