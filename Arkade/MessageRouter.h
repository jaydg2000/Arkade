#pragma once
#include <SDL.h>
#include <list>
#include <map>
#include "MessageSink.h"

using namespace std;

namespace arkade {

	class MessageRouter {
	public:
		~MessageRouter();

		static MessageRouter*						instance();
		void										register_sink(uint32_t message_type, MessageSink* ptr_sink);
		void										broadcast(Message* ptr_message);

	private:
		static MessageRouter*						m_ptr_instance;
		map<uint32_t, list<MessageSink*>>			m_sink_map;

		MessageRouter();

		bool										contains_message_type(uint32_t message_type);
		list<MessageSink*>*							get_message_type_list(uint32_t message_type);
		list<MessageSink*>*							get_or_add_message_type_list(uint32_t message_type);

	};

}