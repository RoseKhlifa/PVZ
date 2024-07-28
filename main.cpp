#include"memory.h"
int main()
{
	HWND m_hwnd = FindWindowA("MainWindow","植物大战僵尸中文版"); //取窗口句柄
	DWORD m_processid;//初始化PID
	GetWindowThreadProcessId(m_hwnd,&m_processid);//窗口句柄未知
	HANDLE m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_processid); //进程PID未知
	DWORD m_moudle = GetModuleBase(m_processid, (char*)"PlantsVsZombies.exe");
	DWORD m_sunaddress = m_moudle + 0x02A9EC0;
	DWORD buffer0 = 0;
	ReadProcessMemory(m_handle,(LPVOID)m_sunaddress,&buffer0,4,NULL); //进程句柄未知
	
	DWORD buffer1 = 0;
	DWORD buffer2 = 0;
	ReadProcessMemory(m_handle, (LPVOID)(buffer0+0x768), &buffer1, 4, NULL); //进程句柄未知
	ReadProcessMemory(m_handle, (LPVOID)(buffer1 + 0x5560), &buffer2, 4, NULL); //进程句柄未知
	DWORD buffer3 = 0;
	cout << "请输入阳光数量：";
	cin >> buffer3;
	while (true)
	{

		WriteProcessMemory(m_handle, (LPVOID)(buffer1 + 0x5560), &buffer3, 4, NULL);

	}
	


	
	getchar();
	return 0;
}