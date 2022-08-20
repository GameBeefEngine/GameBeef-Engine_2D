
#include <lua.hpp>
#include <lualib.h>

#include <iostream>

#pragma once
class ScriptLoader
{
public:
	bool loadLua(const char* path);
private:
	int iErr = 0;
};

