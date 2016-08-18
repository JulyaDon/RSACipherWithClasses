#pragma once
class Message
{
private:
	int length;
	char* message; //указатель на строку с сообщением
	Message(); //конструктор по умолчанию. Запрещаем его использовать путем помещения в секцию private.
	void setMessage(char* message); //метод записи сообщения
public:
	char* getMessage() const; //метод получения сообщения
	unsigned char* getUMessage() const;
	int getLength() const;
	Message(char* message); //конструктор. Принимает строку сообщения.
	Message(unsigned char* message);
	Message(const Message &); //конструктор копирования
	~Message();
	Message operator=(Message message);
};


