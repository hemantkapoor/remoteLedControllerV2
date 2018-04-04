/*
 * Ledmanager.h
 *
 *  Created on: 12 Feb 2018
 *      Author: hemant
 */

#ifndef LEDMANAGER_H_
#define LEDMANAGER_H_

#include "gpio.h"
#include "MessageBase.h"

#include <vector>
#include <set>

class Led;

class Ledmanager : public MessageBase
{
public:
	//No constructor for singleton

	//Same goes for copy constructor
	Ledmanager(const Ledmanager&) = delete;
	//and assignment operator
	Ledmanager& operator=(const Ledmanager&) = delete;

	bool addLed(GPIO::PinNumbersEnum, const std::string&);

	static Ledmanager* instance();
	virtual ~Ledmanager();

	virtual void handleCommand(std::vector<std::string>&);

private:
	//Private functions
	Ledmanager();
	static Ledmanager* m_ledManager;
	std::map<std::string,Led*> m_ledRecords;
	std::set<GPIO::PinNumbersEnum> m_ledPinNumberRecords;

	//Commands to handle
	const std::string SetLedCommand = "SLC";
	const std::string GetLedCommand = "GLC";

};

#endif /* LEDMANAGER_H_ */
