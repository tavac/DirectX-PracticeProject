#include <Windows.h>
#include <stdlib.h>
#include <string.h>

// Setting up winmain
// https://docs.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-160

static WCHAR szWindowClass[] = L"Main Window";
static WCHAR szTitle[] = L"LF-Graphics";

HINSTANCE hInst;

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	WNDCLASSEXW wcexw;

	wcexw.cbSize = sizeof(WNDCLASSEX);
	wcexw.style = CS_HREDRAW | CS_VREDRAW;
	wcexw.lpfnWndProc = WndProc;
	wcexw.cbClsExtra = 0;
	wcexw.cbWndExtra = 0;
	wcexw.hInstance = hInstance;
	wcexw.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcexw.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcexw.lpszMenuName = NULL;
	wcexw.lpszClassName = szWindowClass;
	wcexw.hIcon = LoadIconW(wcexw.hInstance, IDI_APPLICATION);
	wcexw.hIconSm = LoadIconW(wcexw.hInstance, IDI_APPLICATION);

	if (!RegisterClassExW(&wcexw))
	{
		MessageBoxW(
			NULL,
			L"Call to RegisterClassEXW failed!",
			NULL, NULL);
		return FALSE;
	}

	hInst = hInstance;

	HWND hWnd = CreateWindowExW(
		WS_EX_OVERLAPPEDWINDOW,
		szWindowClass,
		szTitle,
		WS_OVERLAPPED,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1280, 1024,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			L"Call to CreateWindow failed!",
			NULL, NULL);
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessageW(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return (int)msg.wParam;

}

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	PAINTSTRUCT ps;
	HDC hdc;
	WCHAR greeting[] = L"Hello Cruel World";

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOutW(hdc, 5, 5, greeting, wcslen(greeting));

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, message, wParam, lParam);
	}

	return 0;
}