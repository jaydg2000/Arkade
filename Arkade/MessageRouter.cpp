#include "MessageRouter.h"

namespace arkade {

	MessageRouter::MessageRouter()
	{
	}


	MessageRouter::~MessageRouter()
	{
	}

	MessageRouter* MessageRouter::instance() {
		if (!m_ptr_instance) {
			m_ptr_instance = new MessageRouter();
		}

		return m_ptr_instance;
	}

	void MessageRouter::register_sink(uint32_t message_type, MessageSink* ptr_sink) {
		list<MessageSink*>& sink_list = get_or_add_message_type_list(message_type);
		sink_list.push_back(ptr_sink);
	}

	bool MessageRouter::contains_message_type(uint32_t message_type) {
		return m_sink_map.count(message_type) > 0;
	}

	list<MessageSink*>& MessageRouter::get_or_add_message_type_list(uint32_t message_type) {
		if (!contains_message_type(message_type)) {
			list<MessageSink*> new_list;
			auto new_pair = make_pair<uint32_t, list<MessageSink*>>(message_type, new_list);
			m_sink_map.insert(new_pair);
		return m_sink_map.at(message_type);
		}
	}
}