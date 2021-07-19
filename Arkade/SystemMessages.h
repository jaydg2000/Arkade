#pragma once

/*
*	Custom messages should use Ids 1000 and up. Below 1000 are reserved for system use.
	Message Id Groups

	400-499 Form/Form Control
*/

#define MESSAGE_FORMCONTROL_MOUSEDOWN		400
#define MESSAGE_FORMCONTROL_MOUSEHOVER		402


struct MouseDownArgs
{

	uint32_t		x;
	uint32_t		y;
};