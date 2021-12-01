#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <Windows.h>

/*Window Procedure*/
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
/*Win API driver*/
int WINAPI WinMain(HINSTANCE HInstance, HINSTANCE HPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    /*Declare window handler, message, window class*/

    MSG msg;
    WNDCLASSEX winclass;
    HWND hwnd;

    /*Declare window properties*/

    winclass.lpszClassName = "window_class";
    winclass.lpszMenuName = NULL;
    winclass.lpfnWndProc = WindowProcedure;
    winclass.cbClsExtra = 0;
    winclass.cbSize = sizeof(WNDCLASSEX);
    winclass.cbWndExtra = 0;
    winclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    winclass.hInstance = HInstance;
    winclass.style = CS_DBLCLKS;

    /*Declare icon and cursor*/

    winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    /*Register window class*/
    if (!RegisterClassEx(&winclass))
    {
        return 0;
    }
    /*Create window to Window handler*/
    hwnd = CreateWindowEx(
        0,
        "window_class",
        "My Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1280,
        720,
        HWND_DESKTOP,
        NULL,
        HInstance,
        NULL);

    ShowWindow(hwnd, nCmdShow);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return 0;
}