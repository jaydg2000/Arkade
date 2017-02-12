#include "MessageRouter.h"
#include "MessageSink.h"
#include "Message.h"

namespace arkade {

	MessageRouter* MessageRouter::m_ptr_instance = nullptr;

	MessageRouter::MessageRouter()
	{
	}


	MessageRouter::~MessageRouter()
	{
		m_sink_map.clear();
	}

	MessageRouter* MessageRouter::instance() {
		if (!m_ptr_instance) {
			m_ptr_instance = new MessageRouter();
		}

		return m_ptr_instance;
	}

	void MessageRouter::register_sink(uint32_t message_type, MessageSink* ptr_sink) {
		list<MessageSink*>* sink_list = get_or_add_message_type_list(message_type);
		sink_list->push_back(ptr_sink);
	}

	void MessageRouter::unregister_sink(uint32_t message_type, MessageSink* ptr_sink) {
		list<MessageSink*>* ptr_sinks = get_message_type_list(message_type);
		if (!ptr_sinks)
			return;
		for (MessageSink* sink : *ptr_sinks) {
			if (sink == ptr_sink) {
				ptr_sinks->remove(ptr_sink);
			}
		}
	}

	void MessageRouter::broadcast(Message* ptr_message) {
		list<MessageSink*>* ptr_sinks = get_message_type_list(ptr_message->message_type());
		if (!ptr_sinks)
			return;
		for (MessageSink* sink : *ptr_sinks) {
			sink->post(ptr_message);
		}
	}

	bool MessageRouter::contains_message_type(uint32_t message_type) {
		return m_sink_map.count(message_type) > 0;
	}

	list<MessageSink*>* MessageRouter::get_or_add_message_type_list(uint32_t message_type) {
		if (!contains_message_type(message_type)) {
			list<MessageSink*> new_list;
			auto new_pair = make_pair(message_type, new_list);
			m_sink_map.insert(new_pair);
		}
		return &(m_sink_map[message_type]);
	}

	list<MessageSink*>* MessageRouter::get_message_type_list(uint32_t message_type) {
		if (!contains_message_type(message_type)) {
			return nullptr;
		}
		return &(m_sink_map[message_type]);
	}
}