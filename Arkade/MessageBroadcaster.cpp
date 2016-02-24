#include "MessageBroadcaster.h"
#include "MessageRouter.h"

namespace arkade {

	MessageBroadcaster::MessageBroadcaster()
	{
	}


	MessageBroadcaster::~MessageBroadcaster()
	{
	}

	void MessageBroadcaster::send_message(Message* message) {
		MessageRouter* router = MessageRouter::instance();
		router->broadcast(message);
	}
}