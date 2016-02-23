#include "Message.h"

namespace arkade {

	Message::Message(uint32_t message_type)
	{
		m_message_type = message_type;
		m_ptr_sender = weak_ptr<MessageSink>();
		m_ptr_data = weak_ptr<void>();
	}


	Message::Message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender)
	{
		m_message_type = message_type;
		m_ptr_sender = ptr_sender;
		m_ptr_data = weak_ptr<void>();
	}

	Message::Message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender, weak_ptr<void> ptr_data)
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

	weak_ptr<MessageSink> Message::sender() {
		return m_ptr_sender;
	}

	weak_ptr<void> Message::data() {
		return m_ptr_data;
	}
}