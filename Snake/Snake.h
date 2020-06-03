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
public:
	int SnakeSize;
	Node *head, * tail;
	Snake();
	void CreateSnake(int MapSize_);
	void DelSnake();
	void Growing();
	void Crawl(int direction_);
	void Cut(Node* tmp);
};