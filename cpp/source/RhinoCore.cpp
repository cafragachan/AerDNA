
#pragma once
#include <include/RhinoCore.h>


#include <include/RhinoInclude.h>
#include <delayimp.h>



static FARPROC WINAPI DliRhinoLibrary(unsigned dliNotify, PDelayLoadInfo pdli)
{
	static const wchar_t* RhinoLibraryPath = L"C:\\Program Files\\Rhino 7 WIP\\System\\RhinoLibrary.dll";

	if (dliNotify == dliNotePreLoadLibrary && _stricmp(pdli->szDll, "RhinoLibrary.dll") == 0)
		return (FARPROC)LoadLibraryEx(RhinoLibraryPath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

	return 0;
}

const PfnDliHook __pfnDliNotifyHook2 = DliRhinoLibrary;

extern "C" HRESULT StartupInProcess(int argc, wchar_t** argv, const STARTUPINFO* pStartUpInfo, HWND hHostWnd);
extern "C" HRESULT ShutdownInProcess();

RhinoCore::RhinoCore()
{
	StartupInProcess(0, nullptr, nullptr, HWND_DESKTOP);
}


RhinoCore::~RhinoCore()
{
	ShutdownInProcess();
}
