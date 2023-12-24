#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include"resource.h"
#include <stdio.h>

CONST CHAR* g_sz_VALUES[] = { "This","is","my","first","Combo","Box" };

// Ctrl+T тестовый режим  в resource.rc

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProcAddItem(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow) 
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDHELP), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON_PARCEL));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);


		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
		for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
		}
		SendMessage(hCombo, CB_SETCURSEL, 0, 0); // Сразу же выбирает нулевой элемент  ComboBox

		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			CHAR sz_buffer[MAX_PATH]{};
			CHAR sz_message[MAX_PATH]{};
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0); // Получаем  номер выбранного элемента ComboBox
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_message, "Вы выбрали пункт %i со значением \"%s\".", i, sz_buffer);
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);

		}
		break;

		case IDC_ADD:
			DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_OTHER_DIALOG), hwnd, (DLGPROC)DlgProcAddItem, 0);
				break;
		case IDCANCEL:EndDialog(hwnd, 0);
			break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}
	BOOL CALLBACK DlgProcAddItem(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
	{
		switch (uMsg) 
		{
		case WM_INITDIALOG:
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam)) 
			{
			case IDOK:
			case IDCANCEL:EndDialog(hwnd, 0);
			}
			break;
		case WM_CLOSE:EndDialog(hwnd, 0);
		}
		return FALSE;
	}

