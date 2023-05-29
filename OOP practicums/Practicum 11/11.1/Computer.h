#pragma once

class Computer
{
	double _cpuPower = 0;
	char* _gpuModel = nullptr;
	int _suplyPower = 0;
	int _ram = 0;

	virtual void setCpuPower(double cpuPower);
	virtual void setGpuModel(const char* gpuModel);
	virtual void setSuplyPower(int suplyPower);
	virtual void setRam(int ram);

	void free();
	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other);

protected:
	char** devices{};
	int _deviceCount = 0;

public:
	virtual void printType() const = 0;
	virtual void printDevices() const = 0;
	virtual double getCpuPower() const;
	virtual const char* getGpuModel() const;
	virtual int getSuplyPower() const;
	virtual int getRam() const;

	Computer() = delete;
	Computer(double cpuPower, const char* gpuModel, int suplyPower, int ram);

	Computer(const Computer& other);
	Computer& operator=(const Computer& other);

	Computer(Computer&& other) noexcept;
	Computer& operator=(Computer&& other) noexcept;

	virtual ~Computer();
};