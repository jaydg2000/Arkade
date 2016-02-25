#include "Message.h"

namespace arkade {

	Message::Message(uint32_t message_type)
	{
		m_message_type = message_type;
		m_ptr_sender = nullptr;
		m_ptr_data = nullptr;
	}


	Message::Message(uint32_t message_type, MessageSink* ptr_sender)
	{
		m_message_type = message_type;
		m_ptr_sender = ptr_sender;
		m_ptr_data = nullptr;
	}

	Message::Message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data)
	{
		m_message_type = message_type;
		m_ptr_sender = ptr_sender;
		m_ptr_data = ptr_data;
	}


	Message::~Message()
	{
	}

	uint32_t Message::message_type() {
		return m_message_type;
	}

	MessageSink* Message::sender() {
		return m_ptr_sender;
	}

	void* Message::data() {
		return m_ptr_data;
	}
}