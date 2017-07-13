#Lua State

//Ever since ROBLOX Removed their GlobalState Function, it's possible to find the algorithm of the Lua State.
//Look up Unable to create a new thread for %s, press F5 to generate pseudocode. The algorithm should be located under v50 = 1.

//We see this function.

/*

        v49 = sub_5A8F20(v48, 5);
        v50 = 0;
        if ( v49 )
          v50 = 1;
        v51 = *(_DWORD *)(v41 + 56 * v50 + 164) - (v41 + 56 * v50 + 164);
        v52 = lua_newthread(v51);
		
		
*/


//We can make our own OpenState Function to return the value of the Lua State.

DWORD rL;

DWORD GlobalState(DWORD ScriptContext) {
	int v50;
	int v51;
	int v52;

	v50 = 0;

	v51 = *(DWORD *)(ScriptContext + 56 * v50 + 164) - (ScriptContext + 56 * v50 + 164);
	v52 = lua_newthread(v51);
	return v52;
}

rL = GlobalState(ScriptContext);

//We use lua_newthread to create a new thread for the new state.
