#pragma once
#include <SDL.h>
#include <memory>
#include "MessageSink.h"

using namespace std;

namespace arkade {

	class Message {
	public:
		Message(uint32_t message_type);
		Message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender);
		Message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender, weak_ptr<void> data);
		~Message();

		uint32_t								message_type();
		weak_ptr<MessageSink>					sender();
		weak_ptr<void>							data();

	private:
		uint32_t								m_message_type;
		weak_ptr<MessageSink>					m_ptr_sender;
		weak_ptr<void>							m_ptr_data;

	};

}