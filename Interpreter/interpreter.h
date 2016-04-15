#pragma once
#include<iostream>
#include<string>
using namespace std;
//��������
class PlayContext
{
private:
	string text;
public:
	void SetText(string text)
	{
		this->text = text;
	}
	string PlayText()
	{
		return text;
	}
};
//���ʽ��
class Expression
{
public:
	void Interpret(PlayContext * context)
	{
		if (context->PlayText().length() == 0)
		{
			return;
		}
		else
		{
			string playKey = context->PlayText().substr(0, 1);
			context->PlayText() = context->PlayText().substr(2);
			string s = context->PlayText().substr(0, context->PlayText().find(" ", 0));
			double playValue = atof(s.c_str());
			context->PlayText() = context->PlayText().substr(context->PlayText().find(" ", 0) + 1);

			Excute(playKey, playValue);
		}
	}
	//ִ��
	virtual void Excute(string key, double value) = 0;
};
//������
class Note : public Expression
{
public:
	void Excute(string key, double value)
	{
		string note = "";
		const char * s = key.c_str();
		switch (int(s[0]))
		{
		case 67:
			note = "1";
			break;
		case 68 :
			note = "2";
			break;
		case 69 :
			note = "3";
			break;
		case 70 :
			note = "4";
			break;
		case 71 :
			note = "5";
			break;
		case 65 :
			note = "6";
			break;
		case 66 :
			note = "7";
			break;
		}
		cout << note << " ";
	}
};
//������
class Scale : public Expression
{
public:
	void Excute(string key, double value)
	{
		string scale = "";
		switch (int(value))
		{
		case 1:
			scale = "����";
			break;
		case 2:
			scale = "����";
			break;
		case 3:
			scale = "����";
			break;
		}
		cout << scale << " ";
	}
};