#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevious, LPSTR lpComString, int nShowCmd)
{
	// Test message box
	MessageBox(NULL, "Hello, Vexal!", "Vexal Online", MB_OK);

	// All okay!
	return 0;
}