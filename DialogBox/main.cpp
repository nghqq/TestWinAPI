#include<Windows.h>
#include"resource.h"



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
		case IDOK: MessageBox(hwnd, "Была нажата кнопка OK", "info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0); // Отрабатывает при нажатие кнопки "закрыть" (X).
	}
	return FALSE;
}

