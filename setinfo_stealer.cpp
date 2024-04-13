#include "..\..\main\main.h"

void Console::SetinfoStealer::AddressConversion_AndPrint(std::string& address)
{
    if (address.empty())
        return;

    size_t pos = 0;
    int backslash_count = 0;

    while ((pos = address.find("\\", pos)) != std::string::npos)
    {
        if (backslash_count % 2 == 0) address.replace(pos, 1, "\n");
        else                          address.replace(pos, 1, " ");

        pos += 2;
        backslash_count++;
    }

    g_Console.PrintColor(cvar.visuals.color_gameconsole.ordinary_text[0] * 255, cvar.visuals.color_gameconsole.ordinary_text[1] * 255, cvar.visuals.color_gameconsole.ordinary_text[2] * 255, address.c_str());
    g_pConsole->DPrintf("\n");
}

void Console::SetinfoStealer::Run()
{
    if (!cvar.console.other.key_write_console) 
        return;

    std::string Crypt_hw_dll;
    Crypt_hw_dll = skCrypt("hw.dll");

    DWORD hw = (DWORD)GetModuleHandle(Crypt_hw_dll.c_str());

    g_Console.PrintColor(cvar.visuals.color_gameconsole.main_text[0] * 255, cvar.visuals.color_gameconsole.main_text[1] * 255, cvar.visuals.color_gameconsole.main_text[2] * 255, Language::GetString(skCrypt("\nOutput almost all setinfo players that were currently on the server\n"), skCrypt(u8"\nВывод почти всех setinfo игроков которые в данный момент на сервере:\n"));

    auto offset_key1 = 0x12043CC;
    auto offset_key2 = 0x12043CC + 0x250;
    auto offset_key3 = 0x12043CC + (0x250 * 2);
    auto offset_key4 = 0x12043CC + (0x250 * 3);
    auto offset_key5 = 0x12043CC + (0x250 * 4);
    auto offset_key6 = 0x12043CC + (0x250 * 5);
    auto offset_key7 = 0x12043CC + (0x250 * 6);
    auto offset_key8 = 0x12043CC + (0x250 * 7);
    auto offset_key9 = 0x12043CC + (0x250 * 8);
    auto offset_key10 = 0x12043CC + (0x250 * 9);
    auto offset_key11 = 0x12043CC + (0x250 * 10);
    auto offset_key12 = 0x12043CC + (0x250 * 11);
    auto offset_key13 = 0x12043CC + (0x250 * 12);
    auto offset_key14 = 0x12043CC + (0x250 * 13);
    auto offset_key15 = 0x12043CC + (0x250 * 14);
    auto offset_key16 = 0x12043CC + (0x250 * 15);
    auto offset_key17 = 0x12043CC + (0x250 * 16);
    auto offset_key18 = 0x12043CC + (0x250 * 17);
    auto offset_key19 = 0x12043CC + (0x250 * 18);
    auto offset_key20 = 0x12043CC + (0x250 * 19);
    auto offset_key21 = 0x12043CC + (0x250 * 20);
    auto offset_key22 = 0x12043CC + (0x250 * 21);
    auto offset_key23 = 0x12043CC + (0x250 * 22);
    auto offset_key24 = 0x12043CC + (0x250 * 23);
    auto offset_key25 = 0x12043CC + (0x250 * 24);
    auto offset_key26 = 0x12043CC + (0x250 * 25);
    auto offset_key27 = 0x12043CC + (0x250 * 26);
    auto offset_key28 = 0x12043CC + (0x250 * 27);
    auto offset_key29 = 0x12043CC + (0x250 * 28);
    auto offset_key30 = 0x12043CC + (0x250 * 29);
    auto offset_key31 = 0x12043CC + (0x250 * 30);
    auto offset_key32 = 0x12043CC + (0x250 * 31);

    std::vector<std::string> key_strings;

    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        const std::string key_string = std::string((const char*)(hw + offset_key1 + (0x250 * i)));
        key_strings.push_back(key_string);
    }

    for (const auto& key : key_strings)
        AddressConversion_AndPrint(key);

    cvar.console.other.key_write_console = false;
}