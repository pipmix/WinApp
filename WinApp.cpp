#include "WinApp.h"

HWND WinApp::_hWnd = nullptr;

WinApp::WinApp(UINT width, UINT height, std::wstring name): w(width), h(height), n(name) {


}

int WinApp::Run(HINSTANCE hInstance, int nCmdShow)
{
	// Parse the command line parameters
	int argc;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	
	LocalFree(argv);

	// Initialize the window class.
	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.hInstance = hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = L"DXSampleClass";
	RegisterClassEx(&windowClass);

	RECT windowRect = { 0, 0, static_cast<LONG>(w), static_cast<LONG>(h) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// Create the window and store a handle to it.
	_hWnd = CreateWindow(
		windowClass.lpszClassName,
		nullptr,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,		// We have no parent window.
		nullptr,		// We aren't using menus.
		hInstance,
		nullptr);

	// Initialize the sample. OnInit is defined in each child-implementation of DXSample.


	ShowWindow(_hWnd, nCmdShow);


	MSG msg = {};
	while (msg.message != WM_QUIT){
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<char>(msg.wParam);
}


LRESULT CALLBACK WinApp::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch (message){
		case WM_CREATE:{
			return 0;
		}


		case WM_PAINT:{
			//if (pSample)
			//{
			//	pSample->OnUpdate();
			//	pSample->OnRender();
			//}
			//return 0;
		}


		case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
		}

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}