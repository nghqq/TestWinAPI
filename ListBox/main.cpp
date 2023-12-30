#include<Windows.h>
#include<stdio.h>
#include "resource.h"

CONST CHAR* g_sz_VALUES[] = { "This","is","my","first","List","Box" };


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //процедура окна


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow) 
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}



BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);

	HWND hList = GetDlgItem(hwnd, IDC_LIST);
	for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
	{
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
	}
	SendMessage(hList, LB_SETCURSEL, 0, 0);
	break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam)) 
		{
		case IDOK: MessageBox(hwnd, "Была нажата кнопка OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:EndDialog(hwnd, 0);
		
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}




