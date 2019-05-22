#pragma once

class carClass
{
public:

	enum result {success, error};

	enum status {on, off};

	enum direction {front, back, holding};

	carClass();
	~carClass();

	result testGear(int speed, int gear);

	status GetEngineStatus() const;

	direction GetDirection();

	int GetSpeed() const;

	int GetGear() const;

	result SetSpeed(int speed);

	result SetGear(int gear);

	result turnOnEngine();

	result turnOffEngine();

private:

	status m_status = off;

	direction m_direction = holding;

	int m_speed = 0;

	int m_gear = 0;
};