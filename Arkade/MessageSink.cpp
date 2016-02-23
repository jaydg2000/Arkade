#include "MessageSink.h"

namespace arkade {

	MessageSink::MessageSink()
	{
	}


	MessageSink::~MessageSink()
	{
	}

	void MessageSink::accept_message(Message_ptr message) {
		m_message_queue.push(message);
	}

	void MessageSink::send_message(Message_ptr message) {

	}

	void MessageSink::on_message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender, weak_ptr<void> ptr_data) {

	}
}