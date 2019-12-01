/*
* Author: Guy Levin
* Date: Dec 2019
*/
#ifndef DRIVER_DUMPER_HEADER
#define DRIVER_DUMPER_HEADER

#include <Windows.h>

#define STATUS_INFO_LENGTH_MISMATCH ((NTSTATUS)0xC0000004L)
#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)

#define MAX_DRIVER_NAME_LENGTH_STR "30"

typedef NTSTATUS(*ZwQuerySystemInformationType)(DWORD SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);

typedef struct _SYSTEM_MODULE_INFORMATION { // Information Class 11
	PVOID Reserved[2];						// + 0x00
	PVOID Base;								// + 0x10
	ULONG Size;								// + 0x18
	ULONG Flags;							// + 0x1C
	USHORT Index;							// + 0x20
	USHORT Unknown;							// + 0x22
	USHORT LoadCount;						// + 0x24
	USHORT ModuleNameOffset;				// + 0x26
	CHAR ImageName[256];					// + 0x28
} SYSTEM_MODULE_INFORMATION, * PSYSTEM_MODULE_INFORMATION;

typedef struct _SYSTEM_ALL_MODULES {
	DWORD dwNumOfModules;
	SYSTEM_MODULE_INFORMATION modules[ANYSIZE_ARRAY];
} SYSTEM_ALL_MODULES, * PSYSTEM_ALL_MODULES;

#endif // !DRIVER_DUMPER_HEADER