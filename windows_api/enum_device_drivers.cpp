#pragma comment(lib, "psapi")

/* 
 * Lib psapi required to linker
 * Compile with: -DPSAPI_VERSION=1
 * */

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>

#define ARRAY_SIZE 1024

int main(void) {

    LPVOID drivers[ARRAY_SIZE];
    DWORD cbNeeded;
    int cDrivers, i;
    
    if(EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded) && cbNeeded < sizeof(drivers)) {
        TCHAR szDriver[ARRAY_SIZE];

        cDrivers = cbNeeded / sizeof(drivers[0]);

        _tprintf(TEXT("There are %d drivers:\n"), cDrivers);
        for(i = 0; i < cDrivers; i++) {
            if(GetDeviceDriverBaseName(drivers[i], szDriver, sizeof(szDriver) / sizeof(szDriver[0]))) {
                _tprintf(TEXT("%d: %s\n"), i+1, szDriver);
            }
        }
    } else {
        _tprintf(TEXT("EnumDeviceDrivers failed; array size needed is %ld\n"), cbNeeded / sizeof(LPVOID));
        return 1;
    }

    return 0;
}
