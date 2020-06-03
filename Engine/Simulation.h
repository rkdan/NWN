#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "WireNetwork.h"

class Simulation
{
public:
	Simulation( class MainWindow& wnd );
	Simulation( const Simulation& ) = delete;
	Simulation& operator=( const Simulation& ) = delete;
    void ComposeFrame();
    void UpdateModel();
private:

private:
	MainWindow& wnd;
	Graphics gfx;
    WireNetwork Network;
};