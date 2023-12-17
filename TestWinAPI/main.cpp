//WinAPI
#include <Windows.h>


// ГЛАВНАЯ ФУНКЦИЯ 

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	// Все типы данных в WinAPI всегда пишутся  в верхнем регистре.
	// hInstance  - это экземпляр загруженного  *.exe - файла.
	// lpCmdLine - командная строка, с которой был запущен *.exe - файл.
	//										В эту командную строку можно передавать параметры.
	// nCmdShow  - Режим отображения окна:
	//свернуто на панель задач;
	//развернуто на весь экран;
	//свернуто в окно;

	MessageBox(NULL, "Hello World!\n Что-то тут написано", "Это окно сообщения ", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_HELP);
	// const char* - это ANSI/ASCII string 
	// LPCWSTR - LongPointer to Wide String
	// Wide String - строка в кодировке юникод (wchar_t) хранит символ в кодировке юникод
	return 0;
}

/*typedef  struct  tagHELPINFO
{
	UINT cbSize;		// размер структуры в байтах
	int iContextType;		// тип справки
	int iCtrlId;		// идинтификатор окна либо меню
	HANDLE hItemHandle;	// идентификатор дочернего
	// окна либо связанного меню
	DWORD dwContextId;		// контекстный идентификатор либо
	// окна либо элемента упраления
	POINT MousePos;		// Позиция мыши
} HELPINFO, FAR* LPHELPINFO;*/


