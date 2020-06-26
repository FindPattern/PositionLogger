    #include <windows.h>
    #include <stdio.h>
    #include "log.h"
     
    #define playerPointer 0x??????
    #define X 0x????????
    #define Y 0x????????
    #define Z 0x????????
     
    float fX_1;
    float fY_1;
    float fZ_1;
     
     
    VOID LogPosition(VOID)
    {
    	Writelog("<3");
    	for(;;)
    	{
    		DWORD player = *(DWORD*)playerPointer ;
    		if(GetAsyncKeyState(VK_NUMPAD0)&1)
    		{
    			fX_1 = *(float*)(player+X);
    			fY_1 = *(float*)(player+Y);
    			fZ_1 = *(float*)(player+Z);
     
    			Writelog("X: %f\nY: %f\nZ: %f\n",fX_1,fY_1,fZ_1);
    		}
    	}
    }
     
    BOOL __stdcall DllMain( HMODULE hDll , DWORD Reason )
    {
    if(Reason==DLL_PROCESS_ATTACH)
    {
    	logging(hDll);
    	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)LogPosition, NULL, NULL, NULL); 
    }
    return TRUE;
    }