#pragma once

namespace arkade {

	class Behavior {
	public:
		Behavior();
		~Behavior();

		virtual void		on_setup();
		virtual void		on_update() = 0;
		virtual void		on_cleanup();

	};

}