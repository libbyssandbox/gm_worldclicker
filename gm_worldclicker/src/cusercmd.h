#pragma once

#include <GarrysMod/Lua/SourceCompat.h>

class CUserCmd
{
public:
	uint32_t	command_number;
	uint32_t	tick_count;
	Vector		viewangles;
	float		forwardmove;
	float		sidemove;
	float		upmove;
	uint32_t	buttons;
	uint8_t		impulse;
	uint32_t	weaponselect;
	uint32_t	weaponsubtype;
	uint32_t	random_seed;
	uint16_t	mousedx;
	uint16_t	mousedy;
	bool		hasbeenpredicted;

	uint8_t		keys[5];
	int8_t		scroll_wheel;
	bool		wc_state;
	Vector		wc_angles;
	bool		is_typing;
	Vector		motion_sensor_positions[20];
	bool		forced;
};
