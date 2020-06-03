#include "WireNetwork.h"
#include <random>
#include <cmath>

WireNetwork::Wire::Wire(Vec2D start, Vec2D stop, Vec2D mid)
	:
	start(start),
	stop(stop),
	mid(mid)
{
}

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

void WireNetwork::MakeAdjMat()
{
	for (int i = 0; i < nWires; i++)
	{
		Wire current = Network[i];
		// Check to see if this wire intercepts with any other wires.
		for (int j = i; j < nWires; j++)
		{
			Wire check = Network[j];
			bool intersect = doIntersect(current.start, current.stop, check.start, check.stop);
			if (intersect)
			{
				AdjMat[j * nWires + i] = 1;
				AdjMat[i * nWires + j] = 1;
			}
		}
	}
}

bool WireNetwork::onSegment(Vec2D p, Vec2D q, Vec2D r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

int WireNetwork::orientation(Vec2D p, Vec2D q, Vec2D r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear 

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool WireNetwork::doIntersect(Vec2D p0, Vec2D q0, Vec2D p1, Vec2D q1)
{
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p0, q0, p1);
	int o2 = orientation(p0, q0, q1);
	int o3 = orientation(p1, q1, p0);
	int o4 = orientation(p1, q1, q0);

	// General case 
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p0, p1, q0)) return true;

	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p0, q1, q0)) return true;

	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p1, p0, q1)) return true;

	// p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p1, q0, q1)) return true;

	return false; // Doesn't fall in any of the above cases 
}
