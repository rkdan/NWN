#pragma once
#include <vector>
#include "Vec2D.h"
using namespace std;

class WireNetwork
{
	class Wire
	{
	public:
		Wire(Vec2D start, Vec2D stop, Vec2D mid);
		Wire() = default;
		Vec2D start;
		Vec2D stop;
		Vec2D mid;
	private:

	};
public:
	WireNetwork(int width, int height, int nWires);
	int width;
	int height;
	int nWires;
	vector<Wire> Network = vector<Wire>(nWires);
	vector<int> AdjMat = vector<int>(nWires * nWires);
	void MakeAdjMat();
private:
	bool onSegment(Vec2D p, Vec2D q, Vec2D r);
	int orientation(Vec2D p, Vec2D q, Vec2D r);
	bool doIntersect(Vec2D p0, Vec2D q0, Vec2D p1, Vec2D q1);
};