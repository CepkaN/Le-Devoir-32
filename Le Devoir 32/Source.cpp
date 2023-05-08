#include<iostream>
#include<string>

struct arr {
	int* pointer = nullptr;
	int length = 0;
};
struct route {
	int march = 0;
	std::string voiture = "vide";
	std::string nachmar = "vide";
	std::string conmar = "vide";
};
route tram{ 8,"tram","ulisa 40 let VLKSM","Mashinostroiteley"
};
route aut{166,"autobus","Avtostanzio Vostocnaya","Berezovskiy"};
route trol{6,"filobus","Himmash","Academiceskiy"};
void init(arr& bloc) {
	if (bloc.pointer != nullptr)
		exit;
	bloc.pointer = new int[bloc.length] {};
}
void show(arr& bloc) {
	std::cout << "[ ";
	for (int i = 0; i < bloc.length; i++)
		std::cout << bloc.pointer[i] << ", ";
	std::cout << "\b\b ]";
}
void app(arr& bloc, int cifr) {
	if (cifr <= 0)
		return;
	int* terr = new int[bloc.length + cifr]{};
	for (int i = 0; i < bloc.length; i++)
		terr[i] = bloc.pointer[i];
	delete[] bloc.pointer;
	bloc.pointer=terr;
	bloc.length = bloc.length + cifr;
}
void el(arr& bloc, int indice) {
	std::cout << bloc.pointer[indice];
}
void clear(arr& bloc) {
	delete[] bloc.pointer;
	bloc.pointer = nullptr;
	bloc.length = 0;
}
void permuter(std::string& str, char A, char B) {
	if (str.find(A) == 0)
		exit;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == A)
			str[i] = B;
	std::cout << str;
}
void info(route& r){
	std::cout << "Маршрут номер : " << r.march << "\n";
	std::cout << "Вид транспорта : " << r.voiture << '\n';
	std::cout << "Начальная остановка : " << r.nachmar << '\n';
	std::cout << "Конечная остановка : " << r.conmar << '\n';
}
int stoim(route& r, int cel) {
	int sto;
	if (r.march == 166)
		sto = cel * 46;
	else
		sto = cel * 33;
	return sto;
}
int main() {
	setlocale(LC_ALL, "Russian");
	// Задача 1.
	std::cout << "Задача 1.\nВведите длину массива:";
	arr mass;
	std::cin >> mass.length;
	init(mass);
	std::cout << "Массив :";
	show(mass);
	std::cout << "\nВведите количество дополнительных элементов :";
	int nom;
	std::cin >> nom;
	app(mass, nom);
	std::cout << "Новый массив :";
	show(mass);
	std::cout << "\nВведите индекс элемента массива :";
	int indice;
	std::cin >> indice;
	std::cout << "Ваш элемент массива с индексом " << indice<<" : ";
	el(mass, indice);
	clear(mass);

	// Задача 2.
	std::cout << "\nЗадача 2.\nВведите строку : ";
	std::string stroka;
	std::cin.ignore();
	getline(std::cin, stroka);
	std::cout << "Введите символ : ";
	char ch1;
	std::cin >> ch1;
	std::cout << "Введите второй символ : ";
	char ch2;
	std::cin >> ch2;
	permuter(stroka, ch1, ch2);
	
	// Задача 3.
	std::cout << "\nЗадача 3.\nВведите номер маршрута : ";
	route tran;
	int tr;
	std::cin >> tr;
	switch (tr) {
	case 6:info(trol); tran = trol; break;
	case 166:info(aut); tran = aut; break;
	case 8:info(tram); tran = tram; break;
	default:std::cout<<"В базе нет данного маршрута.\n";
	};
	std::cout << "Введите количество человек : ";
	int cel, sto;
	std::cin >> cel;
	sto = stoim(tran, cel);
	std::cout << "Стоимость проезда для " << cel << " человек " << " равна " << sto;


	return 0;
}