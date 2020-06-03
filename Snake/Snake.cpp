#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	this->head = this->tail = nullptr;
}

void Snake::CreateSnake(int MapSize_)
{
	head = new Node;
	head->prev = tail = new Node;
	head->next = tail->prev = nullptr;
	tail->next = head;

	head->x = head->y = tail->x = tail->y = MapSize_ / 2;
	head->direction = tail->direction = RIGHT;
	SnakeSize = 2;
}

void Snake::DelSnake()
{
	Cut(head);
	delete head;
	SnakeSize--;
}

void Snake::Growing()
{
	Node* tmp = new Node;
	tmp->next = tail;
	tmp->prev = nullptr;

	tmp->x = tail->x;
	tmp->y = tail->y;
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
		head->x = head->prev->x;
		head->y = head->prev->y - 1;
		head->prev->direction = head->direction = UP;
		break;
	case RIGHT:
		head->x = head->prev->x + 1;
		head->y = head->prev->y;
		head->prev->direction = head->direction = RIGHT;
		break;
	case DOWN:
		head->x = head->prev->x;
		head->y = head->prev->y + 1;
		head->prev->direction = head->direction = DOWN;
		break;
	case LEFT:
		head->x = head->prev->x - 1;
		head->y = head->prev->y;
		head->prev->direction = head->direction = LEFT;
		break;
	}
}

void Snake::Cut(Node* tmp)
{
	for (tail; tail != tmp;)
	{
		tail = tail->next;
		delete(tail->prev);
		tail->prev = nullptr;
		SnakeSize--;
	}

}
void Colision()
{

}