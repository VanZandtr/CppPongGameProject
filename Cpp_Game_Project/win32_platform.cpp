#include <Windows.h>

bool running = true;

//Message handler
LRESULT CALLBACK win_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT res = 0;
	switch (uMsg)
	{
		case WM_CLOSE:
		//if "x" (close) is hit, close the window
		case WM_DESTROY: {
			running = false;
		} break;
		default: {
			res = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	return res;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	//Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = TEXT("Game Window Class");
	window_class.lpfnWndProc = win_callback;

	//Register Class
	RegisterClass(&window_class);

	//Create Window
	HWND window = CreateWindow(window_class.lpszClassName, TEXT("Cpp Game Project"), WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running)
	{
		//Input
		MSG msg;
		//will only read each message once
		while (PeekMessage(&msg, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		//Simulate

		//Render

	}
}