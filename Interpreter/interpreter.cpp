#include "interpreter.h"
void main()
{
	PlayContext * context = new PlayContext();
	cout << "ÉÏº£Ì²: " << endl;
	context->SetText("O 2 E 0.5 G 0.5 A 3 E 0.5");
	Expression * expression = NULL;
	try
	{
		while (context->PlayText().length() > 0)
		{
			string str = context->PlayText().substr(0, 1);
			const char * s = str.c_str();
			switch (int(s[0]))
			{
			case 79 :
				expression = new Scale();
				break;
			case 67 :
			case 68 :
			case 69 :
			case 70 :
			case 71 :
			case 65 :
			case 66 :
			case 80 :
				expression = new Note();
				break;
			}
			expression->Interpret(context);
		}
	}
	catch (exception ex)
	{
		cout << "????" << endl;
	}
}