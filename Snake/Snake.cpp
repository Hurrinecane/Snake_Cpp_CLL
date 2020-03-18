#include "pch.h"
#include "Snake.h"

Snake::Snake(int MapSize_, int BlockSize_)
{
	MapSize = MapSize_;
	BlockSize = BlockSize_;

	head = new Node;
	head->prev = tail = new Node;
	head->next = nullptr;
	head->block.height = head->block.width = BlockSize;
	head->block.x = head->block.y = 0;
	head->direction = UP;
}

void Snake::Growing()
{
	Node* tmp = new Node;
	tmp->next = tail;
	tmp->prev = nullptr;

	tmp->block.x = tail->block.x;
	tmp->block.y = tail->block.y;
	tmp->direction = tail->direction;

	tail->prev = tmp;
	tail = tmp;
	SnakeSize++;
}

void Snake::Crawl(int direction_)
{
	Node* tmp = tail;
	tail = tail->next;
	tail->prev = nullptr;
	tmp->prev = head;
	tmp->next = nullptr;
	head->next = tmp;
	head = tmp;

	switch (direction_)
	{
	case UP:
		head->block.y -= 1;
		head->prev->direction = head->direction = UP;
		break;
	case RIGHT:
		head->block.x += 1;
		head->prev->direction = head->direction = RIGHT;
		break;
	case DOWN:
		head->block.y += 1;
		head->prev->direction = head->direction = DOWN;
		break;
	case LEFT:
		head->block.x -= 1;
		head->prev->direction = head->direction = LEFT;
		break;
	}
}
void Snake::Cut(Node* tmp, int SnakeSize, Node* tail, Node* head)
{
	for (tail; tail != tmp; tail = tail->prev)
	{
		delete(tail->next);
		tail->next = nullptr;
		SnakeSize--;
	}
}
	void Colision()
	{

	}