#pragma once
#include <SDL.h>
#include "__arkade_spr_registry.h"
#include "Graphics.h"
#include "CollisionDetector.h"
#include "BoundingBoxCollisionDetector.h"

namespace arkade {

	class Scene {
	public:
		Scene();
		Scene(CollisionDetector* collision_detector);
		~Scene();

		void							run();
		void							stop();
		void							enable_auto_collision_detection(bool enabled);

	protected:
		virtual void					on_setup();
		virtual void					on_begin();
		virtual void					on_loop();
		virtual void					on_end();
		virtual void					on_cleanup();
		virtual void					on_detect_collisions(CollisionDetector* detector);

		void							check_keyboard_input();
		void							check_mouse_input();		
		void							setup_sprites();
		void							cleanup_sprites();
		void							update_sprites();
		void							render_sprites();
		void							handle_messages();
		void							auto_detect_collisions(CollisionDetector* detector);

	private:
		bool							m_scene_is_ended;
		bool							m_auto_collision_detection_enabled;
		CollisionDetector*				m_collision_detector;
	};

}