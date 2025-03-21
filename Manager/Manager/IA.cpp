#include "IA.hpp"

IA::IA(char selectedMode, Node* start, Node* target)
{
	this->mode = selectedMode;
	this->target = target;
	this->start = start;
}
IA::~IA()
{

}

char IA::getMode()
{
	return this->mode;
}
std::vector<Node*> IA::getPath()
{
	return this->path;
}
std::vector<Node*> IA::getCurrent()
{
	return this->current;
}
Node* IA::getStart()
{
	return this->start;
}
Node* IA::getTarget()
{
	return this->target;
}


void IA::switchMode()
{
	if (this->mode == 'e')
	{
		this->mode = 'm';
	}
	else
	{
		this->mode = 'e';
	}
}
void IA::setTarget(Node* node)
{
	this->target = node;
}
void IA::setStart(Node* node)
{
	this->start = node;
}

float IA::Manhattan(int x1, int y1, int x2, int y2)
{
	return (abs(x1 - x2) + abs(y1 - y2));
}
float IA::Euclidian(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
float IA::Distance(Node* tile1, Node* tile2)
{
	if (this->mode == 'e')
	{
		return this->Euclidian(tile1->getX(), tile1->getY(), tile2->getX(), tile2->getY());
	}
	else if (this->mode == 'm')
	{
		return this->Manhattan(tile1->getX(), tile1->getY(), tile2->getX(), tile2->getY());
	}
}
void IA::BuildPath(Graph* graph)
{
	Node* node = target;
	do
	{
		this->path.push_back(node);
		node = node->getPrevious();
	} while (node != nullptr);
}
void IA::Astar(Graph* graph)
{
	if (this->current.empty())
	{
		start->setDTT(this->Distance(this->target, this->start));
		start->setDTS(this->Distance(this->start, this->start));
		start->setTD();
		this->current.push_back(start);
		return;
	}

	Node* bestNeighbor = new Node(1, 1, 10000);
	for (Node* currentNode : this->current)
	{
		if (currentNode == target)
		{
			this->BuildPath(graph);
			return;
		}
		for (Node* neighbor : currentNode->getNeighborList())
		{
			neighbor->setDTT(this->Distance(target, neighbor));
			neighbor->setDTS(this->Distance(start, neighbor));
			neighbor->setTD();

			bool notallreadychecked = true;
			for (Node* check : this->current)
			{
				if (neighbor == check)
				{
					notallreadychecked = false;
				}
			}
			if (notallreadychecked)
			{
				if (neighbor->getTD() + neighbor->getWeight() == bestNeighbor->getTD() + bestNeighbor->getWeight())
				{
					if (neighbor->getDTT() < bestNeighbor->getDTT())
					{
						bestNeighbor = neighbor;
						bestNeighbor->setPrevious(currentNode);
					}
				}
				if (neighbor->getTD() + neighbor->getWeight() < bestNeighbor->getTD() + bestNeighbor->getWeight())
				{
					bestNeighbor = neighbor;
					bestNeighbor->setPrevious(currentNode);
				}
			}
		}
	}

	this->current.push_back(bestNeighbor);
	return;
}