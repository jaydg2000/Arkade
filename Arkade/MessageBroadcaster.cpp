#include "MessageBroadcaster.h"
#include "MessageRouter.h"
#include "MessagePool.h"

namespace arkade {

	MessageBroadcaster::MessageBroadcaster()
	{
	}


	MessageBroadcaster::~MessageBroadcaster()
	{
	}

	Message* MessageBroadcaster::obtain_message() {
		return MessagePool::instance()->obtain();
	}

	void MessageBroadcaster::send_message(Message* message) {
		MessageRouter* router = MessageRouter::instance();
		router->broadcast(message);
	}
}