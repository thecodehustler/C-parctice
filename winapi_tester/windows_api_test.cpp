#define UNICODE
#include <windows.h>
#include <wingdi.h>
#include <stdio.h>
#include <malloc.h>

#include "d2d_operate.h"

LPCWSTR wClassName = TEXT("myClass");

BOOL SetProcessDPIAware() {
  BOOL (__stdcall* pFn)(void);
  BOOL ret = 0;
  HINSTANCE hInstance=LoadLibrary(TEXT("user32.dll"));
  if (hInstance) {
    pFn=(BOOL (__stdcall*)(void))GetProcAddress(hInstance,"SetProcessDPIAware");
    if (pFn) {
      ret = pFn();
    }
  }
  FreeLibrary(hInstance);
  return ret;
}

LRESULT CALLBACK eventHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
    case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
    break;
    case WM_PAINT: {
      D2DResources* resource = (D2DResources*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
      render(resource);
    }
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
}

void init(HINSTANCE hInstance) {
  SetProcessDPIAware();
  WNDCLASS wndCls = {};
  wndCls.lpszClassName = wClassName;
  wndCls.lpfnWndProc = eventHandler;
  wndCls.hInstance = hInstance;
  wndCls.cbWndExtra = sizeof(D2DResources);
  ATOM atom = RegisterClass(&wndCls);

  if (atom == 0) {
    printf("ERROR: Failed to create window class, error code: %d.\n", GetLastError());
  }
}

void runMsgLoop() {
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {
  init(hInstance);
  
  D2DResources resources = {};
  initD2DIndependentResources(&resources);
  int w, h;
  calculateWH(&resources, 640, 480, &w, &h);

  HWND hWnd = CreateWindowEx(0, wClassName, TEXT("Windows 窗口程序"), WS_OVERLAPPEDWINDOW^(WS_MAXIMIZEBOX | WS_THICKFRAME), CW_USEDEFAULT,CW_USEDEFAULT,w,h,
  NULL, NULL, hInstance, NULL);
  if (hWnd == NULL) {
    printf("ERROR: Failed to create window. Last Error: %d.\n", GetLastError());
  }
  ShowWindow(hWnd, SW_SHOW);

  initD2DResources(&resources, hWnd);
  SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)&resources);
  runMsgLoop();

  return 0;
}

