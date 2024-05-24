#include <GarrysMod/Lua/Interface.h>

#include "cusercmd.h"

#define CHECK_CMD \
CUserCmd* pCmd =  LUA->GetUserType<CUserCmd>(1, GarrysMod::Lua::Type::UserCmd); \
if (!pCmd) \
{ \
	LUA->ArgError(1, "CUserCmd expected"); \
	return 0; \
}

LUA_FUNCTION(GetWorldClicker)
{
	LUA->CheckType(1, GarrysMod::Lua::Type::UserCmd);

	CHECK_CMD

	LUA->PushBool(pCmd->wc_state);
	return 1;
}

LUA_FUNCTION(SetWorldClicker)
{
	LUA->CheckType(1, GarrysMod::Lua::Type::UserCmd);
	LUA->CheckType(2, GarrysMod::Lua::Type::Bool);

	CHECK_CMD

	pCmd->wc_state = LUA->GetBool(2);
	return 0;
}

LUA_FUNCTION(GetWorldClickerAngle)
{
	LUA->CheckType(1, GarrysMod::Lua::Type::UserCmd);

	CHECK_CMD

	LUA->PushVector(pCmd->wc_angles);
	return 1;
}

LUA_FUNCTION(SetWorldClickerAngle)
{
	LUA->CheckType(1, GarrysMod::Lua::Type::UserCmd);
	LUA->CheckType(2, GarrysMod::Lua::Type::Vector);

	CHECK_CMD

	pCmd->wc_angles = LUA->GetVector(2);
	return 0;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_REG);
	{
		LUA->PushString("CUserCmd");
		LUA->RawGet(-2);

		if (LUA->IsType(-1, GarrysMod::Lua::Type::Table))
		{
			LUA->PushString("GetWorldClicker");
			LUA->PushCFunction(GetWorldClicker);
			LUA->RawSet(-3);

			LUA->PushString("SetWorldClicker");
			LUA->PushCFunction(SetWorldClicker);
			LUA->RawSet(-3);

			LUA->PushString("GetWorldClickerAngle");
			LUA->PushCFunction(GetWorldClickerAngle);
			LUA->RawSet(-3);

			LUA->PushString("SetWorldClickerAngle");
			LUA->PushCFunction(SetWorldClickerAngle);
			LUA->RawSet(-3);
		}

		LUA->Pop();
	}
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	// Nope

	return 0;
}