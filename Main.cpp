#include "WinApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){

	WinApp app(720, 480, L"Title");
	return app.Run(hInstance, nCmdShow);
}