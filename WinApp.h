#pragma once
#include <windows.h>
#include <string>


class WinApp
{
public:

	WinApp(UINT width, UINT height, std::wstring name);
	int Run(HINSTANCE hInstance, int nCmdShow);
	HWND GetHwnd() { return _hWnd; }

	void Init();
	void Update();
	void Draw();



private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static HWND _hWnd;
	UINT w;
	UINT h;
	std::wstring n;
};
