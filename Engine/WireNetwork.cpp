#include "WireNetwork.h"
#include <random>
#include <cmath>

WireNetwork::WireNetwork(int width, int height, int nWires)
	:
	width(width),
	height(height),
	nWires(nWires)
{
	//int Length = 80;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> Length(60, 90);
	std::uniform_real_distribution<float> xPoint(0, width - 1);
	std::uniform_real_distribution<float> yPoint(0, height - 1);
	std::uniform_real_distribution<float> Degree(0, 3.14);
	for (int nSpawned = 0; nSpawned < nWires; ++nSpawned)
	{
		Vec2D spawnMidPos = { xPoint(rng), yPoint(rng) };
		float orientation = Degree(rng);
		float length = Length(rng);
		float xStop = spawnMidPos.x + ((length / 2) * cos(orientation));
		float yStop = spawnMidPos.y + ((length / 2) * sin(orientation));
		float xStart = spawnMidPos.x - ((length / 2) * cos(orientation));
		float yStart = spawnMidPos.y - ((length / 2) * sin(orientation));
		Network[nSpawned] = Wire({xStart, yStart}, {xStop, yStop}, spawnMidPos);
	}
}

WireNetwork::Wire::Wire(Vec2D start, Vec2D stop, Vec2D mid)
	:
	start(start),
	stop(stop),
	mid(mid)
{
}
