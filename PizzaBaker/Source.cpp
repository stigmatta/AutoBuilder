#include <iostream>
#include <string>

using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Достоинства паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

   /*
		* Pizza (продукт) представляет сложный конструируемый объект.
		* ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
		* */
class Automobile
{
	string body;
	int engine;
	int wheels;
	string gearbox;
	string name;
public:
	void SetBody(string body) {
		this->body = body;
	}

	string GetBody()const {
		return body;
	}

	void SetName(string name) {
		this->name = name;
	}

	string GetName()const {
		return name;
	}

	void SetEngine(int engine) {
		this->engine = engine;
	}

	int GetEngine()const {
		return engine;
	}

	void SetWheels(int wheels) {
		this->wheels = wheels;
	}

	int GetWheels()const {
		return wheels;
	}

	void SetGearbox(string gearbox) {
		this->gearbox = gearbox;
	}

	string GetGearbox()const{
		return gearbox;
	}

	void ShowAutomobile()
	{
		cout <<"Car Model:"<<name<<"\t"<< "Body: "<<body<<"\t"<<"Engine(l/s): "<<engine<<"\t"<<"Wheels(R): "<<wheels<<"\t"<<"Gearbox: "<<gearbox<<"\n\n";
	}
};

class Builder abstract
{
protected:
	Automobile automobile;
public:
	Automobile GetAutomobile()
	{
		return automobile;
	}
	virtual void BuildBody() abstract;
	virtual void BuildName() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildGearbox() abstract;
};

// ConcreteBuilder выполняет следующие действия:
// - конструирует и собирает вместе части продукта посредством реализации интерфейса Builder;
// - определяет создаваемое представление и следит за ним;
// - предоставляет интерфейс для доступа к продукту

class DaewooLanosBuilder: public Builder
{
public:

	void BuildName() override {
		automobile.SetName("Daewoo Lanos");
	}
	void BuildBody() override
	{
		automobile.SetBody("sedan");
	}

	void BuildEngine() override
	{
		automobile.SetEngine(98);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(13);
	}

	void BuildGearbox() override
	{
		automobile.SetGearbox("5 Manual");
	}
};

class FordProbeBuilder : public Builder
{
public:

	void BuildName() override {
		automobile.SetName("Ford Probe");
	}

	void BuildBody() override
	{
		automobile.SetBody("coupe");
	}

	void BuildEngine() override
	{
		automobile.SetEngine(160);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(14);
	}

	void BuildGearbox() override
	{
		automobile.SetGearbox("4 Auto");
	}
};

class UAZPatriotBuilder : public Builder
{
public:

	void BuildName() override {
		automobile.SetName("UAZ Patriot");
	}

	void BuildBody() override
	{
		automobile.SetBody("universal");
	}

	void BuildEngine() override
	{
		automobile.SetEngine(120);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(16);
	}

	void BuildGearbox() override
	{
		automobile.SetGearbox("4 Manual");
	}
};

class HyundaiGetzBuilder : public Builder
{
public:

	void BuildName() override {
		automobile.SetName("Hyundai Getz");
	}

	void BuildBody() override
	{
		automobile.SetBody("hatchback");
	}

	void BuildEngine() override
	{
		automobile.SetEngine(66);
	}

	void BuildWheels() override
	{
		automobile.SetWheels(13);
	}

	void BuildGearbox() override
	{
		automobile.SetGearbox("4 Auto");
	}
};

class Shop
{
	Builder* autoBuilder;
public:

	void SetAutomobileBuilder(Builder* ab) {
		autoBuilder = ab;
	}
	Automobile GetAuto()const
	{
		return autoBuilder->GetAutomobile();
	}
	void ConstructAutomobile()
	{
		autoBuilder->BuildName();
		autoBuilder->BuildBody();
		autoBuilder->BuildEngine();
		autoBuilder->BuildWheels();
		autoBuilder->BuildGearbox();
	}
};

void client(Builder* builder)
{
	Shop shop;
	shop.SetAutomobileBuilder(builder);
	shop.ConstructAutomobile();
	shop.GetAuto().ShowAutomobile();
}

void main()
{
	Builder* builder = new FordProbeBuilder();
	client(builder);
	delete builder;
	builder = new HyundaiGetzBuilder();
	client(builder);
	delete builder;
	system("pause");
}