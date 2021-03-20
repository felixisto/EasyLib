
#include "../Looper.h"
#include "../ScopeLock.h"
#include "../../Basic/System.h"
#include "../../Tool/Logging/Logging.h"

using namespace easy;

bool LooperLoopWait(Looper* looper) {
	const float minWaitDelay = Looper::MIN_WAIT_DELAY_MS / 1000.0;

	float timeToWait = looper->getSecondsDelay();

	while (timeToWait > 0) {
		if (!looper->isActive()) {
			return false;
		}

		timeToWait -= minWaitDelay;

		easy::system::sleep(minWaitDelay);
	}

	looper->getClient()->onLoop();

	return looper->isActive();
}

void LooperLoop(Looper* looper) {
	while (LooperLoopWait(looper)) {

	}
}

Looper::Looper(CString name, float secondsDelay, LooperClient* client) : name(name), client(client), secondsDelay(secondsDelay), thread(LooperLoop) {

}

Looper::~Looper() {
	if (active.getAndSet(false)) {
		Logging::standard().printWarning("Looper' %s' is being destroyed, before the thread is stopped!", name.c());

		thread.wait();
	}
}

bool Looper::isActive() {
	return active.get();
}

float Looper::getSecondsDelay() {
	return secondsDelay;
}

LooperClient* Looper::getClient() {
	return client;
}

void Looper::start() {
	if (active.getAndSet(true)) {
		return;
	}

	thread.start(this);
}

void Looper::stop() {
	active.set(false);
}