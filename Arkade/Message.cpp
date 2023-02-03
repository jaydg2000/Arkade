#include "Message.h"
#include "MessagePool.h"

namespace arkade {

	Message::Message() {
		m_message_type = 0;
		m_ptr_sender = nullptr;
		m_ptr_data = nullptr;
	}

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

	void Message::set(uint32_t type, MessageSink* sender, void* data) {
		m_message_type = type;
		m_ptr_sender = sender;
		m_ptr_data = data;
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

	//void Message::release() {
	//	MessagePool* pool = MessagePool::instance();
	//	pool->release(this);
	//}
}