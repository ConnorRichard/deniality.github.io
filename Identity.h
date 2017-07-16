#Identity

/*

What is the identity? The identity is a certain "level", if you have a level that falls under 7,
you will have restricted access to Roblox's APIs and Functions.

If you have a identity of 7 and above, you will have unrestricted access to ROBLOX's API and functions.

So how do we change the identity level? There are many ways to do so, I'm going to show you how to 
change the identity level.


*/

void Identity(int Identity) {
	auto Context = (int*(__cdecl*)
		())SigScan("\x55\x8B\xEC\x51\x56\xE8\x00\x00\x00\x00\x50", "xxxxxx????x"); //Identity AOB
	*(int*)Context() = Identity; //Sets Context Identity to our new identity
}

//You would just call Identity(7) to change the default identity of 0 to 7.
