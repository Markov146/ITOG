#include <iostream>
#include <fstream>
#include<string>
#include<cctype>

using namespace std;

void Register();
void Login();
void Exit();
static bool isLoggedIn = false;
int main(){
    setlocale(LC_ALL, "rus");

    char choice = 0;
    cout << "Регестрация: 1\n"
        << "Войти: 2\n"
        << "Выйти: 3\n"
        << "<<";
    while (cin >> choice)
    {
        int ch = atoi(&choice);
        switch (ch) {
        case 1:
            Register();
            break;
        case 2:
            Login();
            break;
        case 3: {
            Exit();
            break;
        default:
            cout << "Вы ввели не верное значение .Повторите снова.\n";
        }
          
        }
        cout << "<<";
    }
    return 0;
}

void Register() {
    string username, password;
    cout << "Введите имя :";
    cin >> username;
    cout << "Введите пароль для регестрации :";
    cin >> password;
    hash<char> hash_string;
    ofstream file;
    file.open("c:\\" + username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Регистрация прошла успешно.\n" << hash_string(password)<<endi;
}
void Login() {
    string username, password, un, pw;

    if (isLoggedIn) {
        cout << "Вы уже авторизованы.\n";
    }
    else{
        cout << "Введите имя для входа:";
        cin >> username;

        cout << "Введите пароль:";
        cin >> password;
        hash<char> hash_string;
        ifstream read("c:\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password) {
            cout << "Вы ввошли в систему.\n";
            isLoggedIn = true;

        }
        else {
            cout << "Вы ввели неправильный логин или пароль.\n";
        }
    }
}
void Exit() {
    if (isLoggedIn)
    {
        cout << "ВЫ вышли из системыю\n";
        isLoggedIn = false;
    }
    else {
        cout << "Вы не авторизованы\n";
    }
}
