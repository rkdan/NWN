#include "MainWindow.h"
#include "Simulation.h"
#include "ChiliException.h"


int WINAPI wWinMain( HINSTANCE hInst,HINSTANCE,LPWSTR pArgs,INT )
{
	bool show = true;
	MainWindow wnd( hInst,pArgs );
	Simulation theSim( wnd );
	theSim.UpdateModel();
	if (show)
	{
		while (wnd.ProcessMessage())
		{
			theSim.ComposeFrame();
		}
	}
	return 0;
}