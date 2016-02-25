#pragma once
#include <SDL.h>
#include <memory>

using namespace std;

namespace arkade {
	class MessageSink;
	class Message {
	public:
		Message(uint32_t message_type);
		Message(uint32_t message_type, MessageSink* ptr_sender);
		Message(uint32_t message_type, MessageSink* ptr_sender, void* data);
		~Message();

		uint32_t								message_type();
		MessageSink*							sender();
		void*									data();

	private:
		uint32_t								m_message_type;
		MessageSink*							m_ptr_sender;
		void*									m_ptr_data;

	};

}