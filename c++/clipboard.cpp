#include <iostream>
#include <windows.h>


int SetClipboardText(const char *text) {

    if(OpenClipboard(nullptr) != 0) {

        HGLOBAL clipbuffer;
        char *buffer;

        EmptyClipboard();
        
        clipbuffer = GlobalAlloc(GMEM_DDESHARE, strlen(text) + 1);
        buffer = (char*) GlobalLock(clipbuffer);
        
        strcpy(buffer, LPCSTR(text));
        
        GlobalUnlock(clipbuffer);
        SetClipboardData(CF_TEXT, clipbuffer);
        
        CloseClipboard();

        return 0;

    } else {
        return -1;
    }

}

std::string GetClipboardText(void) {
    if(!OpenClipboard(nullptr))
        return "-error";

    HANDLE hData = GetClipboardData(CF_TEXT);

    if(hData == nullptr) {
        return "-error";
    }

    char *pszText = static_cast<char*>(GlobalLock(hData));
    if(pszText == nullptr)
        return "-error";

    std::string text(pszText);
    GlobalUnlock(hData);
    
    CloseClipboard();

    return text;
}

int main(void) {

    std::string old_clip = GetClipboardText();
    std::cout << "Clipboard: " << GetClipboardText() << std::endl;

    /* Se o clipboard atual for 'teste' enttão será substituido por 'teste1234' */
    if(strcmp(old_clip.c_str(), "teste") == 0) {
        SetClipboardText("teste1234");
        std::cout << "New Clipboard: " << GetClipboardText() << std::endl;
    }

    return 0;
}
