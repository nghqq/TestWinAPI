//WinAPI
#include <Windows.h>


// ������� ������� 

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	// ��� ���� ������ � WinAPI ������ �������  � ������� ��������.
	// hInstance  - ��� ��������� ������������  *.exe - �����.
	// lpCmdLine - ��������� ������, � ������� ��� ������� *.exe - ����.
	//										� ��� ��������� ������ ����� ���������� ���������.
	// nCmdShow  - ����� ����������� ����:
	//�������� �� ������ �����;
	//���������� �� ���� �����;
	//�������� � ����;

	MessageBox(NULL, "Hello World!\n ���-�� ��� ��������", "��� ���� ��������� ", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP);
	// const char* - ��� ANSI/ASCII string 
	// LPCWSTR - LongPointer to Wide String
	// Wide String - ������ � ��������� ������ (wchar_t) ������ ������ � ��������� ������
	return 0;
}

/*typedef  struct  tagHELPINFO
{
	UINT cbSize;		// ������ ��������� � ������
	int iContextType;		// ��� �������
	int iCtrlId;		// ������������� ���� ���� ����
	HANDLE hItemHandle;	// ������������� ���������
	// ���� ���� ���������� ����
	DWORD dwContextId;		// ����������� ������������� ����
	// ���� ���� �������� ���������
	POINT MousePos;		// ������� ����
} HELPINFO, FAR* LPHELPINFO;*/


