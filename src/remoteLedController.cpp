//============================================================================
// Name        : remoteLedController.cpp
// Author      : Hemant Kapoor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include "MessageManager.h"
#include "Ledmanager.h"
#include "Utility.h"


int main() {
	std::cout << "Hello World" << std::endl;

	auto messageManager = MessageManager::instance();
	Ledmanager::instance()->addLed(GPIO::P8_7,"RED_LED");

	while(true)
	{
		std::this_thread::sleep_for (std::chrono::seconds(1));
		//Check if we are done
		if(messageManager->isMessageManagerFinished()) {break;}
	}
	messageManager->doneWithMessageManager();
	return 0;
}
