#pragma once
#include <SDL.h>
#include <memory>

using namespace std;

namespace arkade {
	class MessageSink;
	class Message {
	public:
		Message();
		Message(uint32_t message_type);
		Message(uint32_t message_type, MessageSink* ptr_sender);
		Message(uint32_t message_type, MessageSink* ptr_sender, void* data);
		~Message();

		void									set(uint32_t type, MessageSink* sender = nullptr, void* data = nullptr);
		uint32_t								message_type();
		MessageSink*							sender();
		void*									data();
		//void									release();

	private:
		uint32_t								m_message_type;
		MessageSink*							m_ptr_sender;
		void*									m_ptr_data;

	};

}