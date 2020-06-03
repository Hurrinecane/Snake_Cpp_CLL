#pragma once

enum Directions { UP, RIGHT, DOWN, LEFT };

struct Node
{
	int direction;
		int x, y;	

	Node* next;
	Node* prev;
};

ref class Snake
{
private:
	int SnakeSize;

public:
	Node *head, * tail;
	Snake();
	void CreateSnake(int MapSize_);
	void Growing();
	void Crawl(int direction_);
	void Cut(Node* tmp);
};