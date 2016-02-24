#pragma once
#include "Message.h"

namespace arkade {

	class MessageBroadcaster
	{
	public:
		MessageBroadcaster();
		~MessageBroadcaster();

		void							send_message(Message* message);
	};

}