#include <iostream>

enum Shape
{
	Circle, Star, Square, Diamond, Cross, Plus
};

enum Colour
{
	R, B, G, Y, P, O  
};

struct tile
{
	Shape shape;
	Colour colour;
	int pos;
	tile* next;
};

class xList
{
private:
	tile *head, *tail;

public:
	xList()
	{
		head = NULL;
		tail = NULL;
	}

	void createTile(Colour colour, Shape shape)
	{
		tile* temp = new tile;
		temp->colour = colour;
		temp->shape = shape;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void display()
	{
		const char* colourVals[] = { "R", "B", "G", "Y", "P", "O"};

		tile* temp = new tile;
		temp = head;
		while (temp != NULL)
		{
			std::cout << temp->shape << colourVals[temp->colour] << "\t";
			temp = temp->next;
		}
	}

	void insert_start(int value)
	{
		tile* temp = new tile;
		temp->next = head;
		head = temp;
	}

	void insert_position(int pos, Colour colour, Shape shape)
	{
		tile* pre = new tile;
		tile* cur = new tile;
		tile* temp = new tile;
		cur = head;
		for (int i = 1; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->colour = colour;
		temp->shape = shape;
		pre->next = temp;
		temp->next = cur;
	}

	void delete_position(int pos)
	{
		tile* current = new tile;
		tile* previous = new tile;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}

	void TEST(int pos)
	{
		tile* current = new tile;
		tile* previous = new tile;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
};



int main()
{
	xList xlist1;
	xList xlist2;
	xlist1.createTile(R, Circle);
	xlist1.createTile(B, Star);
	xlist1.createTile(G, Diamond);
	xlist1.createTile(Y, Square);
	xlist1.createTile(O, Cross);
	xlist1.createTile(P, Plus);
	xlist1.insert_position(2 ,R, Star);
	xlist1.display();
	std::cout << "\n";
	xlist2.createTile(R, Circle);
	xlist2.createTile(B, Star);
	xlist2.createTile(G, Diamond);
	xlist2.createTile(Y, Square);
	xlist2.createTile(O, Cross);
	xlist2.createTile(P, Plus);
	xlist2.insert_position(2, R, Star);
	xlist2.display();

}
