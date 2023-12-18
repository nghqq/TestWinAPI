#include<Windows.h>
#include"resource.h"


CONST CHAR g_sz_LOGIN_INVITE[] = "Введите имя пользователя";
CONST CHAR g_sz_PASSWORD_INVITE[] = "Введите пароль";
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //прототип процедуры окна

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	// HWND - это окно  (Handler to Window - обработчик окна).
	// uMsg - это сообщение которое передаётся окну.
	// wParam, lParam - это  параметры сообщения.
	switch (uMsg) 
	{
	case WM_INITDIALOG: //Здесь можно создавать элементы интерфейса.
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		
	}
		break;			// Эта секция отрабатывает при запуске окна один раз.
	case WM_COMMAND:
		// Здесь обрабатываются команды нажатия кнопок, сочетания клавиш и тд.
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CHAR sz_buffer[MAX_PATH] = {};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, MAX_PATH, (LPARAM)sz_buffer);

			//EN_ - Edit Notification
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_LOGIN_INVITE) == 0)
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			if (HIWORD(wParam) == EN_KILLFOCUS && strlen(sz_buffer) == 0)
				SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_LOGIN_INVITE);
		}
		break;

		case IDC_EDIT_PASSWORD:
		{
			CHAR sz_buffer[MAX_PATH] = {};
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			SendMessage(hEditPassword, WM_GETTEXT, MAX_PATH, (LPARAM)sz_buffer);

		
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_PASSWORD_INVITE) == 0)
				SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)"");
			if (HIWORD(wParam) == EN_KILLFOCUS && strlen(sz_buffer) == 0)
				SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)g_sz_PASSWORD_INVITE);
		}
		break;

		case IDC_BUTTON_COPY:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer); //WM_GETTEXT берет текст
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer); // WM_GETTEXT вставляет текст
			//SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer); // Копирует 
		}
		break;
		case IDOK: MessageBox(hwnd, "Была нажата кнопка OK", "info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0); // Отрабатывает при нажатие кнопки "закрыть" (X).
	}
	return FALSE;
}

