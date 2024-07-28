#pragma once
#include <iostream>
#include<string>
#include<windows.h>
#include<TlHelp32.h>


using namespace std;

ULONG64 GetModuleBase(DWORD dwProcID, char* szModuleName) {
	ULONG64 ModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcID);
	if (hSnapshot != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32)) {
			do {
				if (strcmp(ModuleEntry32.szModule, szModuleName) == 0) {
					ModuleBaseAddress = (uintptr_t)ModuleEntry32.modBaseAddr;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));;
		}
		CloseHandle(hSnapshot);
	}
	return ModuleBaseAddress;
}