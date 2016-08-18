#include "Message.h"
#include <string.h>


void Message::setMessage(char * message)
{
	int length = strlen(message);
	if (this->message != 0) delete[] this->message;
	this->message = new char[length + 1];
	strcpy(this->message, message);
}


char * Message::getMessage() const
{
	return this->message;
}

unsigned char * Message::getUMessage() const
{
	return (unsigned char*) this->message;
}

Message::Message(char * message) :message(0), length(0)
{
	setMessage(message);
	this->length = strlen(message);
}

Message::Message(unsigned char * message) :message(0), length(0)
{
	setMessage((char*)message);
	this->length = strlen((char*)message);
}

int Message::getLength() const {
	return this->length;
}

Message::~Message()
{
	if (this->message != 0)
	{
		delete[] this->message;
	}
	message = 0;
}

Message Message::operator=(Message message)
{
	this->setMessage(message.getMessage());
	this->length = message.getLength();
	return *this;
}

Message::Message(const Message& message) :message(0), length(0)
{
	this->setMessage(message.getMessage());
	this->length = message.getLength();
}

