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
		m_message_queue.push(message);
	}

	void MessageSink::flush() {
		while (!m_message_queue.empty()) {
			Message* ptr_message = m_message_queue.front();
			on_message(ptr_message->message_type(), ptr_message->sender(), ptr_message->data());
			ptr_message->release();
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