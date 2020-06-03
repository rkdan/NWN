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
};