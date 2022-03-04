#include "QueueP.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	PRIORITY temp_p;
	int working_queue = 0;
	QueueP* temp = new QueueP();
	QueueP* queue1 = new QueueP();
	QueueP* queue2 = new QueueP();
	while (true) {
		int value;
		int priority;
		int action = 0;
		cout << "Доступные действия :\n" <<
			"1. Выбрать очередь для работы.\n" <<
			"2. Обменять значения очередей.\n" <<
			"3. Выйти из консольного приложения.\n";
		cin >> action;
		switch (action)
		{
		case 1:
			system("cls");
			cout << "Доступные очереди :\n"
				<< "1. Очередь №1\n"
				<< "2. Очередь №2\n";
			cin >> working_queue;
			switch (working_queue)
			{
			case 1:
				system("cls");
				temp = queue1;
				break;
			case 2:
				system("cls");
				temp = queue2;
				break;
			default:
				cout << "Неверный номер.\n";
				system("pause");
				system("cls");
				break;
			}
			if (working_queue < 1 || working_queue > 2) {
				break;
			}
			else {
				cout << "Доступные операции с очередью :\n"
					<< "1. Проверка очереди на пустоту.\n"
					<< "2. Получить информацию о голове очереди.\n"
					<< "3. Удаление последнего элемента(pop).\n"
					<< "4. Вставка элемента.\n"
					<< "5. Получение общего количества элементов.\n"
					<< "6. Получени информации о конкретном приоритете.\n";
				cin >> action;
				switch (action)
				{
				case 1:
					temp->write_on_stream(cout);
					system("pause");
					system("cls");
					break;
				case 2:
					try {
						cout << temp->get_front_element() << " ";
						cout << temp->get_front_priority() << endl;
					}
					catch (exception e) {
						cout << e.what();
					}
					system("pause");
					system("cls");
					break;
				case 3:
					temp->pop();
					cout << "Операция выполнена.\n";
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					cout << "Введите значение элемента для вставки.\n";
					cin >> value;
					cout << "Выберите приоритет данного элемента\n1. LOW\n2. MEDIUM\n3. HIGH\n";
					cin >> priority;
					if (priority == 1) temp_p = PRIORITY::LOW;
					else if (priority == 2) temp_p = PRIORITY::MEDIUM;
					else if (priority == 3) temp_p = PRIORITY::HIGH;
					else {
						cout << "Неверный приоритет\n";
						system("pause");
						system("cls");
						break;
					}
					temp->insert(value, temp_p);
					cout << "Элемент вставлен.\n";
					system("pause");
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "Общее количество элементов = " << temp->get_length() << endl;
					system("pause");
					system("cls");
					break;
				case 6:
					system("cls");
					cout << "Выберите приоритет по которому хотите получить информацию\n1. LOW\n2. MEDIUM\n3. HIGH\n";
					cin >> priority;
					if (priority == 1) temp_p = PRIORITY::LOW;
					else if (priority == 2) temp_p = PRIORITY::MEDIUM;
					else if (priority == 3) temp_p = PRIORITY::HIGH;
					else {
						cout << "Неверный приоритет\n";
						system("pause");
						system("cls");
						break;
					}
					cout << "Количество элементов по данному приоритету = " << temp->get_priority_length(temp_p);
					system("pause");
					system("cls");
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			temp = new QueueP(move(*queue1));
			*queue1 = move(*queue2);
			*queue2 = move(*temp);
			cout << "Успешно выполнено.\n";
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Работа завершена.";
			return 0;
			break;
		default:
			break;
		}
	}
	/**/
}