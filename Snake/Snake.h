#pragma once

class Snake
{
private:
	int MapSize, BlockSize;

	int SnakeSize;

	struct Node
	{
		int direction;
		struct
		{
			int x, y, width, height;
		} block;

		Node* next;
		Node* prev;
	} *head, * tail;
public:
	enum Directions { UP, RIGHT, DOWN, LEFT };
	Snake(int MapSize_, int BlockSize_);
	void Growing();
	void Crawl(int direction_);
	void Cut(Node* tmp, int SnakeSize, Node* tail, Node* head);
};