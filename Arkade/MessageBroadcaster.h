#pragma once
#include "Message.h"

namespace arkade {

	class MessageBroadcaster
	{
	public:
		MessageBroadcaster();
		~MessageBroadcaster();

		Message*						obtain_message();
		void							send_message(Message* message);
	};

}