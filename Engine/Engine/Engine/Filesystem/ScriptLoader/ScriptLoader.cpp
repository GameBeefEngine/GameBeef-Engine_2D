#include "ScriptLoader.h"

bool ScriptLoader::loadLua(const char* path)
{

	lua_State *lua = lua_open();
	luaopen_io(lua);

	if ((iErr = luaL_loadfile(lua, path)) == 0)
	{
		// Call main...
		if ((iErr = lua_pcall(lua, 0, LUA_MULTRET, 0)) == 0)
		{
			// Push the function name onto the stack
			lua_pushstring(lua, "scriptStart");
			// Function is located in the Global Table
			lua_gettable(lua, LUA_GLOBALSINDEX);
			lua_pcall(lua, 0, 0, 0);
		}
	}

	lua_close(lua);
	return true;
}
