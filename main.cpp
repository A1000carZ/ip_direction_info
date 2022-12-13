#include "./ip_direction/ip_direction.h"
using namespace std;

int main()
{
    string input;

    cout << "Bienvenido!" << endl
         << endl;
    /* code */
    cout << "Ingrese una dirección ip valida: ";
    cin >> input;

    for(int i = 0; i<input.size(); i++){
        if(input[i] >= 'a' && input[i] <= 'z') {
            cout << "Hubo un error al procesar los datos";
            return 0;
        }
    }

    IPDirection ip(input);

    ip.getInfo();

    return 0;
}