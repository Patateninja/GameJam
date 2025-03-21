#include "Graph.hpp"

//Tile Function
Node::Node(int X, int Y, int wgt = 0)
{
	this->weight = wgt;
	this->x = X;
	this->y = Y;
	this->previous = nullptr;
	this->distanceToStart = 0;
	this->distanceToTarget = 0;
	this->totalDistance = 0;
}

Node::~Node()
{

}

int Node::getX()
{
	return this->x;
}
int Node::getY()
{
	return this->y;
}
int Node::getWeight()
{
	return this->weight;
}
Node* Node::getPrevious()
{
	return this->previous;
}
float Node::getDTT()
{
	return this->distanceToTarget;
}
float Node::getDTS()
{
	return this->distanceToStart;
}
float Node::getTD()
{
	return this->totalDistance;
}
std::vector<Node*> Node::getNeighborList()
{
	return this->neighbors;
}
Node* Node::getSpecificNeighbor(int index)
{
	return this->neighbors[index];
}

void Node::setWeight(int wei)
{
	this->weight = wei;
}
void Node::setPrevious(Node* node)
{
	this->previous = node;
}
void Node::setDTT(float dtt)
{
	this->distanceToTarget = dtt;
}
void Node::setTD()
{
	this->totalDistance = this->distanceToStart + this->distanceToTarget;
}
void Node::setDTS(float dts)
{
	this->distanceToStart = dts;
}
void Node::resetNeighbor()
{
	this->neighbors.clear();
}
void Node::addNeighbor(Node* newneihgbor)
{
	this->neighbors.push_back(newneihgbor);
}

//Graph Function
Graph::Graph(int x, int y, bool corner)
{
	this->x = x - 1;
	this->y = y - 1;
	for (int i = 0; i <= this->x; i++)
	{
		for (int j = 0; j <= this->y; j++)
		{
			this->nodes.push_back(new Node(i, j));
		}
	}
	this->diag = corner;
	this->recalculateGraph();
}
Graph::~Graph()
{
	for (Node* i : this->nodes)
	{
		i->~Node();
	}
}

std::vector<Node*> Graph::getList()
{
	return this->nodes;
}
Node* Graph::getNode(int x, int y)
{
	for (Node* i : this->nodes)
	{
		if (i->getX() == x && i->getY() == y)
		{
			return i;
		}
	}
}
bool Graph::getDiag()
{
	return this->diag;
}

void Graph::toogleDiag()
{
	this->diag = !this->diag;
}
void Graph::recalculateGraph()
{
	for (Node* curentNode : this->nodes)
	{
		curentNode->resetNeighbor();
		if (this->diag)
		{
			if (curentNode->getX() != 0 && curentNode->getY() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() - 1, curentNode->getY() - 1));
			}
			if (curentNode->getX() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() - 1, curentNode->getY()));
			}
			if (curentNode->getX() != 0 && curentNode->getY() != this->y)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() - 1, curentNode->getY() + 1));
			}

			if (curentNode->getX() != this->x && curentNode->getY() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() + 1, curentNode->getY() - 1));
			}
			if (curentNode->getX() != this->x)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() + 1, curentNode->getY()));
			}
			if (curentNode->getX() != this->x && curentNode->getY() != this->y)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() + 1, curentNode->getY() + 1));
			}

			if (curentNode->getY() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX(), curentNode->getY() - 1));
			}
			if (curentNode->getY() != this->y)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX(), curentNode->getY() + 1));
			}
		}
		else
		{
			if (curentNode->getX() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() - 1, curentNode->getY()));
			}
			if (curentNode->getX() != this->x)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX() + 1, curentNode->getY()));
			}
			if (curentNode->getY() != 0)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX(), curentNode->getY() - 1));
			}
			if (curentNode->getY() != this->y)
			{
				curentNode->addNeighbor(this->getNode(curentNode->getX(), curentNode->getY() + 1));
			}
		}
	}
}
Node* Graph::getRandomNeighbor(Node* node)
{
	srand(time(NULL));
	int random = rand() % node->getNeighborList().size();
	return node->getSpecificNeighbor(random);
}

void Graph::addObstacle(int x, int y)
{
	this->getNode(x, y)->setWeight(10000);
}