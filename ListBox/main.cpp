#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include "resource.h"

CONST CHAR* g_sz_VALUES[] = { "This","is","my","first","List","Box" };


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //процедура окна
BOOL CALLBACK DlgProcAddItem(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


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
		SendMessage(hList, LB_SETCURSEL, 0, 0); // Сразу же выбирает нулевой элемент  ComboBox

		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_ADD:
			DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_OTHER_DIALOG), hwnd, (DLGPROC)DlgProcAddItem, 0); break;
		case IDC_DELETE:
		{
			CHAR sz_buffer[FILENAME_MAX]{};
			CHAR sz_message[FILENAME_MAX]{};
			HWND hCombo = GetDlgItem(hwnd, IDC_LIST);
			int i = SendMessage(hCombo, LB_GETCURSEL, 0, 0);
			SendMessage(hCombo, LB_GETTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_message, "Вы действительно хотите удалить элемент №%i со значением \"%s\"?", i, sz_buffer);
			switch (MessageBox(hwnd, sz_message, "Вопрос", MB_YESNO | MB_ICONQUESTION))
			{
			case IDYES:SendMessage(hCombo, LB_DELETESTRING, i, 0);
			case IDNO:break;
			}

		}

		case IDOK:
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_LIST);
			CHAR sz_buffer[MAX_PATH]{};
			CHAR sz_message[MAX_PATH]{};
			int i = SendMessage(hCombo, LB_GETCURSEL, 0, 0); // Получаем  номер выбранного элемента ComboBox
			SendMessage(hCombo, LB_GETTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_message, "Вы выбрали пункт %i со значением \"%s\".", i, sz_buffer);
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);

		}
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
		SetFocus(GetDlgItem(hwnd, IDC_EDIT_NEW_ITEM));
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CHAR sz_buffer[FILENAME_MAX] = {};
			HWND hEditAddItem = GetDlgItem(hwnd, IDC_EDIT_NEW_ITEM);
			SendMessage(hEditAddItem, WM_GETTEXT, FILENAME_MAX, (LPARAM)sz_buffer);
			HWND hParent = GetParent(hwnd);
			HWND hCombo = GetDlgItem(hParent, IDC_LIST);
			//SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)sz_buffer);
			if (SendMessage(hCombo, LB_FINDSTRINGEXACT, -1, (LPARAM)sz_buffer) == LB_ERR)
				SendMessage(hCombo, LB_ADDSTRING, 0, (LPARAM)sz_buffer);
		}
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}




