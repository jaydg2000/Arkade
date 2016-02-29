#include "MessagePool.h"

namespace arkade {

	MessagePool* MessagePool::m_instance = nullptr;

	MessagePool::MessagePool(uint32_t initial_size)
	{
		while (initial_size-- > 0)
			m_messages.push(new Message());
	}


	MessagePool::~MessagePool()
	{
	}

	MessagePool* MessagePool::instance() {
		if (!m_instance)
			m_instance = new MessagePool(MESSAGE_POOL_INITIAL_SIZE);
		return m_instance;
	}

	Message* MessagePool::obtain() {
		if (m_messages.empty())
			return new Message();

		Message* message = m_messages.front();
		m_messages.pop();

		return message;
	}

	void MessagePool::release(Message* message) {
		message->set(0, nullptr, nullptr);
		m_messages.push(message);
	}
}