#pragma once

#include "Eren/Core/Core.h"
//#include "Eren/Core/Timestep.h"
#include "Eren/Events/Event.h"

namespace Eren {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return mDebugName; }
	protected:
		std::string mDebugName;
	};

}