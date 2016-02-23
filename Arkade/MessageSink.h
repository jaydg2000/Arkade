#pragma once
#include <SDL.h>
#include <memory>
#include <queue>
#include "Message.h"

using namespace std;

namespace arkade {

	typedef unique_ptr<Message> Message_ptr;

	class MessageSink {
	public:
		MessageSink();
		~MessageSink();

		void				accept_message(Message_ptr ptr_message);
		void				send_message(Message_ptr ptr_message);

	protected:
		virtual void		on_message(uint32_t message_type, weak_ptr<MessageSink> ptr_sender, weak_ptr<void> ptr_data);

	private:
		queue<Message_ptr>	m_message_queue;
	};

}