#Retcheck

/*
What is the Return Check (Retcheck) ?
It is a check where ROBLOX puts in place of most Lua C Functions such as getfield, setfield etc.
The check is triggered when you call a function (that contains the Return Check function) and you will get
shutdown if the return check address is out of a range that is normally set by ROBLOX.

There are many ways to bypass the return check without having to bypass other checks, consolecheck, memory check, callcheck.
Other methods will work such as Eternal's Retcheck Bypass and Variable's JB method.

However, I'm writing a method that bypasses the Return check by using Louka's Method, still using retcheck flags.

*/

#Bypass

DWORD RF1, RF2;
DWORD Retcheck = aslr(0xC0FFEE); //Return Check Address
DWORD RetcheckFlag1 = aslr(0xDEADBEEF); //Return Check Flag 1
DWORD RetcheckFlag2 = aslr(0xDEADBEEF); //Return Check Flag 2

DWORD WriteMemory(DWORD Address, DWORD Instruction) {
	
	DWORD dwOldProtection;
	VirtualProtect((LPVOID)Address, 1, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	*(char*)Address = Instruction;
	VirtualProtect((LPVOID)Address, 1, dwOldProtection, &dwOldProtection);
}

void Retcheck_Disable() {
	RF1 = *(DWORD*)RetcheckFlag1;
	RF2 = *(DWORD*)RetcheckFlag2;
	WriteMemory(Retcheck, 0xC3);
}

void Retcheck_Enable() {
	*(DWORD*)RetcheckFlag1 = RF1;
	*(DWORD*)RetcheckFlag2 = RF2;
	WriteMemory(Retcheck, 0x55);
}

//Remember this just requires you to find the Retcheck Address and the Flags.
