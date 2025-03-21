#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include "SFML/Graphics.hpp"

class Node
{
private:
	int x;
	int y;
	int weight;
	Node* previous;
	float distanceToTarget;
	float distanceToStart;
	float totalDistance;
	std::vector<Node*> neighbors;
public:
	Node(int, int, int);
	~Node();

	int getX();
	int getY();
	int getWeight();
	Node* getPrevious();
	float getDTT();
	float getDTS();
	float getTD();
	std::vector<Node*> getNeighborList();
	Node* getSpecificNeighbor(int);

	void setWeight(int);
	void setPrevious(Node*);
	void setDTT(float);
	void setDTS(float);
	void setTD();
	void resetNeighbor();
	void addNeighbor(Node*);
};


class Graph
{
private:
	std::vector<Node*> nodes;
	int x;
	int y;
	bool diag;
public:
	Graph(int, int, bool);
	~Graph();

	std::vector<Node*> getList();
	Node* getNode(int, int);
	bool getDiag();

	void toogleDiag();
	void recalculateGraph();
	Node* getRandomNeighbor(Node*);

	void addObstacle(int, int);
};