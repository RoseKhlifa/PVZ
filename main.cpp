#include"memory.h"
int main()
{
	HWND m_hwnd = FindWindowA("MainWindow","ֲ���ս��ʬ���İ�"); //ȡ���ھ��
	DWORD m_processid;//��ʼ��PID
	GetWindowThreadProcessId(m_hwnd,&m_processid);//���ھ��δ֪
	HANDLE m_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_processid); //����PIDδ֪
	DWORD m_moudle = GetModuleBase(m_processid, (char*)"PlantsVsZombies.exe");
	DWORD m_sunaddress = m_moudle + 0x02A9EC0;
	DWORD buffer0 = 0;
	ReadProcessMemory(m_handle,(LPVOID)m_sunaddress,&buffer0,4,NULL); //���̾��δ֪
	
	DWORD buffer1 = 0;
	DWORD buffer2 = 0;
	ReadProcessMemory(m_handle, (LPVOID)(buffer0+0x768), &buffer1, 4, NULL); //���̾��δ֪
	ReadProcessMemory(m_handle, (LPVOID)(buffer1 + 0x5560), &buffer2, 4, NULL); //���̾��δ֪
	DWORD buffer3 = 0;
	cout << "����������������";
	cin >> buffer3;
	while (true)
	{

		WriteProcessMemory(m_handle, (LPVOID)(buffer1 + 0x5560), &buffer3, 4, NULL);

	}
	


	
	getchar();
	return 0;
}