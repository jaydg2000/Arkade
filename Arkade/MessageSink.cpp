#include "MessageSink.h"
#include "MessageRouter.h"

namespace arkade {

	MessageSink::MessageSink()
	{
	}


	MessageSink::~MessageSink()
	{
	}

	void MessageSink::post(Message* message) {
		QueuedMessage msg;
		msg.message_type = message->message_type();
		msg.ptr_sender = message->sender();
		msg.ptr_data = message->data();
		m_message_queue.push(msg);
	}

	void MessageSink::flush() {
		while (!m_message_queue.empty()) {
			QueuedMessage message = m_message_queue.front();
			on_message(message.message_type, message.ptr_sender, message.ptr_data);
			m_message_queue.pop();
		}
	}

	void MessageSink::register_for_messages(uint32_t message_type) {
		MessageRouter* router = MessageRouter::instance();
		router->register_sink(message_type, this);
	}

	void MessageSink::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {

	}
}