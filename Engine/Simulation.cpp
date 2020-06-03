#include "MainWindow.h"
#include "Simulation.h"

Simulation::Simulation(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
    Network(300, 300, 500)
{
}

void Simulation::UpdateModel()
{
}

void Simulation::ComposeFrame()
{
    gfx.BeginFrame();
    gfx.DrawRect(360, 350, 400, 750, Colors::Yellow);
    gfx.DrawRect(700, 350, 740, 750, Colors::Yellow);
    //gfx.DrawLine(500, 500, 50, 50, Colors::Cyan);
    float xPad = 400.0f;
    float yPad = 400.0f;
    for (int i = 0; i < Network.nWires; i++)
    {
        Vec2D p0 = { Network.Network[i].start.x + xPad, Network.Network[i].start.y + yPad };
        Vec2D p1 = { Network.Network[i].stop.x + xPad, Network.Network[i].stop.y + yPad };

        gfx.DrawLine(p0, p1, Colors::Red);
    }
    gfx.EndFrame();
}

// Support Functions
// -----------------
