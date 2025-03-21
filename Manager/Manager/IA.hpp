#pragma once
#include <cmath>
#include "Graph.hpp"

class IA
{
private:
	std::vector<Node*> path;
	std::vector<Node*> current;
	char mode;
	Node* target;
	Node* start;
public:
	IA(char, Node*, Node*);
	~IA();

	char getMode();
	std::vector<Node*> getPath();
	std::vector<Node*> getCurrent();
	Node* getStart();
	Node* getTarget();

	void switchMode();
	void setTarget(Node*);
	void setStart(Node*);

	float Manhattan(int, int, int, int);
	float Euclidian(int, int, int, int);
	float Distance(Node*, Node*);
	void BuildPath(Graph*);
	void Astar(Graph*);
};