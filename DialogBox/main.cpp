#include<Windows.h>
#include"resource.h"


CONST CHAR g_sz_LOGIN_INVITE[] = "������� ��� ������������";
CONST CHAR g_sz_PASSWORD_INVITE[] = "������� ������";
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //�������� ��������� ����

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	// HWND - ��� ����  (Handler to Window - ���������� ����).
	// uMsg - ��� ��������� ������� ��������� ����.
	// wParam, lParam - ���  ��������� ���������.
	switch (uMsg) 
	{
	case WM_INITDIALOG: //����� ����� ��������� �������� ����������.
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		
	}
		break;			// ��� ������ ������������ ��� ������� ���� ���� ���.
	case WM_COMMAND:
		// ����� �������������� ������� ������� ������, ��������� ������ � ��.
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
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer); //WM_GETTEXT ����� �����
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer); // WM_GETTEXT ��������� �����
			//SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer); // �������� 
		}
		break;
		case IDOK: MessageBox(hwnd, "���� ������ ������ OK", "info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0); // ������������ ��� ������� ������ "�������" (X).
	}
	return FALSE;
}

