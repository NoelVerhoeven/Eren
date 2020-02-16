#include "Eren.h"
#include "Eren/Core/EntryPoint.h"

class Sandbox : public Eren::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Eren::Application* Eren::createApplication() {
	return new Sandbox();
}