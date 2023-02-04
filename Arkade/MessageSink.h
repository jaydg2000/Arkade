#pragma once
#include <SDL.h>
#include <memory>
#include <queue>
#include "Message.h"

using namespace std;

namespace arkade {

	class MessageSink {
	public:
		MessageSink();
		~MessageSink();

		void				register_for_messages(uint32_t message_type);
		void				post(Message* ptr_message);
		void				flush();

	protected:
		virtual void		on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

	private:
		queue<QueuedMessage>	m_message_queue;
	};

}