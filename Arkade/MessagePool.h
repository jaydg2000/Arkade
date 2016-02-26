#pragma once
#include <queue>
#include "Message.h"

#define MESSAGE_POOL_INITIAL_SIZE 10

namespace arkade {

	class MessagePool
	{
	public:
		~MessagePool();

		static MessagePool*						instance();
		Message*								obtain();
		void									release(Message*);

	private:
		static MessagePool*						m_instance;
		queue<Message*>							m_messages;

		MessagePool(uint32_t initial_size);
	};

}