
#include <Windows.h>
#include <iostream>
#include "Easy/Samples/Samples.h"
#include "Easy/Basic/Math.h"
#include "Easy/Concurrency/ThreadManager.h"

int main() {
    easy::math::Random::standard();
    easy::ThreadManager::standard();
    auto options = easy::Logging::standard().getWriteToFileOptions();
    options.enabled = true;
    easy::Logging::standard().setWriteToFileOptions(options);

    bool result = easy::samples::AllSamples().performAll();

    printf("Tests result: %s", (result ? "success" : "failure"));
}
