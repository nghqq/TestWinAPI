#include <Windows.h>
#include"resource.h"
#include"resource1.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT cmdShow) 
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDHELP), NULL, DLGPROC(DlgProc), 0);
	return 0;
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg)
	{	
	case WM_INITDIALOG: 
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON_STUDENT));
		SendMessage(hwnd, WM_SETICON, 0, LPARAM(hIcon));
	}
		break;
	case WM_COMMAND:
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}