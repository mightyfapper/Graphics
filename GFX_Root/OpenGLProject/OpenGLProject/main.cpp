#include "Engine.h"

int main()
{
	Engine engine;

	if (!engine.Init(800, 600))
	{
		cout << "Engine Init error" << endl;
		return false;
	}

	engine.Start();

	return 0;
}