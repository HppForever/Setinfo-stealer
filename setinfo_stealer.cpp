#include "..\..\main\main.h"

void Console::SetinfoStealer::AddressConversion_AndPrint(std::string& Address)
{
    if (Address.empty())
        return;

    size_t Pos = NULL;
    int BackslashCount = NULL;

    while ((Pos = Address.find("\\", Pos)) != std::string::npos)
    {
        if (BackslashCount % 2 == NULL) Address.replace(Pos, 1, "\n");
        else                            Address.replace(Pos, 1, " ");

        Pos += 2;
        BackslashCount++;
    }

    Console::ColorPrint::FinalPrint(Console::ColorPrint::TypeText::Ordinary, std::string(Address + "\n").c_str());
}

void Console::SetinfoStealer::Run()
{
    if (!cvar.console.other.setinfo_write_console) 
        return;

    Console::ColorPrint::FinalPrint(Console::ColorPrint::TypeText::Main, Language::GetString(skCrypt("\nOutput almost all setinfo players that were currently on the server\n"), skCrypt(u8"\nВывод почти всех setinfo игроков которые в данный момент на сервере:\n")));

    std::vector<std::string> KeyStrings;

    for (int i = NULL; i < MAX_CLIENTS; i++)
        KeyStrings.push_back(std::string((const char*)((DWORD)GetModuleHandle(std::string(skCrypt("hw.dll")).c_str()) + 0x12043CC + (0x250 * i))));

    for (auto& Key : KeyStrings)
        AddressConversion_AndPrint(Key);

    cvar.console.other.setinfo_write_console = false;
}
